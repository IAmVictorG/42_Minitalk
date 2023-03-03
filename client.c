/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:39:28 by vgiordan          #+#    #+#             */
/*   Updated: 2023/03/03 16:15:13 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send(unsigned char c, pid_t pid)
{	
	int	t;
	int	tt;

	t = c;
	tt = 1;
	while (c > 0)
	{
		if (c % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c /= 2;
		usleep(WAITING);
	}
	t *= 2;
	while (t < 256)
	{
		kill(pid, SIGUSR1);
		usleep(WAITING);
		t *= 2;
	}
}

static void	send_string(char *str, pid_t pid)
{
	while (*str)
	{
		send(*str, pid);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	char		*message;
	pid_t		pid;
	int			fd;
	char		buf[2001];

	fd = open("etranger.txt", O_RDONLY);
	read(fd, buf, 2000);
	if (argc == 3)
	{
		message = argv[1];
		//buf[2000] = '\0';
		//message = buf;
		pid = ft_atoi(argv[2]);
		send_string(message, pid);
		return (0);
	}
	else
		ft_putstr_fd("Usage : ./client <message> <pid>\n", 1);
}
