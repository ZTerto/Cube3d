/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:40:20 by ajodar-c          #+#    #+#             */
/*   Updated: 2025/01/21 10:08:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read function of file
static char	*get_read(int fd, char *memory)
{
	ssize_t		bytesread;
	char		*nbuffer;

	bytesread = 1;
	nbuffer = get_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (nbuffer == NULL)
		return (free(memory), NULL);
	while (bytesread > 0 && !get_strchr(memory, '\n'))
	{
		bytesread = read(fd, nbuffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(nbuffer), free(memory), NULL);
		nbuffer[bytesread] = '\0';
		if (bytesread == 0)
			return (free(nbuffer), memory);
		memory = get_join(memory, nbuffer);
	}
	return (free(nbuffer), memory);
}

//create a line with memory read
static char	*get_line(char *memory)
{
	char	*line;
	int		i;

	i = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i++;
	line = get_substr(memory, 0, i);
	return (line);
}

//save rest of line on the memory
static char	*get_save(char *memory, int *malloc_flag)
{
	int		i;
	char	*savemem;

	i = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i++;
	if (memory[i] == '\0')
		return (free(memory), NULL);
	savemem = get_substr(memory, i, get_strlen(memory) - i);
	if (savemem == NULL)
		*malloc_flag = 1;
	return (free(memory), savemem);
}

//version 4.1 (dinamic buffer and line stop at \n)
//Get ft_read with read in a while
//Take a line with ft_line
//Save the rest in memory with ft_save
char	*get_next_line(int fd)
{
	int			malloc_flag;
	char		*line;
	static char	*memory;

	malloc_flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(memory), memory = NULL, NULL);
	memory = get_read(fd, memory);
	if (memory == NULL)
		return (NULL);
	line = get_line(memory);
	if (line == NULL)
		return (free(memory), memory = NULL, NULL);
	memory = get_save(memory, &malloc_flag);
	if (malloc_flag == 1)
		return (free(line), NULL);
	return (line);
}
