/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:09:19 by mazoukni          #+#    #+#             */
/*   Updated: 2021/07/07 13:04:40 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    print_error(int error)
{
    if (error == 0)
        exit(0);
    else if (error == 1)
        ft_putstr_fd("🚨🚨🚨🚨Error🚨🚨🚨🚨: \n\t___FATAL_ERROR_MALLOC__ ", 1);
    else if (error == 2)
        ft_putstr_fd("\t==👾👾👾Usage👾👾👾==\n\t\t./clinet [pid] [message]\n", 1);
    else
        ft_putstr_fd("\t======😊Relax Nothing is Wrong😊======" ,1);
}