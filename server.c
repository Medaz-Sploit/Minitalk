/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:40:10 by mazoukni          #+#    #+#             */
/*   Updated: 2021/07/13 04:26:10 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_join_string(char character, char *message)
{
	char	*new_string;
	char	*joined_string;

	if (!(new_string = malloc(2)))
		print_error(2);
	new_string[0] = character;
	new_string[1] = 0;
	if (message == 0)
	{
		if (!(message = malloc(2)))
			print_error(2);
		ft_strlcpy(message, new_string, 2);
	}
	else
	{
		joined_string = message;
		if (!(message = ft_strjoin(message, new_string)))
			print_error(0);
		free(joined_string);
	}
	free(new_string);
	return (message);
}


void	ft_counter(int SIGNAL)
{
	static char *message;
	static int counter;
	static int character;
	
	counter++;
	if (SIGNAL == SIGUSR2)
	{
		character = character << 1;
		character += 1;
	}
	else
		character = character << 1;
	if (counter == 7)
	{
		message = ft_join_string(character, message);
		if (character == 0)
		{
			ft_putstr_fd(message, 1);
			write(1, "\n", 1);
			free(message);
			message = 0;
		}
		counter = 0;
		character = 0;
	}
}

int main(int argc, char **argv)
{
	int pid;
	char	*PROCESS_ID;
	
	argv[1] = NULL;
	if (argc == 1)
	{
		pid = getpid();
		if (!(PROCESS_ID = ft_itoa(pid)))
			print_error(0);
		ft_putstr_fd("🤖🤖🤖🤖🤖🤖 PROCESS ID 🤖🤖🤖🤖🤖 : ", 1);
		ft_putstr_fd(PROCESS_ID, 1);
		write(1, "\n", 1);
		signal(SIGUSR1, ft_counter);
		signal(SIGUSR2, ft_counter);
		while (1)
			pause();
	}
	else
		ft_putstr_fd("🚨🚨🚨🚨 Warning 🚨🚨🚨🚨: \n \t\t ==> Usage : ./server", 1);
	return (0);
}