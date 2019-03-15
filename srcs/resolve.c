/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 08:39:06 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 10:06:47 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "computorV1.h"

static void	polynome_2nd_complexe(t_nome *polynome)
{
	ft_putendl("Discriminant is strictly negative, the two solutions are :");
	ft_putendl("Not yet...");
	polynome = NULL;
}

static void	polynome_2nd(t_nome *polynome)
{
	double	s1;
	double	s2;
	double	delta;
	
	delta = polynome->next->coef * polynome->next->coef - 4 * polynome->coef *\
			polynome->next->next->coef;
	if (delta > 0)
	{
		ft_putendl("Discriminant is strictly positive, the two solutions are :");
		s1 = (-polynome->next->coef - sqrt(delta)) / (2 * polynome->coef);
		s2 = (-polynome->next->coef + sqrt(delta)) / (2 * polynome->coef);
		ft_putnbr((int)s1);
		ft_putchar('\n');
		ft_putnbr((int)s2);
	}
	else if (delta < 0)
		polynome_2nd_complexe(polynome);
	else
	{
		ft_putendl("Discriminant is null, the solution is :");
		ft_putnbr((int)(-polynome->next->coef / (2 * polynome->coef)));
	}
}

void		resolve(t_parse *parse, t_nome *polynome)
{
	double	s1;

	if (parse->poly_degree == 0 && polynome->coef == 0)
		ft_putendl("This polynome is always true");
	else if (parse->poly_degree == 0)
		ft_putendl("This polynome is always false");
	else if (parse->poly_degree == 1)
	{
		s1 = -polynome->next->coef / polynome->coef;
		ft_putstr("The solution is : ");
		ft_putnbr((int)s1);
	}
	else
		polynome_2nd(polynome);
}
