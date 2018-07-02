/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	print_l_hub(char *str, char *dir, t_flags *toggle)
{
	struct stat		items;
	char			*file;

	file = NULL;
	if (dir != NULL)
		file = dir;
	else
		file = str;
	stat(file, &items);
	if (!S_ISDIR(items.st_mode))
		print_l_f(str, NULL, toggle);
	else
		print_l(str, dir, toggle);
}

int		time_check(char *file1, char *file2, char *one, char *two)
{
	struct stat		mtime1;
	struct stat		mtime2;

	lstat(file1, &mtime1);
	lstat(file2, &mtime2);
	if (mtime1.st_mtime < mtime2.st_mtime)
	{
		return (-1);
	}
	if (mtime1.st_mtime == mtime2.st_mtime)
	{
		if (mtime1.st_mtimespec.tv_nsec < mtime2.st_mtimespec.tv_nsec)
			return (1);
		else if (mtime1.st_mtimespec.tv_nsec == mtime2.st_mtimespec.tv_nsec)
			return (ft_strcmp(two, one) < 0);
	}
	return (0);
}

int		time_compare(char *one, char *two, t_flags *toggle, char *dir)
{
	char			*file1;
	char			*file2;
	char			*tmp;
	int 			bol;

	(void)toggle;
	if (dir != NULL)
	{
		tmp = ft_strjoin(dir, "/");
		file1 = ft_strjoin(tmp, one);
		ft_memdel((void **)&tmp);
		tmp = ft_strjoin(dir, "/");
		file2 = ft_strjoin(tmp, two);
		ft_memdel((void **)&tmp);
	}
	else
	{
		file1 = ft_strdup(one);
		file2 = ft_strdup(two);
	}
	bol = time_check(file1, file2, one, two);
	ft_memdel((void **)&file1);
	ft_memdel((void **)&file2);
	return (bol);
}

void	suffix(char *path)
{
	acl_t			acl;
	acl_entry_t		dummy;

	if (path)
	{
		acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
		if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
		{
			acl_free(acl);
			acl = 0;
		}
		if (listxattr(path, 0, 0, 0) > 0)
			ft_putstr("@ ");
		else if (acl != 0)
			ft_putstr("+ ");
		else
			ft_putstr("  ");
	}
	else
		ft_putstr("  ");
}

void	print_spacing(t_flags *toggle, char *dir)
{
	if (dir != NULL)
		while (toggle->i-- > 0)
			ft_putstr(" ");
}
