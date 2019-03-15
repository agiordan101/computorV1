/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 08:39:06 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 08:59:15 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "computorV1.h"

void	resolve(t_parse *parse, t_nome *polynome)
{
	if (parse->poly_degree == 0 && polynome->coef == 0)
		ft_putendl("This polynome is always true");
}
