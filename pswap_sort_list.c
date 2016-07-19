/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_sort_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:29:34 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 16:52:27 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge4_sort(t_pile **a, t_pile **b, t_swap *sw)
{
	do_sa(a, b, sw);
	do_ra(a, b, sw);
	do_sa(a, b, sw);
	do_pb(a, b, sw);
	do_sa(a, b, sw);
	do_pb(a, b, sw);
	do_sa_sb(a, b, sw);
	do_pa(b, a, sw);
	do_pa(b, a, sw);
}

static void	pswap_trio_sort(t_pile **a, t_pile **b, t_swap *sw)
{
	t_pile *tmp;
	t_pile *end;

	tmp = *a;
	end = tmp->previous;
	if (tmp->nb < end->nb)
	{
		do_pb(a, b, sw);
		do_sa(a, b, sw);
		do_pa(b, a, sw);
	}
	else if (tmp->nb > end->nb)
	{
		do_ra(a, b, sw);
		do_sa(a, b, sw);
	}
}

static int	sort_list_part2(t_pile **a, t_pile **b, t_swap *sw)
{
	int o;

	if (sw->count == 1)
	{
		ft_set_bit(&(sw->flags), INORDER);
		return (0);
	}
	o = pswap_ascending(a);
	if (o == 0)
	{
		ft_set_bit(&(sw->flags), INORDER);
		return (0);
	}
	if (sw->count > 2)
	{
		o = pswap_justone(a, b, sw);
		if (o == 0)
			return (0);
	}
	if (sw->count == 3)
	{
		pswap_trio_sort(a, b, sw);
		return (0);
	}
	return (1);
}

/*
** sw->count == 1 (in main.c > pswap_ini_struct)
*/

void		pswap_sort_list(t_pile **a, t_pile **b, t_swap *sw)
{
	t_pile	*end;
	int		o;

	end = *a;
	while (end->next != *a)
	{
		end = end->next;
		sw->count++;
	}
	if (sort_list_part2(a, b, sw) == 0)
		return ;
	o = pswap_descending(a);
	if (o == 0 && sw->count < 7)
	{
		if (sw->count == 4)
			merge4_sort(a, b, sw);
		else
			pswap_merge_sort(a, b, sw);
		return ;
	}
	if (sw->count > 3)
		pswap_global_sort(a, b, sw);
}
