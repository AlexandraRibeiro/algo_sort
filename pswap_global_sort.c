/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_global_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:24:39 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 17:03:44 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	global_sort_p4(t_pile **a, t_pile **b, t_swap *sw)
{
	while (sw->tmp2 != *b)
	{
		while ((sw->b1)->nb > (sw->tmp2)->nb)
		{
			if ((sw->b1)->nb < (sw->b1)->previous->nb)
				do_rb(b, a, sw);
			else
			{
				while ((sw->b1)->nb > (sw->tmp2)->nb && sw->tmp2 != *b)
					sw->tmp2 = (sw->tmp2)->next;
				if (sw->tmp2 == *b)
					do_pa(b, a, sw);
				else
					do_rb(b, a, sw);
			}
			sw->b1 = *b;
			sw->tmp2 = (sw->b1)->next;
		}
		if ((sw->b1)->nb < (sw->tmp2)->nb)
			pswap_justone_rev(a, b, sw);
		sw->b1 = *b;
		sw->tmp2 = (sw->b1)->next;
	}
}

static void	global_sort_p3(t_pile **a, t_pile **b, t_swap *sw)
{
	sw->b1 = *b;
	sw->tmp2 = (sw->b1)->next;
	if (sw->c > 2)
	{
		if (pswap_descending(b) != 0)
		{
			pswap_justone_rev(a, b, sw);
			sw->b1 = *b;
			sw->tmp2 = (sw->b1)->next;
		}
	}
}

static int	global_sort_p2(t_pile **a, t_pile **b, t_swap *sw)
{
	sw->j = 0;
	if (pswap_ascending(a) == 0)
	{
		if (sw->c == 1 && (sw->tmp)->nb > (sw->b1)->nb)
			return (0);
		while ((sw->tmp)->nb > (sw->b1)->nb && sw->j < sw->c && sw->c > 1)
		{
			sw->b1 = (sw->b1)->next;
			(sw->j)++;
		}
		if (sw->j == sw->c && sw->c > 1)
			return (0);
	}
	do_pb(a, b, sw);
	(sw->c)++;
	sw->b1 = *b;
	if (*b != NULL && sw->c > 1)
	{
		if (pswap_descending(b) != 0)
		{
			pswap_justone_rev(a, b, sw);
			sw->b1 = *b;
		}
	}
	return (1);
}

static void	global_sort_p1(t_pile **a, t_pile **b, t_swap *sw)
{
	while ((sw->tmp)->nb > (sw->end)->nb || (sw->tmp)->nb > (sw->tmp2)->nb)
	{
		if ((sw->tmp)->nb > (sw->end)->nb)
			do_ra(a, b, sw);
		else if ((sw->tmp)->nb > (sw->tmp2)->nb)
		{
			if (*b != NULL && sw->c > 1 && (sw->b1)->nb < (sw->b1)->next->nb)
			{
				do_sa_sb(a, b, sw);
				(sw->b1) = *b;
			}
			else
				do_sa(a, b, sw);
		}
		sw->tmp = *a;
		sw->tmp2 = (sw->tmp)->next;
		sw->end = (sw->tmp)->previous;
	}
}

void		pswap_global_sort(t_pile **a, t_pile **b, t_swap *sw)
{
	sw->tmp = *a;
	sw->tmp2 = (sw->tmp)->next;
	sw->end = (sw->tmp)->previous;
	while ((sw->tmp)->next != *a)
	{
		global_sort_p1(a, b, sw);
		if (global_sort_p2(a, b, sw) == 0)
			break ;
		sw->tmp = *a;
		sw->tmp2 = (sw->tmp)->next;
		sw->end = (sw->tmp)->previous;
	}
	if (*b != NULL)
	{
		global_sort_p3(a, b, sw);
		global_sort_p4(a, b, sw);
		do_pa(b, a, sw);
	}
}
