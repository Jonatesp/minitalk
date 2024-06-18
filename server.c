/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:59:44 by anbourge          #+#    #+#             */
/*   Updated: 2021/10/07 19:05:10 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static t_msg	g_msg;

void	ft_handler(int msg)
{
	g_msg.c += ((msg & 1) << g_msg.size);
	g_msg.size++;
	if (g_msg.size == 15)
	{
		ft_putchar_fd(g_msg.c, 1);
		if (!g_msg.c)
			ft_putchar_fd('\n', 1);
		g_msg.size = 0;
		g_msg.c = 0;
	}
}

int	main(void)
{
	g_msg.size = 0;
	g_msg.c = 0;
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		signal(SIGUSR2, ft_handler);
		signal(SIGUSR1, ft_handler);
		pause();
	}
}
