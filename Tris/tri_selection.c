/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_selection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:45:00 by chbadad           #+#    #+#             */
/*   Updated: 2021/08/27 18:52:13 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int *tri_selection(char **av, int size)
{
	int *tab;
	int i;
	int j;
	int k;
	int min;
	int mem_size;
	int count;

	count = 0;
	mem_size = size;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return;
	i = 0;
	while (size--)
	{
		tab[i] = atoi(av[i + 1]);
		i++;
	}
	i = 0;
	while (i < mem_size)
	{
		min = i;
		j = i + 1;
		while (j < mem_size)
		{
			if (tab[j] < tab[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			k = tab[i];
			tab[i] = tab[min];
			tab[min] = k;
			count++;
		}
		i++;
	}
	printf("%d", count);
	return (tab);
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
