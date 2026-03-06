/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_guy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:28:20 by akjoerse          #+#    #+#             */
/*   Updated: 2026/03/06 10:44:49 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_guy	*init_guy(double xPos, double yPos)
{
	t_guy	*guy;

	guy = malloc(sizeof(t_guy));
	if (!guy || guy == NULL)
		return (NULL);
	guy->xPos = xPos;
	guy->yPos = yPos;
	guy->xDir = 0.0;
	guy->yDir = -1.0;
	guy->xPlane = 0.0;
	guy->yPlane = 0.66;
	return (guy);
}
