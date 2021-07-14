/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:40:01 by mazoukni          #+#    #+#             */
/*   Updated: 2021/07/12 19:09:46 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*

 ** This program simply send signals but its a encryption mechanism using signals to send 
 ** letters, bit shiifting by 1 and divide by two and reverse this operation with divide by 2 and add 1

 */



char *ft_char_to_binary(char character)
{
	int i;
	char *binary;

	binary = (char *)malloc(8);
	if (binary == 0)
		print_error(1);
	binary[7] = 0;
	i = 6;
	while (character > 1)
	{
		binary[i] = character % 2 + 48;
		character /= 2;
		i--;
	}
	binary[i] = character % 2 + 48;
	i--;
	while (i >= 0)
	{
		binary[i] = 48;
		i--;
	}
	return (binary);
}

void	ft_send_ack(int pid)
{
	int i;

	i = 0;
	while (i < 7)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(50);
	}
}

void ft_send_character(int pid, char *message)
{
	int i;
	int j;
	char *temp;

	i = 0;
	if (!(temp = (char *)malloc(ft_strlen(message))))
		print_error(1);
	while (message[i])
	{
		j = 0;
		temp = ft_char_to_binary(message[i]);
		while (temp[j])
		{
			if (temp[j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			j++;
		}
		i++; 
	}
	free(temp);
	ft_send_ack(pid);
}

int main(int argc, char **argv)
{
	int pid;
	char *message;

	if (argc == 3)
	{
		if (!(message = (char *)malloc(ft_strlen(argv[2]))))
			print_error(1);
		pid = atoi(argv[1]);
		message = argv[2];
		ft_send_character(pid, message);
	}
	else
		print_error(2);
}
