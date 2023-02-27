/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:39:28 by vgiordan          #+#    #+#             */
/*   Updated: 2023/01/12 13:13:39 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void	send(unsigned char c, pid_t pid)
{
	while(c > 0)
	{
		
		if (c % 2 == 0)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		c /= 2;
		usleep(100);
	}
	printf("-------------------\n");
}
int main(int argc, char *argv[])
{
	char	*message;
	pid_t		pid;

	if (argc == 3)
	{
		message = argv[1];
		pid = atoi(argv[2]);
		while (*message)
		{
			send(*message, pid);
			message++;
		}
		return 0;
	}
}