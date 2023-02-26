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
void	send(unsigned char* msg, pid_t pid)
{
	char	c;
	c = *msg;
	while(c > 0)
	{
		printf("c %d\n", c);
		if (c % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c /= 2;
		sleep(1);
	}
}
int main(int argc, char *argv[])
{
	char	*message;
	pid_t		pid;

	message = argv[1];
	pid = atoi(argv[2]);
	
	printf("message %s, pid %d\n", message, pid);
	send(message, pid);
	return 0;
}