/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   computorv1.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 01:59:56 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 11:48:22 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <stdio.h>/////////////////////////////////////////////////////////////
# include <math.h>/////////////////////////////////////////////////////////////
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_nome
{
	double			coef;
	int				exp;
	struct s_nome	*next;
}					t_nome;

typedef struct		s_parse
{
	t_nome			*first;
	int				iscoef;
	double			coef;
	int				exp;
	int				side;
	int				poly_degree;
}					t_parse;

t_nome				*reduce(t_parse *parse);
void				resolve(t_parse *parse, t_nome *polynome);

t_nome				*ft_newnome(t_nome **first, double coef, int exp);
void				ft_delnome(t_nome **first);
void				ft_print_polynome(t_nome *first);
void				ft_sort_polynome(t_nome *nome);

#endif
