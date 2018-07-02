/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utility_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static void	file_dir_reverse_sort_lst_p2(t_list **erreur, t_list **file,
	t_list **dir)
{
	ft_lstreverse(file);
	ft_lstreverse(dir);
	ft_lstaddend(erreur, *file);
	ft_lstaddend(erreur, *dir);
}

static void ft_get_error(t_list **erreur, t_list **search, t_list **tmp)
{
	struct stat	items;

	if (*search && !stat(((*search)->content), &items) &&
		errno == ENOENT && (*erreur = *search))
		*tmp = *erreur;
	while (*tmp && (*tmp)->next &&
		!stat((*tmp)->next->content, &items) && errno == ENOENT)
		*tmp = (*tmp)->next;
}


void		file_dir_reverse_sort_lst(t_list **search)
{
	struct stat	items;
	t_list		*erreur;
	t_list		*file;
	t_list		*dir;
	t_list		*tmp;

	erreur = NULL;
	tmp = *search;
	ft_get_error(&erreur, search, &tmp);
	file = NULL;
	if (tmp && tmp->next && !stat(tmp->next->content, &items) &&
		!S_ISDIR(items.st_mode))
	{
		file = tmp->next;
		tmp->next = NULL;
		tmp = file;
	}
	while (tmp && !stat(tmp->content, &items) &&
		!S_ISDIR(items.st_mode))
		tmp = tmp->next;
	dir = tmp;
	tmp->next = NULL;
	file_dir_reverse_sort_lst_p2(&erreur, &file, &dir);
}
