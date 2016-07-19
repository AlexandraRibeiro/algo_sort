/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:07:01 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 19:16:12 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bonus_display_pilea(t_pile **a, int f)
{
	t_pile *tmp;

	tmp = *a;
	ft_putstr_fd("\n-> a : (sommet a gauche)	", f);
	while (tmp->next != *a)
	{
		ft_putnbr_fd(tmp->nb, f);
		ft_putchar_fd(' ', f);
		tmp = tmp->next;
	}
	ft_putnbr_fd(tmp->nb, f);
	ft_putchar_fd('\n', f);
}

static void	bonus_display_pileb(t_pile **b, int f)
{
	t_pile *tmp;

	tmp = *b;
	ft_putstr_fd("-> b : (sommet a gauche)	", f);
	while (tmp->next != *b)
	{
		ft_putnbr_fd(tmp->nb, f);
		ft_putchar_fd(' ', f);
		tmp = tmp->next;
	}
	ft_putnbr_fd(tmp->nb, f);
	ft_putstr_fd("\n\n", f);
}

static void	mv_display(t_pile **a, t_pile **b, t_swap *sw, int f)
{
	if (!(sw->flags & INORDER))
		ft_putstr_fd(sw->mv, f);
	ft_putchar_fd('\n', f);
	if (sw->flags & BONUS_M)
	{
		ft_putstr_fd("Nombre de pas : ", f);
		ft_putnbr_fd(sw->countm, f);
		ft_putchar_fd('\n', f);
	}
	if (sw->flags & BONUS_L)
	{
		ft_putstr_fd("Nombre de pas : ", f);
		ft_putnbr_fd(sw->countm, f);
		ft_putchar_fd('\n', f);
		if (*a != NULL)
			bonus_display_pilea(a, f);
		else
			ft_putstr_fd("\n-> a : (vide)\n", f);
		if (*b != NULL)
			bonus_display_pileb(b, f);
		else
			ft_putstr_fd("-> b : (vide)\n\n", f);
	}
}

void		pswap_display_fd(t_pile **a, t_pile **b, t_swap *sw, int f)
{
	if (f == 2)
	{
		write(f, "Error\n", 6);
		pswap_free_pile(a);
		pswap_free_pile(b);
		exit(1);
	}
	if (f == 1)
	{
		if (sw->flags & BONUS_M || sw->flags & BONUS_V)
			ft_reset_bit(&(sw->flags), BONUS_L);
		if (sw->mv != NULL || sw->flags & INORDER)
			mv_display(a, b, sw, f);
		if (sw->flags & BONUS_V)
		{
			if (*a != NULL)
				bonus_display_pilea(a, f);
			else
				ft_putstr_fd("\n-> a : (vide)\n", f);
			if (*b != NULL)
				bonus_display_pileb(b, f);
			else
				ft_putstr_fd("-> b : (vide)\n\n", f);
		}
	}
}
