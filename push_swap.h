/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:52:31 by aribeiro          #+#    #+#             */
/*   Updated: 2016/03/25 19:05:40 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

/*
** BONUS_V : -v : print all steps
** BONUS_M : -m : count steps
*/
# define OP_SS		0x80000000
# define OP_RR		0x40000000
# define OP_RRR		0x20000000
# define BONUS_L	0x01000000
# define BONUS_V	0x02000000
# define BONUS_M	0x08000000
# define INORDER	0x04000000

typedef struct		s_pile
{
	int				nb;
	struct s_pile	*previous;
	struct s_pile	*next;
}					t_pile;

typedef	struct		s_swap
{
	t_pile			*tmp;
	t_pile			*tmp2;
	t_pile			*end;
	t_pile			*start;
	t_pile			*b1;
	int				j;
	int				c;
	int				flags;
	int				ac;
	int				error;
	int				count;
	int				countm;
	char			bonusl[3];
	char			bonusm[3];
	char			bonusv[3];
	char			*mv;
}					t_swap;

void				create_pilea(t_pile **a, t_pile **b, t_swap *sw, int nb);
void				create_pileb(t_pile **b, t_pile **a, t_swap *sw, int nb);
void				pswap_free_pile(t_pile **x);
void				pswap_param(t_pile **a, t_pile **b, char **av, t_swap *sw);
int					param_bonus(t_pile **a, t_pile **b, char **av, t_swap *sw);

void				pswap_sort_list(t_pile **a, t_pile **b, t_swap *sw);
int					pswap_ascending(t_pile **x);
int					pswap_descending(t_pile **x);
int					pswap_justone(t_pile **a, t_pile **b, t_swap *sw);
int					pswap_justone_rev(t_pile **a, t_pile **b, t_swap *sw);
void				pswap_merge_sort(t_pile **a, t_pile **b, t_swap *sw);
void				pswap_global_sort(t_pile **a, t_pile **b, t_swap *sw);

void				pswap_display_fd(t_pile **a, t_pile **b, t_swap *sw, int f);
void				pswap_print_do(t_pile **a, t_pile **b, t_swap *sw, char *s);
void				pswap_strjoin_exit(t_swap *sw, char *s3);
void				pswap_strjoin_ter(t_swap *sw, char *s3, char *s4);

void				do_sa(t_pile **a, t_pile **b, t_swap *sw);
void				do_sb(t_pile **b, t_pile **a, t_swap *sw);
void				do_sa_sb(t_pile **a, t_pile **b, t_swap *sw);
void				do_ra(t_pile **a, t_pile **b, t_swap *sw);
void				do_rb(t_pile **b, t_pile **a, t_swap *sw);
void				do_ra_rb(t_pile **a, t_pile **b, t_swap *sw);
void				do_rra(t_pile **x, t_pile **b, t_swap *sw);
void				do_rrb(t_pile **x, t_pile **a, t_swap *sw);
void				do_rra_rrb(t_pile **a, t_pile **b, t_swap *sw);
void				do_pa(t_pile **b, t_pile **a, t_swap *sw);
void				do_pb(t_pile **a, t_pile **b, t_swap *sw);
void				delone_pile(t_pile **x);

/*
** libft functions with exit for error malloc
*/
long long int		ll_atoi(char *str, t_pile **a, t_pile **b, t_swap *sw);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_set_bit(int *flags, int bitval);
void				ft_reset_bit(int *flags, int bitval);
char				*ft_strcat(char *s1, const char *s2);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *s);
char				*ft_strnew_exit(size_t size);

#endif
