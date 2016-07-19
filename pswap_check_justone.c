/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_check_justone.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:48:23 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/26 13:43:23 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	justone_cas3(t_pile **a, t_pile **b, t_swap *sw)
{
	t_pile *tmp;
	t_pile *tmp2;
	t_pile *tmp3;

	tmp = *a;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	while (tmp2->nb < tmp3->nb && tmp3 != tmp)
	{
		tmp2 = tmp2->next;
		tmp3 = tmp3->next;
	}
	if (tmp3 == tmp)
	{
		do_sa(a, b, sw);
		return (0);
	}
	return (1);
}

static int	justone_cas2(t_pile **a, t_pile **b, t_swap *sw)
{
	t_pile *tmp;
	t_pile *tmp2;
	t_pile *end;

	tmp = *a;
	tmp2 = tmp->next;
	end = tmp->previous;
	while (tmp->nb < tmp2->nb && tmp2 != end)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	if (tmp2 == end)
	{
		do_rra(a, b, sw);
		return (0);
	}
	return (1);
}

static int	justone_cas1(t_pile **a, t_pile **b, t_swap *sw)
{
	t_pile *tmp;
	t_pile *tmp2;
	t_pile *tmp3;

	tmp = *a;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	while (tmp2->nb < tmp3->nb && tmp3 != tmp)
	{
		tmp2 = tmp2->next;
		tmp3 = tmp3->next;
	}
	if (tmp3 == tmp)
	{
		do_ra(a, b, sw);
		return (0);
	}
	return (1);
}

/*
** check for example : 5 1 2 3 4 or 2 3 4 5 1 or 2 1 3 4 5
*/

int			pswap_justone(t_pile **a, t_pile **b, t_swap *sw)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	t_pile	*tmp3;
	t_pile	*end;

	tmp = *a;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	end = tmp->previous;
	if (tmp->nb > tmp2->nb && tmp->nb > end->nb)
	{
		if (justone_cas1(a, b, sw) == 0)
			return (0);
	}
	else if (end->nb < tmp->nb && tmp->nb < tmp2->nb)
	{
		if (justone_cas2(a, b, sw) == 0)
			return (0);
	}
	else if (tmp->nb > tmp2->nb && tmp->nb < end->nb && tmp->nb < tmp3->nb)
	{
		if (justone_cas3(a, b, sw) == 0)
			return (0);
	}
	return (1);
}
