/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 08:28:07 by mazoukni          #+#    #+#             */
/*   Updated: 2021/07/14 08:40:10 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*convert_char_to_binary(char character)
{
	int		index;
	char	*binary;
	
	binary = malloc(sizeof(9));
	if (binary == 0)
		error_occured(0);
	binary[8] = 0;
	index = 7;
	while (character > 1)
	{
		binary[index] = (character % 2) + 48;
		character /=2;
		index--;
	}
	binary[index] = (character % 2) + 48;
	index--;
	while (index >= 0)
	{
		binary[index] = 48;
		index--;
	}
	return (binary);
}

void	send_terminate_signal(int pid)
{
	int		index;
	
	index = 0;
	while (index < 8)
	{
		kill(pid, SIGUSR1);
		index++;
		usleep(50);
	}
}

char	*