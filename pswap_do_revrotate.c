/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_do_revrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:33:57 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 17:56:49 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_pile **x, t_pile **b, t_swap *sw)
{
	int		stock;
	t_pile	*m;
	t_pile	*before;

	if (*x == NULL)
		return ;
	m = *x;
	stock = 1;
	while (m->next != *x)
	{
		m = m->next;
		stock++;
	}
	if (stock == 1)
		return ;
	m = *x;
	before = m->previous;
	*x = before;
	if (sw->flags & OP_RR)
		return ;
	else
		pswap_print_do(x, b, sw, "rra");
}

void	do_rrb(t_pile **x, t_pile **a, t_swap *sw)
{
	int		stock;
	t_pile	*m;
	t_pile	*before;

	if (*x == NULL)
		return ;
	m = *x;
	stock = 1;
	while (m->next != *x)
	{
		m = m->next;
		stock++;
	}
	if (stock == 1)
		return ;
	m = *x;
	before = m->previous;
	*x = before;
	if (sw->flags & OP_RR)
		return ;
	else
		pswap_print_do(a, x, sw, "rrb");
}

void	do_rra_rrb(t_pile **a, t_pile **b, t_swap *sw)
{
	ft_set_bit(&(sw->flags), OP_RRR);
	do_rra(a, b, sw);
	do_rrb(b, a, sw);
	pswap_print_do(a, b, sw, "rrr");
	ft_reset_bit(&(sw->flags), OP_RRR);
}
