/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_tableau.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:55:46 by chbadad           #+#    #+#             */
/*   Updated: 2021/08/27 17:10:34 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
/*
* Ici on remplit le tableau de int (integer)
*/
int	*fill_tab(char **av, int size)
{
	int		*tab;
	int		i;
	char	*ptr;
	//On utilise l'allocation dynamique avec malloc afin d'allouer la bonne taille.
	tab = malloc(sizeof(int) * size);
	//On teste si l'allocation s'est bien déroulée.
	if (!tab)
		return (NULL);
	// On initilise l'indice i à 0
	// Le premier argument à l'indice 0 étant le nom du programme on ajoute 1
	// à l'indice.
	// On utilise strtol afin de convertir la chaîne en int.
	// La fonction atoi() est dépréciée mais utilisable pour l'exercice.
	i = 0;
	while (size--)
	{
		tab[i] = (int)strtol(av[i + 1], &ptr, 10);
		i++;
	}
	return (tab);
}

//On imprime
void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (size--)
		printf("%d\n", tab[i++]);
}

int	main(int ac, char **av)
{
	int	*tab;

	if (ac > 1)
	{
		//On met ac - 1 car le premier argument de av (ou argv) est toujours
		//le nom du programme
		tab = fill_tab(av, ac - 1);
		//On imprime le tableau
		print_tab(tab, ac - 1);
		//On libère la mémoire allouée via malloc.
		free(tab);
		tab = NULL;
		return (0);
	}
	else
	{
		//Si il n'y a pas plus d'un seul argument, on quitte le programme
		//avec un message d'erreur.
		printf("S'il vous plaît, mettez des arguments : (./nom du programme) (vos arguments...)\n");
		return (-1);
	}
}
