/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   computorV1.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 01:59:56 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 07:55:51 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <stdio.h>/////////////////////////////////////////////////////////////
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_nome
{
	int				coef;
	int				exp;
	struct s_nome	*next;
}					t_nome;

typedef struct		s_parse
{
	t_nome			*first;
	int				iscoef;
	int				coef;
	int				exp;
	int				side;
	int				polynomial_degree;	
}					t_parse;

void				reduce(t_parse *parse);

t_nome				*ft_newnome(t_nome **first, int coef, int exp);
void				ft_print_polynome(t_nome *first);

#endif
