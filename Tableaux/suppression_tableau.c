/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suppression_tableau.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:55:46 by chbadad           #+#    #+#             */
/*   Updated: 2021/08/27 17:38:29 by chbadad          ###   ########.fr       */
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

//On l'imprime
void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	printf("[");
	while (size--)
		printf("%d ", tab[i++]);
	printf("]\n");
}

//On insère le nouvel élément
int	*insert_elem(int *prev_tab, int prev_size, int nb, int pos)
{
	int	*new_tab;
	int	i;
	int	j;
	int	new_size;

	//on crée un nouveau tableau via malloc de la taille précédente + 1
	new_tab = malloc(sizeof(int) * (prev_size + 1));
	if (!new_tab)
		return (NULL);
	//On utilise deux indices pour ne pas avoir de conflits entre les deux tableaux
	i = 0;
	j = 0;
	new_size = prev_size + 1;
	while (new_size--)
	{
		// Si i est égal à la position - 1 (un tableau commençant à 0 en c)
		// alors le nouveau tableau à l'indice courant est égal à notre nouveau nombre
		// new_tab[i++] est une faon plus compacte pour incrémenter l'indice i.
		if (i == pos - 1)
			new_tab[i++] = nb;
		new_tab[i++] = prev_tab[j++];
	}
	//On retourne le tableau
	return (new_tab);
}

void	modif_elem(int *tab, int size, int nb, int pos)
{
	int	i;

	i = 0;
	while (size--)
	{
		if (i == pos - 1)
		{
			tab[i] = nb;
			return ;
		}
		i++;
	}
}

int	*suppr_elem(int *prev_tab, int prev_size, int pos)
{
	int	*new_tab;
	int	i;
	int	j;
	int	new_size;

	//on crée un nouveau tableau via malloc de la taille précédente + 1
	new_tab = malloc(sizeof(int) * (prev_size - 1));
	if (!new_tab)
		return (NULL);
	//On utilise deux indices pour ne pas avoir de conflits entre les deux tableaux
	i = 0;
	j = 0;
	new_size = prev_size - 1;
	while (new_size--)
	{
		//Ici on considère l'indice j afin de passe l'élément dans le tableau existant.
		if (j == pos - 1)
			j++;
		new_tab[i++] = prev_tab[j++];
	}
	//On retourne le tableau
	return (new_tab);
}

int	main(int ac, char **av)
{
	int	*tab;
	int *new_tab;
	int	nb;
	int	pos;

	if (ac > 1)
	{
		//CREATION
		//On met ac - 1 car le premier argument de av (ou argv) est toujours
		//le nom du programme
		tab = fill_tab(av, ac - 1);
		printf("Tableau avant insertion :\n");
		//On imprime le tableau
		print_tab(tab, ac - 1);

		//INSERTION
		printf("Veuillez entrer un élément à insérer :\n");
		scanf("%d", &nb);
		printf("Sa position :\n");
		scanf("%d", &pos);
		if (pos < 1 || pos > ac)
		{
			printf("Veuillez entrer une position correcte >= 1 && <= %d :\n", ac);
			free(tab);
			return (-1);
		}
		new_tab = insert_elem(tab, ac - 1, nb, pos);
		printf("Tableau après insertion :\n");
		print_tab(new_tab, ac);

		//MODIFICATION
		printf("Veuillez la position de l'élément à modifier :\n");
		scanf("%d", &pos);
		printf("Sa nouvelle valeur :\n");
		scanf("%d", &nb);
		if (pos < 1 || pos > ac)
		{
			printf("Veuillez entrer une position correcte >= 1 && <= %d :\n", ac);
			free(new_tab);
			free(tab);
			tab = NULL;
			new_tab = NULL;
			return (-1);
		}
		modif_elem(new_tab, ac, nb, pos);
		printf("Tableau après modification :\n");
		print_tab(new_tab, ac);

		//SUPPRESSION
		printf("Veuillez entrer la position d'un élément à supprimer :\n");
		scanf("%d", &pos);
		if (pos < 1 || pos > ac)
		{
			printf("Veuillez entrer une position correcte >= 1 && <= %d :\n", ac);
			free(new_tab);
			free(tab);
			tab = NULL;
			new_tab = NULL;
			return (-1);
		}
		//On reprend le tableau tab afin d'éviter un nouvelle variable.
		free(tab);
		tab = suppr_elem(new_tab, ac, pos);
		printf("Tableau après suppression :\n");
		print_tab(tab, ac - 1);
		//FIN
		//On libère la mémoire allouée via malloc.
		free(tab);
		free(new_tab);
		tab = NULL;
		new_tab = NULL;
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
