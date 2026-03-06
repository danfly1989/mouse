/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:39:23 by akjoerse          #+#    #+#             */
/*   Updated: 2026/02/25 13:42:47 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
void	foo(int bar)
{
	(void)bar;
}
void	error(char *msg)
{
	ft_printf(RED"error:");
	if (msg)
		ft_printf("%s\n"DEF, msg);
	else
		ft_printf("unspecified error\n"DEF);
}

void	debug_i(char *msg, int i)
{
	if (i == 0)
		ft_printf(GRN"debug:");
	if (msg)
		ft_printf(GRN"%s"BLU"%d\n"DEF, msg, i);
	else
		ft_printf("unspecified debug statement.\n"DEF);
}	

void	debug(char *msg)
{
	ft_printf(GRN"debug:");
	if (msg)
		ft_printf("%s\n"DEF, msg);
	else
		ft_printf("unspecified debug statement.\n"DEF);
}
