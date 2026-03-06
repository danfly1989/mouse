/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:19:05 by akjoerse          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:56 by codex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	keychain(int key, void *param)
{
	if (key == 65307 || !param)
		close_handler(param);
	return (0);
}

int	close_handler(void *param)
{
	t_cub	*cub;

	cub = param;
	debug("in `close_handler` trying to call cub_exit");
	cub_exit(param);
	return (0);
}
