/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_check_justone_rev.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:08:02 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/26 13:43:28 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	justone_rev_cas2(t_pile **a, t_pile **b, t_swap *sw)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	t_pile	*tmp3;
	t_pile	*end;

	tmp = *b;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	end = tmp->previous;
	if (tmp->nb < tmp3->nb)
	{
		if ((tmp3->nb - tmp->nb) <= (tmp->nb - end->nb))
			do_sb(b, a, sw);
		else
			do_rb(b, a, sw);
	}
	else
		do_sb(b, a, sw);
}

/*
** check for example : 2 9 5 3
*/

int			pswap_justone_rev(t_pile **a, t_pile **b, t_swap *sw)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	t_pile	*end;

	tmp = *b;
	tmp2 = tmp->next;
	end = tmp->previous;
	if (tmp->nb < tmp2->nb && tmp->nb < end->nb)
	{
		do_rb(b, a, sw);
		return (0);
	}
	else if (tmp->nb < tmp2->nb && tmp->nb > end->nb)
	{
		justone_rev_cas2(a, b, sw);
		return (0);
	}
	return (1);
}
