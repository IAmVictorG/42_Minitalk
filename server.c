/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:41:10 by vgiordan          #+#    #+#             */
/*   Updated: 2023/03/06 16:25:04 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	handler(int num)
{
	static t_nbpow	nbpow;
	int				val;

	if (!((nbpow.nb)))
		(nbpow.nb) = 0;
	if (!((nbpow.power)))
		(nbpow.power) = 0;
	if (num == SIGUSR1)
		nbpow.power += 1;
	if (num == SIGUSR2)
	{
		val = 1 << (nbpow.power);
		nbpow.nb += val;
		nbpow.power += 1;
	}
	if (nbpow.power == 8)
	{
		write (1, &(nbpow.nb), 1);
		nbpow.nb = 0;
		nbpow.power = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	char				*pid;

	sa.sa_handler = handler;
	sa.sa_flags = 1;
	pid = ft_itoa(getpid());
	ft_putstr_fd("PID : ", 1);
	ft_putstr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	free(pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
	return (0);
}
