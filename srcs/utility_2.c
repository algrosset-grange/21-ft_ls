/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static void	ft_put_ls_error(char *str)
{
	ft_putstr("ft_ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
}

static void	ft_print_l_file(char *str, char *way, t_flags *toggle)
{
	t_list	*list;

	list = NULL;
	ft_lstaddend(&list, ft_lstnew(str,
		sizeof((void *)str) * ft_strlen(str)));
	print_long_lst(&list, toggle, way);
	ft_lstdel(&list, &ft_lstdelcontent);
	ft_memdel((void **)&list);
}

static char	*make_file(char *str, char *way)
{
	char	*file;
	char	*tmp;

	if (way != NULL && ft_strcmp(str, way))
	{
		tmp = ft_strjoin(way, "/");
		file = ft_strjoin(tmp, str);
		ft_memdel((void **)&tmp);
	}
	else
		file = ft_strdup(str);
	return (file);
}

int			item_amount_lst(char *str, char *way, t_flags *toggle)
{
	DIR				*dir;
	struct stat		items;
	char			*file;

	file = make_file(str, way);
	dir = opendir(file);
	if (!stat(file, &items) && !S_ISDIR(items.st_mode))
	{
		if (toggle != NULL && toggle->l == 1)
			ft_print_l_file(str, way, toggle);
		else
			ft_putendl(str);
		return (1);
	}
	else if (dir == NULL)
	{
		ft_put_ls_error(str);
		ft_memdel((void **)&file);
		return (2);
	}
	ft_memdel((void **)&file);
	closedir(dir);
	return (0);
}
