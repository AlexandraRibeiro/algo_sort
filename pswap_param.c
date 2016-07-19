/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 19:11:47 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 19:13:14 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	verif_duplicate(t_pile **a, t_pile **b, t_swap *sw, int n)
{
	t_pile *end;

	if (*a == NULL)
		return ;
	end = *a;
	while (end->next != *a)
	{
		if (end->nb == n)
			pswap_display_fd(a, b, sw, 2);
		end = end->next;
	}
}

static int	bonusl(t_pile **a, t_pile **b, t_swap *sw)
{
	if (sw->ac == 2)
		pswap_display_fd(a, b, sw, 2);
	if ((sw->flags & BONUS_M || sw->flags & BONUS_V) && sw->ac == 3)
		pswap_display_fd(a, b, sw, 2);
	if ((sw->flags & BONUS_M && sw->flags & BONUS_V) && sw->ac == 4)
		pswap_display_fd(a, b, sw, 2);
	else
	{
		if (!(sw->flags & BONUS_M) && !(sw->flags & BONUS_V))
			ft_set_bit(&(sw->flags), BONUS_L);
		if ((sw->j + 1) >= sw->ac)
			return (0);
	}
	return (1);
}

void		pswap_param(t_pile **a, t_pile **b, char **av, t_swap *sw)
{
	long long int	lln;
	int				n;

	sw->j = 1;
	while (sw->j < sw->ac)
	{
		if (ft_strcmp(sw->bonusl, av[sw->j]) == 0)
		{
			n = bonusl(a, b, sw);
			if (n == 0)
				return ;
			sw->j++;
		}
		if (param_bonus(a, b, av, sw) == 0)
			return ;
		lln = ll_atoi(av[sw->j], a, b, sw);
		if (lln > 2147483647 || lln < -2147483648)
			pswap_display_fd(a, b, sw, 2);
		n = (int)lln;
		verif_duplicate(a, b, sw, n);
		create_pilea(a, b, sw, n);
		sw->j++;
	}
}
