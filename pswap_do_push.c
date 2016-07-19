/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_do_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:59:47 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 17:40:13 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		delone_pile(t_pile **x)
{
	t_pile *m1;
	t_pile *safe_prev;
	t_pile *safe_next;

	m1 = *x;
	if (m1->next == *x)
	{
		free(m1);
		*x = NULL;
	}
	else
	{
		safe_next = m1->next;
		safe_prev = m1->previous;
		free(m1);
		safe_prev->next = safe_next;
		safe_next->previous = safe_prev;
		*x = safe_next;
	}
}

static void	insertone_pile(t_pile **x, int nb)
{
	t_pile *tmp;
	t_pile *m1;
	t_pile *safe_prev;

	if ((tmp = (t_pile *)malloc(sizeof(t_pile))) == NULL)
		exit(1);
	tmp->nb = nb;
	if (*x == NULL)
	{
		*x = tmp;
		tmp->next = *x;
		tmp->previous = *x;
	}
	else
	{
		m1 = *x;
		safe_prev = m1->previous;
		tmp->next = m1;
		tmp->previous = safe_prev;
		m1->previous = tmp;
		safe_prev->next = tmp;
		*x = tmp;
	}
}

void		do_pa(t_pile **b, t_pile **a, t_swap *sw)
{
	t_pile	*b1;

	b1 = *b;
	if (*b == NULL)
		return ;
	insertone_pile(a, b1->nb);
	delone_pile(b);
	pswap_print_do(a, b, sw, "pa");
}

void		do_pb(t_pile **a, t_pile **b, t_swap *sw)
{
	t_pile	*a1;

	a1 = *a;
	if (*a == NULL)
		return ;
	insertone_pile(b, a1->nb);
	delone_pile(a);
	pswap_print_do(a, b, sw, "pb");
}
