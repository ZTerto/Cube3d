xhost +local:docker  # Permite acceso al servidor X

docker build -t cub3d .

docker run -it \
    --rm \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v "$PWD":/home/devuser/app \
    cub3d

