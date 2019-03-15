/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reduce.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 07:39:35 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 11:47:59 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "computorv1.h"

static t_nome	*print_sum(t_parse *parse, t_nome *sum)
{
	ft_putstr("Reduced form: ");
	ft_print_polynome(sum);
	ft_putstr("Polynomial degree: ");
	ft_putnbr(parse->poly_degree);
	ft_putchar('\n');
	return (sum);
}

static void		create_nome_missing(t_parse *parse, t_nome *sum, int *power)
{
	if (parse->poly_degree == 2)
		if (!power[1])
			ft_newnome(&sum, 0, 1);
	if (parse->poly_degree >= 1)
		if (!power[0])
			ft_newnome(&sum, 0, 0);
}

static void		finish_sum(t_parse *parse, t_nome **sum, int *power)
{
	t_nome	*tmp;

	create_nome_missing(parse, *sum, power);
	ft_delnome(&(parse->first));
	ft_sort_polynome(*sum);
	ft_sort_polynome(*sum);
	if ((*sum)->coef == 0)
	{
		tmp = (*sum)->next;
		free(*sum);
		*sum = tmp;
		(parse->poly_degree)--;
	}
	if ((*sum)->coef == 0)
	{
		tmp = (*sum)->next;
		free(*sum);
		*sum = tmp;
		(parse->poly_degree)--;
	}
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
		if (tmp->exp >= 3)
			return (NULL);
		if (!power[tmp->exp])
		{
			if (tmp->exp > parse->poly_degree)
				parse->poly_degree = tmp->exp;
			power[tmp->exp] = 1;
			ft_newnome(&sum, tmp->coef, tmp->exp);
		}
		else
			add_nome(sum, tmp);
		tmp = tmp->next;
	}
	finish_sum(parse, &sum, power);
	return (print_sum(parse, sum));
}
