/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:41:10 by vgiordan          #+#    #+#             */
/*   Updated: 2023/01/10 16:20:51 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void handler(int num)
{
	if (num == SIGUSR1)
	{
		write(1, "0\n", 2);
	}
	else if (num == SIGUSR2)
		write(1, "1\n", 2);
	else
		write(1, "ERROR\n", 6);
}

int main(int argc, char const *argv[])
{
	pid_t mypid;
	struct sigaction sa1;
	struct sigaction sa2;

	sa1.sa_handler = handler;
	sa2.sa_handler = handler;

	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	printf("%d\n", getpid());
	while (1)
	{
		sleep(1);
	}
	return 0;
}


