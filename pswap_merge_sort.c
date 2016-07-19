/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_merge_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:33:37 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 15:37:55 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_sort_part2(t_pile **a, t_pile **b, t_swap *sw)
{
	int ret;

	if (sw->count > 3)
		do_sa_sb(a, b, sw);
	ret = sw->count / 2;
	while (ret > 0)
	{
		do_ra_rb(a, b, sw);
		ret--;
	}
	if (sw->count == 2 || sw->count == 3)
	{
		if (sw->count == 2)
			do_sa(a, b, sw);
		else
			do_sa_sb(a, b, sw);
	}
}

void		pswap_merge_sort(t_pile **a, t_pile **b, t_swap *sw)
{
	int i;

	i = 0;
	sw->count /= 2;
	while (i < sw->count)
	{
		do_pb(a, b, sw);
		i++;
	}
	merge_sort_part2(a, b, sw);
	while (i > 0)
	{
		do_pa(b, a, sw);
		i--;
	}
	while (i < sw->count)
	{
		do_ra(a, b, sw);
		i++;
	}
}
