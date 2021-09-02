/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:28:30 by chbadad           #+#    #+#             */
/*   Updated: 2021/09/02 16:46:49 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liste.h"

// Le linker est là afin de faciliter le travail de la liste.
// Il regroupe la premier élément de la liste, ainsi que le dernier.
// C'est donc facile d'accéder à cet élément, et plus pratique afin d'insérer ou supprimer
// un élément en début ou fin de liste.

void	init_linker(t_linker *linker)
{
	linker->first = NULL;
	linker->last = NULL;
}

/*
** Listes doublement chaînées avec création de nouvel élément.
** L'ajout se fait en fin de liste.
*/

void	ft_lst_pushback(void *content, t_linker *linker)
{
	t_data	*new_list;

	new_list = malloc(sizeof(t_data));
	if (!new_list)
		return ;
	// Le contenu de la nouvelle liste est le contenu en paramètree.
	new_list->content = content;
	//Le pointeur précédent la nouvelle structure est égal au dernier élément de la liste
	new_list->prev = linker->last;
	// Si il y a déjà un élément en fin de liste, alors cet élément a pour nouveau successeur
	// la nouvelle liste (étant donné qu'on met à la fin de la liste)
	// Sinon, cela veut dire que c'est le premier élément ajouté.
	if (linker->last)
		linker->last->next = new_list;
	else
		linker->first = new_list;
	// Dans tous les ca son enregistre la nouvelle structure comme étant le dernier élément de la liste.
	linker->last = new_list;
	new_list->next = NULL;
	new_list->prev = NULL;
}

void	ft_lst_pushfront(void *content, t_linker *linker)
{
	t_data	*new_list;

	new_list = (t_data *)malloc(sizeof(t_data));
	if (!new_list)
		return ;
	// Le contenu de la nouvelle liste est le contenu en paramètree.
	new_list->content = content;
	//Le pointeur précédent la nouvelle structure est égal au dernier élément de la liste
	new_list->next = linker->first;
	// Si il y a déjà un élément en début de liste, alors cet élément a pour nouveau précédent
	// la nouvelle liste (étant donné qu'on met au début de la liste)
	// Sinon, cela veut dire que c'est le premier élément ajouté.
	if (linker->first)
		linker->first->prev = new_list;
	else
		linker->last = new_list;
	// Dans tous les ca son enregistre la nouvelle structure comme étant le premier élément de la liste.
	linker->first = new_list;
	new_list->next = NULL;
	new_list->prev = NULL;
}

int	ft_lst_removeback(t_linker *linker)
{
	t_data	*temp;

	temp = linker->last;
	if (!temp)
		return (0);
	linker->last = temp->prev;
	if (linker->last)
		linker->last->next = NULL;
	else
		linker->first = NULL;
	free(temp);
	return (1);
}

int	ft_lst_removefront(t_linker *linker)
{
	t_data	*temp;

	temp = linker->last;
	if (!temp)
		return (0);
	linker->first = temp->next;
	if (linker->first)
		linker->first->prev = NULL;
	else
		linker->last = NULL;
	free(temp);
	return (1);
}

// On parcourt du début à la fin de la liste.
void	ft_print_lst(t_linker linker)
{
	t_data	*lst;

	lst = linker.first;
	while (lst)
	{
		printf("%d\n", (int)lst->content);
		lst = lst->next;
	}
}
// On supprime toute la liste
void	ft_clear_lst(t_linker *linker)
{
	t_data *temp;
	t_data *curr;

	curr = linker->first;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	linker->first = NULL;
	linker->last = NULL;
}

int	main(int ac, char **av)
{
	t_linker	lnk;
	int			i;

	i = 1;
	init_linker(&lnk);
	if (ac > 1)
	{
		while (i < ac)
			ft_lst_pushback((void *) (intptr_t) atoi(av[i++]), &lnk);
		ft_print_lst(lnk);
		ft_clear_lst(&lnk);
	}
	return (0);
}
