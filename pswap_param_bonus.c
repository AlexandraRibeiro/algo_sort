/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_param_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:26:36 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 19:16:31 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bonusm(t_pile **a, t_pile **b, t_swap *sw)
{
	if (sw->ac == 2)
		pswap_display_fd(a, b, sw, 2);
	if ((sw->flags & BONUS_V || sw->flags & BONUS_L) && sw->ac == 3)
		pswap_display_fd(a, b, sw, 2);
	if ((sw->flags & BONUS_V && sw->flags & BONUS_L) && sw->ac == 4)
		pswap_display_fd(a, b, sw, 2);
	else
	{
		ft_set_bit(&(sw->flags), BONUS_M);
		if ((sw->j + 1) >= sw->ac)
			return (0);
	}
	return (1);
}

static int	bonusv(t_pile **a, t_pile **b, t_swap *sw)
{
	if (sw->ac == 2)
		pswap_display_fd(a, b, sw, 2);
	if ((sw->flags & BONUS_M || sw->flags & BONUS_L) && sw->ac == 3)
		pswap_display_fd(a, b, sw, 2);
	if ((sw->flags & BONUS_M && sw->flags & BONUS_L) && sw->ac == 4)
		pswap_display_fd(a, b, sw, 2);
	else
	{
		ft_set_bit(&(sw->flags), BONUS_V);
		if ((sw->j + 1) >= sw->ac)
			return (0);
	}
	return (1);
}

int			param_bonus(t_pile **a, t_pile **b, char **av, t_swap *sw)
{
	int n;

	if (ft_strcmp(sw->bonusv, av[sw->j]) == 0)
	{
		n = bonusv(a, b, sw);
		if (n == 0)
			return (0);
		sw->j++;
	}
	if (ft_strcmp(sw->bonusm, av[sw->j]) == 0)
	{
		n = bonusm(a, b, sw);
		if (n == 0)
			return (0);
		sw->j++;
		if (ft_strcmp(sw->bonusv, av[sw->j]) == 0)
		{
			n = bonusv(a, b, sw);
			if (n == 0)
				return (0);
			sw->j++;
		}
	}
	return (1);
}
