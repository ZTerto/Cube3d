#include "../include/cube3d.h"

static void timeval_to_time_interval(struct timeval *tv, t_time_interval *ti) {
    ti->seconds = (uint64_t)tv->tv_sec;
    ti->nanoseconds = (uint64_t)tv->tv_usec * 1000;
}

void update_fps(t_fps *fps) {
    struct timeval now;

    if (!fps)
        return;

    fps->current_count++;

    gettimeofday(&now, NULL);

    long elapsed_ms = (now.tv_sec - fps->former_time.seconds) * 1000L
                    + (now.tv_usec * 1000 - fps->former_time.nanoseconds) / 1000000L;

    // Actualizar si pasó al menos 1 segundo o para evitar overflow en current_count (por ejemplo, >1e8)
    if (elapsed_ms >= 333 || fps->current_count >= 100000000) {
        fps->former_count = fps->current_count;
        timeval_to_time_interval(&now, &fps->former_time);
        fps->current_count = 0;
    }

    timeval_to_time_interval(&now, &fps->current_time);
}

void itoa_fps(char *dst, int n) {
    int i = 0;

    // Prefijo "FPS: "
    dst[i++] = 'F';
    dst[i++] = 'P';
    dst[i++] = 'S';
    dst[i++] = ':';
    dst[i++] = ' ';

    // Caso n == 0
    if (n == 0) {
        dst[i++] = '0';
        dst[i] = '\0';
        return;
    }

    // Extraer dígitos (en orden inverso)
    char digits[10];
    int len = 0;
    while (n > 0 && len < 10) {
        digits[len++] = (char)('0' + (n % 10));
        n /= 10;
    }

    // Escribirlos en orden correcto
    for (int j = len - 1; j >= 0; --j) {
        dst[i++] = digits[j];
    }
    dst[i] = '\0';
}

void print_counter(void *param) {
    t_game *game = (t_game *)param;
    t_fps *fps = (t_fps *)game->fps;
    long elapsed_ms;
    int fps_value;
  

    if (!fps || !game)
        return;

    elapsed_ms = (long)(fps->current_time.seconds - fps->former_time.seconds) * 1000L +
                 (long)(fps->current_time.nanoseconds - fps->former_time.nanoseconds) / 1000000L;
    // printf("diff_seconds: %ld\n", (long)(((t_fps *)game->fps)->current_time.seconds - ((t_fps *)game->fps)->former_time.seconds));
    // printf("diff_nanoseconds: %ld\n", (long)(((t_fps *)game->fps)->current_time.nanoseconds - ((t_fps *)game->fps)->former_time.nanoseconds));
    // printf("diff_seconds_ms: %ld\n", (long)(((t_fps *)game->fps)->current_time.seconds - ((t_fps *)game->fps)->former_time.seconds) * 1000L);
    // printf("diff_nanoseconds_ms: %ld\n", (long)(((t_fps *)game->fps)->current_time.nanoseconds - ((t_fps *)game->fps)->former_time.nanoseconds) / 1000000L);
    update_fps(fps);

    if (elapsed_ms == 0) elapsed_ms = 1; // Evitar división por cero

    fps_value = (int)((fps->former_count * 1000L) / elapsed_ms);

    char *buf = malloc(FPS_MSG_SIZE);
    if (!buf)
        return;

    snprintf(buf, FPS_MSG_SIZE, "FPS: %d", fps_value);
    // printf("diff_seconds: %ld\n", (long)(((t_fps *)game->fps)->current_time.seconds - ((t_fps *)game->fps)->former_time.seconds));
    // printf("diff_nanoseconds: %ld\n", (long)(((t_fps *)game->fps)->current_time.nanoseconds - ((t_fps *)game->fps)->former_time.nanoseconds));
    // printf("diff_seconds_ms: %ld\n", (long)(((t_fps *)game->fps)->current_time.seconds - ((t_fps *)game->fps)->former_time.seconds) * 1000L);
    // printf("diff_nanoseconds_ms: %ld\n", (long)(((t_fps *)game->fps)->current_time.nanoseconds - ((t_fps *)game->fps)->former_time.nanoseconds) / 1000000L);
    //printf("buf: %s\n", buf);

    mlx_put_string(game->mlx, buf, COUNTER_POS_X, COUNTER_POS_Y);
    free(buf);
}
