/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_functions.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 02:36:00 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 10:53:45 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "computorV1.h"

t_nome	*ft_newnome(t_nome **first, double coef, int exp)
{
	t_nome	*tmp;
	t_nome	*new;

	tmp = *first;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	if (!(new = (t_nome *)malloc(sizeof(t_nome))))
		return (NULL);
	new->coef = coef;
	new->exp = exp;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		*first = new;
	return (new);
}

void	ft_delnome(t_nome **first)
{
	t_nome	*tmp;

	while (*first)
	{
		tmp = (*first)->next;
		free(*first);
		*first = tmp;
	}
}

void	ft_print_polynome(t_nome *first)
{
	while (first)
	{
		if (first->coef >= 0)
			ft_putstr(" + ");
		else
			ft_putstr(" - ");
		ft_putnbr(ft_abs((int)(first->coef)));
		ft_putstr(" * X^");
		ft_putnbr(first->exp);
		first = first->next;
	}
	ft_putendl(" = 0");
}

void	ft_sort_polynome(t_nome *first)
{
	t_nome	*tmp;
	double	tmpValue;

	tmp = first;
	first = first->next;
	while (first)
	{
		if (tmp->exp < first->exp)
		{
			tmpValue = tmp->coef;
			tmp->coef = first->coef;
			first->coef = tmpValue;
			ft_swapint(&(tmp->exp), &(first->exp));
		}
		first = first->next;
		tmp = tmp->next;
	}
}
