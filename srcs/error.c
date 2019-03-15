/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 02:27:25 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 11:47:41 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "computorv1.h"

int		free_exit(t_parse *parse)
{
	parse = NULL;
	return (0);
}

int		error(int error)
{
	if (!error)
		return (0);
	if (error == 1)
		ft_putendl("Malloc failed");
	if (error == 2)
		ft_putendl("Invalid expression");
	return (1);
}
