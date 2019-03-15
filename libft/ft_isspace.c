/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isspace.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 07:58:37 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 08:03:55 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	return ((c != ' ' && c != '\t' && c != '\n' &&
				c != '\r' && c != '\v' && c != '\f') ? 0 : 1);
}