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

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void handler(int num)
{
	write(STDOUT_FILENO, "GREGREGEGR\n", 12);
}

int main(int argc, char const *argv[])
{
	pid_t mypid;
	signal(SIGINT, handler);
	while (1)
	{
		printf("%d\n", getpid());
		sleep(1);
	}
	

	return 0;
}


