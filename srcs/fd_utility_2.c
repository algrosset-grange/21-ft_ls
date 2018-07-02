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
	if (*erreur)
	printf("(*erreur)->content = %s\n", (*erreur)->content);
	if (*file)
	printf("(*file)->content = %s\n", (*file)->content);
	if (*dir)
	printf("(*dir)->content = %s\n", (*dir)->content);
	ft_lstreverse(file);
	ft_lstreverse(dir);
	ft_lstaddend(erreur, *file);
	ft_lstaddend(erreur, *dir);
}

static void	ft_get_error(t_list **erreur, t_list **search, t_list **tmp)
{
	struct stat	items;

	if (*search && stat(((*search)->content), &items) &&
		errno == ENOENT && (*erreur = *search))
		*tmp = *erreur;
	while (*tmp && (*tmp)->next &&
		stat((*tmp)->next->content, &items) && errno == ENOENT)
		*tmp = (*tmp)->next;
}

int	ft_cmp_reverse(char *file1, char *file2, t_flags *toggle, char *dir)
{
	struct stat	item1;
	struct stat	item2;

	()
	if (file1 && file2 &&
		!stat(file1, &item1) &&
		!stat(file2, &item2) &&
		ft_strcmp(file1, file2) < 0 &&
		((!S_ISDIR(item1.st_mode) && !S_ISDIR(item2.st_mode)) ||
		(S_ISDIR(item1.st_mode) && S_ISDIR(item2.st_mode))))
		return (1);
	return(0);
}

void		file_dir_reverse_sort_lst(t_list **search)
{
	ft_sort();
	/*
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
	*/
}
