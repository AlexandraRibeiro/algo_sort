/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:02:12 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 18:48:58 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			pswap_free_pile(t_pile **x)
{
	while (*x != NULL)
		delone_pile(x);
}

static void		pswap_ini_struct(t_swap *sw, int ac)
{
	sw->j = 0;
	sw->c = 0;
	sw->flags = 0;
	sw->ac = ac;
	sw->error = 0;
	sw->count = 1;
	sw->countm = 0;
	sw->bonusl[0] = '-';
	sw->bonusl[1] = 'l';
	sw->bonusl[2] = '\0';
	sw->bonusm[0] = '-';
	sw->bonusm[1] = 'm';
	sw->bonusm[2] = '\0';
	sw->bonusv[0] = '-';
	sw->bonusv[1] = 'v';
	sw->bonusv[2] = '\0';
	sw->mv = NULL;
}

int				main(int ac, char *av[])
{
	t_pile	*a;
	t_pile	*b;
	t_swap	sw;

	a = NULL;
	b = NULL;
	pswap_ini_struct(&sw, ac);
	if (ac < 2)
	{
		pswap_display_fd(&a, &b, &sw, 2);
		return (0);
	}
	pswap_param(&a, &b, av, &sw);
	pswap_display_fd(&a, &b, &sw, 1);
	pswap_sort_list(&a, &b, &sw);
	if (!(sw.flags & BONUS_V) || sw.flags & INORDER)
		pswap_display_fd(&a, &b, &sw, 1);
	if (a != NULL)
		pswap_free_pile(&a);
	if (b != NULL)
		pswap_free_pile(&b);
	if (sw.mv != NULL)
		free(sw.mv);
	return (0);
}
