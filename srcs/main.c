/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 02:05:53 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 07:57:41 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "computorV1.h"

/*
**	Regle pour pas casser le parser :
**
**	-	'+' et '-' separe par des espaces
**	-	Exposant colle au X et au nombre : "X^N"
**
*/

void	find_X(t_parse *parse, char **tab, int i)
{
	char	*x;

	x = tab[i] - 1;
	while ((x = ft_strchr(x + 1, 'X')))
		(parse->exp)++;
	x = tab[i] - 1;
	while ((x = ft_strchr(x + 1, '^')))
		if (*(x - 1) == 'X')
			parse->exp += ft_atoi(x + 1) - 1;
}

void	find_coef(t_parse *parse, char **tab, int i)
{
	if (i >= 1 && tab[i - 1][0] == '-')
		parse->coef *= -1;
	if (ft_isdigit(tab[i][0]) || ft_isdigit(tab[i][1]))
	{
		parse->iscoef = 1;
		if (i >= 1 && tab[i - 1][0] == '/')
			parse->coef /= ft_atoi(tab[i] + (ft_isdigit(tab[i][0]) ? 0 : 1));
		else
			parse->coef *= ft_atoi(tab[i] + (ft_isdigit(tab[i][0]) ? 0 : 1));
	}
}

void	reset_values(t_parse *parse)
{
	parse->iscoef = 0;
	parse->coef = parse->side;
	parse->exp = 0;
}

int		parsing(char *av, t_parse *parse)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(av, ' ');
	reset_values(parse);
	i = -1;
	while (tab[++i])
	{
		find_X(parse, tab, i);
		find_coef(parse, tab, i);
		if (tab[i][0] == '+' || tab[i][0] == '-' || tab[i][0] == '=' || !tab[i + 1])
		{
			if (tab[i][0] == '=')
				parse->side = -1;
			ft_newnome(&(parse->first), parse->coef, parse->exp);
			reset_values(parse);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_parse	parse;

	if (ac == 2)
	{
		parse.first = NULL;
		parse.side = 1;
		if (parsing(av[1], &parse))
			return (1);
		ft_print_polynome(parse.first);
		reduce(&parse);

		//resolve(&parse);
		//print(&parse);
		ft_putchar('\n');
	}
	else
		ft_putendl("usage: ./computorV1 <expression>");
	return (0);
}