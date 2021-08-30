/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:26:14 by chbadad           #+#    #+#             */
/*   Updated: 2021/08/30 19:36:45 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct	s_data
{
	void			*content;
	struct s_data	*next;
	struct s_data	*prev;
}				t_data;

typedef struct	s_linker
{
	t_data	*first;
	t_data	*last;
}				t_linker;

void	init_linker(t_linker *linker);
void	ft_lst_pushback(void *content, t_linker *linker);
void	ft_lst_pushfront(void *content, t_linker *linker);
int		ft_lst_removeback(t_linker *linker);
int		ft_lst_removefront(t_linker *linker);
void	ft_print_lst(t_linker linker);
void	ft_clear_lst(t_linker *linker);
