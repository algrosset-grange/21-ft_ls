/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 09:35:31 by agrosset          #+#    #+#             */
/*   Updated: 2018/06/29 09:35:39 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static void	ft_print_next_directory(t_list *search, char *dir, char **name_dir,
	int a)
{
	char	*tmp;

	tmp = NULL;
	if (dir != NULL && ft_strcmp(search->content, dir))
	{
		tmp = ft_strjoin(dir, "/");
		*name_dir = ft_strjoin(tmp, search->content);
	}
	else
		*name_dir = ft_strdup(search->content);
	if (a)
	{
		ft_putstr("\n");
		ft_putstr(*name_dir);
		ft_putstr(":\n");
	}
	ft_memdel((void **)&tmp);
}

static int	ls_recurse_lst(t_list *search, t_flags *toggle, char *rep, int a)
{
	struct dirent	*d;
	DIR				*dir;
	int				item;
	t_list			*lst_char;
	char			*name_dir;

	name_dir = NULL;
	if ((item = item_amount_lst(search->content, rep, toggle)))
		return (1);
	ft_print_next_directory(search, rep, &name_dir, a);
	dir = opendir(name_dir);
	lst_char = NULL;
	while ((d = readdir(dir)))
	{
		if (d->d_name[0] != '.' || toggle->a == 1)
			ft_lstaddend(&lst_char, ft_lstnew(d->d_name,
				sizeof((void *)d->d_name) * ft_strlen(d->d_name)));
	}
	if (lst_char)
		ft_print(&lst_char, toggle, name_dir);
	closedir(dir);
	ft_memdel((void **)&name_dir);
	ft_lstdel(&lst_char, &ft_lstdelcontent);
	return (0);
}

int			ft_print_recurse(t_list **search, t_flags *toggle, char *dir)
{
	t_list		*maillon;

	maillon = *search;
	while (maillon)
	{
		ls_recurse_lst(maillon, toggle, dir, 1);
		maillon = maillon->next;
	}
	return (0);
}

void		ft_print_multi(t_list **search, t_flags *toggle, char *dir)
{
	t_list		*maillon;

	maillon = *search;
	ls_recurse_lst(maillon, toggle, dir, 0);
	maillon = maillon->next;
	ft_print_recurse(&maillon, toggle, dir);
}
