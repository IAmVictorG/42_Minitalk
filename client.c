/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:39:28 by vgiordan          #+#    #+#             */
/*   Updated: 2023/03/06 16:18:39 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send(unsigned char c, pid_t pid)
{	
	int	t;

	t = c;
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

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		send_string(message, pid);
		return (0);
	}
	else
		ft_putstr_fd("Usage : ./client <pid> <message>\n", 1);
}
