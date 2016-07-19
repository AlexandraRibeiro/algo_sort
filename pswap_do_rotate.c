/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_do_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:59:47 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 17:58:56 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_pile **a, t_pile **b, t_swap *sw)
{
	int		stock;
	t_pile	*m;
	t_pile	*m2;

	if (*a == NULL)
		return ;
	m = *a;
	stock = 1;
	while (m->next != *a)
	{
		m = m->next;
		stock++;
	}
	if (stock == 1)
		return ;
	m = *a;
	m2 = m->next;
	*a = m2;
	if (sw->flags & OP_RR)
		return ;
	else
		pswap_print_do(a, b, sw, "ra");
}

void	do_rb(t_pile **b, t_pile **a, t_swap *sw)
{
	int		stock;
	t_pile	*m;
	t_pile	*m2;

	if (*b == NULL)
		return ;
	m = *b;
	stock = 1;
	while (m->next != *b)
	{
		m = m->next;
		stock++;
	}
	if (stock == 1)
		return ;
	m = *b;
	m2 = m->next;
	*b = m2;
	if (sw->flags & OP_RR)
		return ;
	else
		pswap_print_do(a, b, sw, "rb");
}

void	do_ra_rb(t_pile **a, t_pile **b, t_swap *sw)
{
	ft_set_bit(&(sw->flags), OP_RR);
	do_ra(a, b, sw);
	do_rb(b, a, sw);
	pswap_print_do(a, b, sw, "rr");
	ft_reset_bit(&(sw->flags), OP_RR);
}
