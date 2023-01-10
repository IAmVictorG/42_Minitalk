/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:39:28 by vgiordan          #+#    #+#             */
/*   Updated: 2023/01/10 16:33:49 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char	*message;
	int		pid;

	message = argv[1];
	pid = atoi(argv[2]);

	kill(pid, message);
	printf("message %s, pid %d", message, pid);
	return 0;
}