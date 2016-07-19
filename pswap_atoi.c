/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 20:54:08 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/24 15:20:07 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ll_atoi(char *str, t_pile **a, t_pile **b, t_swap *sw)
{
	long long int number;
	long long int signs;

	number = 0;
	signs = 1;
	if (*str == '-')
	{
		signs = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str < '0' || *str > '9')
		pswap_display_fd(a, b, sw, 2);
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	if (*str != '\0')
		pswap_display_fd(a, b, sw, 2);
	return (signs * number);
}
