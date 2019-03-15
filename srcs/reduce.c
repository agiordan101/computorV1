/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reduce.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 07:39:35 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 08:59:44 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "computorV1.h"

static t_nome	*print_sum(t_parse *parse, t_nome *sum)
{
	ft_putstr("Reduced form: ");
	ft_print_polynome(sum);
	ft_putstr("Polynomial degree: ");
	ft_putchar(parse->poly_degree + '0');
	ft_putchar('\n');
	return (sum);
}

static void		add_nome(t_nome *sum, t_nome *tmp)
{
	while (sum)
	{
		if (sum->exp == tmp->exp)
			sum->coef += tmp->coef;
		sum = sum->next;
	}
}

t_nome			*reduce(t_parse *parse)
{
	t_nome	*sum;
	t_nome	*tmp;
	int		power[3];

	power[0] = 0;
	power[1] = 0;
	power[2] = 0;
	tmp = parse->first;
	sum = NULL;
	while (tmp)
	{
		if (!power[tmp->exp])
		{
			power[tmp->exp] = 1;
			parse->poly_degree = tmp->exp;
			if (tmp->exp >= 3)
				return (NULL);
			ft_newnome(&sum, tmp->coef, tmp->exp);
		}
		else
			add_nome(sum, tmp);
		tmp = tmp->next;
	}
	ft_delnome(&(parse->first));
	return (print_sum(parse, sum));
}
