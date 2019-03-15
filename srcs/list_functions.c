/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_functions.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 02:36:00 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 07:57:35 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "computorV1.h"

t_nome	*ft_newnome(t_nome **first, int coef, int exp)
{
	t_nome	*tmp;
	t_nome	*new;

	//printf("New nome : %d * X^%d\n", coef, exp);
	tmp = *first;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	if (!(new = (t_nome *)malloc(sizeof(t_nome))))
		return (NULL);
	//printf("%p --- %p\n", *first, new);
	new->coef = coef;
	new->exp = exp;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		*first = new;
	return (new);
}

void	ft_print_polynome(t_nome *first)
{
	while (first)
	{
		ft_putstr("\nNome : ");
		ft_putnbr((int)(first->coef));
		ft_putstr(" * X^");
		ft_putnbr(first->exp);
		//printf("Adresse : %p\n", first);
		first = first->next;
	}
}
