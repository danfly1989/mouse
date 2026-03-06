#include <math.h>
#include <stdio.h>
#include <unistd.h>
#define WELCOME "Usage: ./guy <degrees in integer format>\n"
#define PIE 3.1415926535897
typedef struct	s_guy
{
	double	lastRotation;
	double	xPos;
	double	yPos;
	double	xDir;
	double	yDir;
	double	xPlane;
	double	yPlane;
}t_guy;

t_guy	init_guy(t_guy guy)
{
	guy.lastRotation = 0;
	guy.xPos = 1;
	guy.yPos = 1;
	guy.xDir = 0;
	guy.yDir = -1;
	guy.xPlane = 0.66;
	guy.yPlane = 0;
	return (guy);
}

t_guy	rotate_guy(t_guy guy, double a)
{
	double	newXDir;
	double	newYDir;
	double	newXPlane;
	double	newYPlane;

	guy.lastRotation = a;
	a = a * PIE / 180.0;
	newXDir = guy.xDir * cos(a) - guy.yDir * sin(a);
	newYDir = guy.xDir * sin(a) + guy.yDir * cos(a);
	newXPlane = guy.xPlane * cos(a) - guy.yPlane * sin(a);
	newYPlane = guy.xPlane * sin(a) + guy.yPlane * cos(a); 
	guy.xDir = newXDir;
	guy.yDir = newYDir;
	guy.xPlane = newXPlane;
	guy.yPlane = newYPlane;
	return (guy);
}

void	print_guy(t_guy guy)
{
	printf("\nCUBE_GUY is currently:\n");
	printf("\tguy.lastRotation = %f\n", guy.lastRotation);
	printf("\tguy.xPos = %f\n", guy.xPos);
	printf("\tguy.yPos = %f\n", guy.yPos);
	printf("\tguy.xDir = %f\n", guy.xDir);
	printf("\tguy.yDir = %f\n", guy.yDir);
	printf("\tguy.xPlane = %f\n", guy.xPlane);
	printf("\tguy.yPlane = %f\n\n", guy.yPlane);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	num;

	if (nptr[0] == '\0')
		return (0);
	i = 0;
	num = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if ((nptr[i] == 45 || nptr[i] == 43))
	{
		if (nptr[i] == 45)
			neg = neg * (-1);
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
		num = ((num * 10) + (nptr[i++] - 48));
	return (num * neg);
}

int main(int argc, char **argv)
{
	t_guy	guy;
	double	a;
	
	if (argc != 2)
		a = 45;
	else
		a = (double)ft_atoi(argv[1]);
	printf(WELCOME);
	guy = init_guy(guy);
	print_guy(guy);
	guy = rotate_guy(guy, a);
	print_guy(guy);
	return (0);
}
