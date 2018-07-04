/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		cmp_str(char *content1, char *content2, t_flags *toggle, char *dir)
{
	(void)dir;
	if ((toggle->r == 1 && ft_strcmp(content1, content2) < 0)
		|| (toggle->r == 0 && ft_strcmp(content1, content2) > 0))
		return (1);
	return (0);
}

void	ft_make_stat(struct stat *mtime, char *str, char *dir)
{
	char	*file;
	char	*tmp;

	file = NULL;
	if (dir != NULL)
	{
		tmp = ft_strjoin(dir, "/");
		file = ft_strjoin(tmp, str);
		ft_memdel((void **)&tmp);
	}
	else
		file = ft_strdup(str);
	lstat(file, mtime);
	ft_memdel((void **)&file);
}

int		cmp_time(char *content1, char *content2, t_flags *toggle, char *dir)
{
	struct stat		mtime1;
	struct stat		mtime2;

	ft_make_stat(&mtime1, content1, dir);
	ft_make_stat(&mtime2, content2, dir);
	if ((toggle->r == 0 && mtime1.st_mtime < mtime2.st_mtime)
			|| (toggle->r == 1 && mtime1.st_mtime > mtime2.st_mtime))
		return (1);
	else if (mtime1.st_mtime == mtime2.st_mtime
		&& cmp_str(content1, content2, toggle, dir))
		return (1);
	return (0);
}

int		cmp_file_dir_time(char *one, char *two, t_flags *toggle, char *dir)
{
	struct stat	item1;
	struct stat	item2;

	if (one && two &&
		!stat(one, &item1) &&
		!stat(two, &item2) &&
		((!S_ISDIR(item1.st_mode) && !S_ISDIR(item2.st_mode))
			|| (S_ISDIR(item1.st_mode) && S_ISDIR(item2.st_mode)))
		&& ((toggle->t == 1 && cmp_time(one, two, toggle, dir))
			|| cmp_str(one, two, toggle, dir)))
		return (1);
	return (0);
}

void	sort_lst(t_list **list, t_flags *toggle, char *dir,
	int (*cmp)(char *content1, char *content2, t_flags *toggle, char *dir))
{
	t_list *maillon;

	toggle->count = 1;
	while (toggle->count && (maillon = *list))
	{
		toggle->count = 0;
		while (maillon && maillon->next)
		{
			if (cmp((char *)(maillon->content),
				(char *)((maillon->next)->content), toggle, dir))
			{
				toggle->count = 1;
				ft_lstswap(&maillon);
			}
			maillon = maillon->next;
		}
	}
}
