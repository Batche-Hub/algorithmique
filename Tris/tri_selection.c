/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_selection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:45:00 by chbadad           #+#    #+#             */
/*   Updated: 2021/08/29 12:00:58 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (size--)
		printf("%d\n", tab[i++]);
}

int	*fill_tab(char **av, int size)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (size--)
	{
		tab[i] = atoi(av[i + 1]);
		i++;
	}
	return (tab);
}

void	ft_min(int *tab, int j, int size, int *min)
{
	while (j < size)
	{
		if (tab[j] < tab[(*min)])
			(*min) = j;
		j++;
	}
}

void	ft_swap(int *tab, int i, int min)
{
	int	temp;

	temp = tab[i];
	tab[i] = tab[min];
	tab[min] = temp;
}

void	tri_selection(char **av, int size)
{
	int	*tab;
	int	min;
	int	i;
	int	j;

	tab = fill_tab(av, size);
	printf("Tableau avant tri :\n");
	print_tab(tab, size);
	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		ft_min(tab, j, size, &min);
		ft_swap(tab, i, min);
		i++;
	}
	printf("\nTableau après tri :\n");
	print_tab(tab, size);
	free(tab);
}

int main(int ac, char **av)
{
	if (ac > 1)
		tri_selection(av, ac - 1);
	else
	{
		printf("Veuillez rentrer un ou plusieurs arguments.");
		return (-1);
	}
}
