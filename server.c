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

static void handler(int num)
{
	static	int nb;
	static	int power;
	int val;

	if (!nb)
		nb = 0;
	if (!power)
		power = 0;

	if (num == SIGUSR1)
	{
	
		power += 1;
	}
	else if (num == SIGUSR2)
	{
		val = 1 << (power);
		nb += val;
		power += 1;
	}
	else
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
		
	if (power == 7)
	{
		write (1, &nb, 1);
		nb = 0;
		power = 0;
	}
}

int main(int argc, char const *argv[])
{
	pid_t mypid;
	struct sigaction sa;

	sa.sa_handler = handler;
	printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
	return 0;
}


