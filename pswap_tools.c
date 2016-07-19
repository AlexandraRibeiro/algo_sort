/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 20:57:52 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 17:55:07 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pswap_print_do(t_pile **a, t_pile **b, t_swap *sw, char *s)
{
	if (sw->mv != NULL)
		pswap_strjoin_ter(sw, " ", s);
	else
		pswap_strjoin_exit(sw, s);
	if (sw->flags & BONUS_V)
	{
		ft_putstr_fd("-------------------------------------------------\n", 1);
		pswap_display_fd(a, b, sw, 1);
	}
}

void	pswap_strjoin_ter(t_swap *sw, char *s3, char *s4)
{
	char	*tmp;
	size_t	len;

	tmp = NULL;
	if (s3 != NULL && s4 != NULL)
	{
		len = ft_strlen(s4) + 1;
		if (sw->mv != NULL)
			len += ft_strlen(sw->mv);
		tmp = ft_strnew_exit(len);
		if (sw->mv != NULL)
			tmp = ft_strcpy(tmp, sw->mv);
		tmp = ft_strcat(tmp, s3);
		tmp = ft_strcat(tmp, s4);
		if (sw->mv != NULL)
			free(sw->mv);
		sw->mv = tmp;
	}
	sw->countm++;
}

void	pswap_strjoin_exit(t_swap *sw, char *s3)
{
	char	*tmp;
	size_t	len;

	tmp = NULL;
	if (s3 != NULL)
	{
		len = ft_strlen(s3);
		if (sw->mv != NULL)
			len += ft_strlen(sw->mv);
		tmp = ft_strnew_exit(len);
		if (sw->mv != NULL)
			tmp = ft_strcpy(tmp, sw->mv);
		tmp = ft_strcat(tmp, s3);
		if (sw->mv != NULL)
			free(sw->mv);
		sw->mv = tmp;
	}
	sw->countm++;
}
