/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_indirect_par_indice.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:54:17 by chbadad           #+#    #+#             */
/*   Updated: 2021/08/31 11:29:31 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/**
 * Ce tri est, comme l'indique le titre, un tri indirect, c'est à dire qu'il ne manipule pas
 * directement la pile ou la liste pour opérer le tri,
 * mais accole un indice placé dans un tableau d'indice à l'endroit où est supposé
 * se trouver la donnée.
 * Par exemple :
 * 
 *   0    1   2  || Indices
 * | 3 | 18 | 1 ||| Valeurs
 *   |____\__/
 *   |    |  \
 *   0    1   2  || Indices
 * | 2 |  0 | 1 ||| Valeurs (qui ici correspondent aux indices des valeurs du tableau au-dessus)
 *   |    |   |
 *   1    3   18  <= Tableau trié.
 * 
 * L'intérêt principal réside dans le fait que le rangemernt ne se fait qu'une fois pour le tableau trié.
 * D'une certaine façon, cela agit un peu comme des pointeurs mais sans pointeurs.
 * Une méthode consiste à faire la même chose mais avec de vrais pointeurs par ailleurs.
**/


// Ici on ne trie pas vraiment, on place les valeurs des indices au bon endroit.
void tri_indirect_indices(int tab[], int index[], int size)
{
	int	i;
	int	j;
	int	index_val;
	int	val;

	i = -1;
	// On initialise le tableau d'incice avec les indices.
	// Pour tab[10] => index[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	while (++i < size)
		index[i] = i;
	i = -1;
	while (++i < size)
	{
		index_val = index[i];
		val = tab[index_val];
		j = i;
		// On déplace les éléments plus petits à gauche en faisant référence à l'indice dans le tableau d'indice.
		// Si la val == 13 j == 3 et que l'indice de tab[index[j - 1]] pointe vers une valeur + grande (ex : 50) ALORS on déplace l'indice.
		while ((j > 0) && (val < tab[index[j - 1]]))
		{
			index[j] = index[j - 1];
			j--;
		}
		// On place la valeur de l'indice à la bonne place (on ne place pas la valeur du tableau à la bonne place)
		index[j] = index_val;
	}
}

void print(int tab[], int index[], int size)
{
	int i;

	printf("   Tableau direct des valeurs  : ");
	for (i = 0; i < size; i++)
		printf("%10d", tab[i]);
	printf("\n");
	printf("   Tableau des indices         : ");
	for (i = 0; i < size; i++)
		printf("%10d", index[i]);
	printf("\n");
	printf("   Tableau indirect des valeurs: ");
	for (i = 0; i < size; i++)
		printf("%10d", tab[index[i]]);
	printf("\n");
}

void organise(int tab[], int index[], int size)
{
	int	i;
	int	start_index;
	int	target_index;
	int	val;

	i = -1;
	while (++i < size)
	{
		if (index[i] != i)
		{
			val = tab[i];
			target_index = i;
			start_index = index[target_index];
			while (start_index != i)
			{
				tab[target_index] = tab[start_index];
				index[target_index] = target_index;
				target_index = start_index;
				start_index = index[target_index];
			}
			tab[target_index] = val;
			index[target_index] = target_index;
		}
	}
}

int	main(void)
{
	int tab[10] = {-1, 50, -210, 13, 0, 0, 4810, 78, -145, 1};
	int index[10];
	tri_indirect_indices(tab, index, 10);
	print(tab, index, 10);
	organise(tab, index, 10);
	// Ici vu que le tableau d'indices est déjà trié, le tableau des valeurs semble trié.
	// C'est bien le cas, mais si nous n'avions pas fait la régorganisation des valeurs, ce ne serait pas le cas
	// (nous n'avions réorganisé que le tableau des indices).
	print(tab, index, 10);
	return (0);
}
