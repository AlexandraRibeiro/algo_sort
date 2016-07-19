/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:11:08 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 18:11:08 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		create_pilea(t_pile **a, t_pile **b, t_swap *sw, int nb)
{
	t_pile *tmp;
	t_pile *end;

	if ((tmp = (t_pile *)malloc(sizeof(t_pile))) == NULL)
		exit(1);
	tmp->nb = nb;
	if (*a == NULL)
	{
		*a = tmp;
		tmp->next = *a;
		tmp->previous = *a;
	}
	else
	{
		(sw->start) = *a;
		end = *a;
		while (end->next != *a && end->nb != nb)
			end = end->next;
		if (end->nb == nb)
			pswap_display_fd(a, b, sw, 2);
		end->next = tmp;
		tmp->previous = end;
		tmp->next = *a;
		(sw->start)->previous = tmp;
	}
}

void		create_pileb(t_pile **b, t_pile **a, t_swap *sw, int nb)
{
	t_pile *tmp;
	t_pile *end;

	if ((tmp = (t_pile *)malloc(sizeof(t_pile))) == NULL)
		exit(1);
	tmp->nb = nb;
	if (*b == NULL)
	{
		*b = tmp;
		tmp->next = *b;
		tmp->previous = *b;
	}
	else
	{
		sw->start = *b;
		end = *b;
		while (end->next != *b && end->nb != nb)
			end = end->next;
		if (end->nb == nb)
			pswap_display_fd(a, b, sw, 2);
		end->next = tmp;
		tmp->previous = end;
		tmp->next = *b;
		(sw->start)->previous = tmp;
	}
}
