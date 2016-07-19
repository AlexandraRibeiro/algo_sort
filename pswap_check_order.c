/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_check_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 19:18:31 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 15:01:46 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** check ascending order
*/

int		pswap_ascending(t_pile **x)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = *x;
	tmp2 = tmp->next;
	while (tmp->nb < tmp2->nb && tmp2 != *x)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	if (tmp2 == *x)
		return (0);
	else
		return (1);
}

/*
** check descending order
*/

int		pswap_descending(t_pile **x)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = *x;
	tmp2 = tmp->next;
	while (tmp->nb > tmp2->nb && tmp2 != *x)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	if (tmp2 == *x)
		return (0);
	else
		return (1);
}
