/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guy.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:47:46 by akjoerse          #+#    #+#             */
/*   Updated: 2026/03/05 17:37:36 by akjoerse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUY_H
# define GUY_H

typedef struct	s_guy
{
	char	guy_facing_dir;
	double	xPos;
	double	yPos;
	double	xDir;
	double	yDir;
	double	xPlane;
	double	yPlane;
	int	guy_color_hex;
}t_guy;
#endif
//&$`~*@^%|header file for PROJECT NAME project at 42berlin by akjoerse|%^@*~`$&//

/* welcome to the secret portion of the project

a space of rambles or chaos.

//\\////\\
//\\/// \\
//\\// /\\
//\\//  \\
//\\/ //\\
//\\/ / \\
//\\/  /\\
//\\/   \\
//\\ ///\\
//\\ // \\
//\\ / /\\
//\\ /  \\
//\\  //\\
//\\  / \\
//\\   /\\
//\\    \\
//\\||||\\
//\\////\\it is not arbitrary
{code:
{"forward slash","/"},
{"straight bar","|"},
{"back slash","\"},
{"space bar", " "}
int n;16^n
power/value	-- of 16: {"1"} = {"16^power_of_one"}
1	16		//\\////\\{\\}{00}{00}{00}{00}{\\}
2	256		//\\    \\{\\}{01}{01}{01}{01}{\\}
3	4,096		//\\||||\\{\\}{010}{010}{010}{010}{\\}
4	65,536	//\\    \\{\\}{011}{011}{011}{011}{\\}
5	1,048,576	//\\\\\\\\{\\}{0100}{0100}{0100}{0100}{\\}
6	16,777,216	//\\    \\{\\}{0101}{0101}{0101}{0101}{\\}		

*/