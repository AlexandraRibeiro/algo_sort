/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_do_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:59:47 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 17:58:01 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_pile **a, t_pile **b, t_swap *sw)
{
	t_pile	*m;
	t_pile	*m2;
	int		stock;

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
	stock = m2->nb;
	m2->nb = m->nb;
	m->nb = stock;
	if (sw->flags & OP_SS)
		return ;
	else
		pswap_print_do(a, b, sw, "sa");
}

void	do_sb(t_pile **b, t_pile **a, t_swap *sw)
{
	t_pile	*m;
	t_pile	*m2;
	int		stock;

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
	stock = m2->nb;
	m2->nb = m->nb;
	m->nb = stock;
	if (sw->flags & OP_SS)
		return ;
	else
		pswap_print_do(a, b, sw, "sb");
}

void	do_sa_sb(t_pile **a, t_pile **b, t_swap *sw)
{
	ft_set_bit(&(sw->flags), OP_SS);
	do_sa(a, b, sw);
	do_sb(b, a, sw);
	pswap_print_do(a, b, sw, "ss");
	ft_reset_bit(&(sw->flags), OP_SS);
}
