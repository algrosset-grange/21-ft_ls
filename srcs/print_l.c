/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static void	set_file(char *str, char *dir, char **file)
{
	char	*tmp;

	tmp = NULL;
	if (dir != NULL)
	{
		tmp = ft_strjoin(dir, "/");
		*file = ft_strjoin(tmp, str);
	}
	else
		*file = str;
	ft_memdel((void **)&tmp);
}

static void	print_l_p2(struct stat items, char *file, t_flags *toggle,
	char *dir)
{
	char	*bits;
	char	*temp;

	bits = perms(items.st_mode);
	ft_putstr(bits);
	suffix(file);
	if ((toggle->i = (toggle->nlinks - ft_numlen(items.st_nlink))) > 0)
		print_spacing(toggle, dir);
	temp = ft_itoa(items.st_nlink);
	ft_putstr(temp);
	ft_putchar(' ');
	ft_memdel((void **)&temp);
}

void		print_l(char *str, char *dir, t_flags *toggle)
{
	struct stat		items;
	struct passwd	user;
	struct group	group;
	char			*file;

	file = NULL;
	set_file(str, dir, &file);
	stat(file, &items);
	user = *getpwuid(items.st_uid);
	group = *getgrgid(items.st_gid);
	print_l_p2(items, file, toggle, dir);
	if ((toggle->i = (toggle->uid - ft_strlen(user.pw_name))) > 0)
		print_spacing(toggle, dir);
	ft_putstr(user.pw_name);
	ft_putchar(' ');
	if ((toggle->i = (toggle->gid - ft_strlen(group.gr_name))) > 0)
		print_spacing(toggle, dir);
	ft_putstr(group.gr_name);
	print_size_device(items, toggle, dir);
	print_date_name(toggle, str, items, file);
	ft_memdel((void **)&file);
}
