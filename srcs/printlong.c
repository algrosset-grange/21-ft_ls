/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static void	print_xattr(t_flags *toggle, struct stat timer)
{
	char	*mtime;

	mtime = ctime(&timer.st_mtime);
	toggle->i = 3;
	while (++toggle->i < 11)
		write(1, &mtime[toggle->i], 1);
	if (time(NULL) - timer.st_mtimespec.tv_sec >= 15724800)
	{
		toggle->i = 19;
		ft_putchar(' ');
		while (++toggle->i < 24)
			write(1, &mtime[toggle->i], 1);
	}
	else
	{
		toggle->i = 10;
		while (++toggle->i < 16)
			write(1, &mtime[toggle->i], 1);
	}
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

void		print_date_name(t_flags *toggle, char *str,
	struct stat timer, char *file)
{
	char			buf[1024];
	ssize_t			len;
	char			*temp;
	char			*prnt;

	temp = ft_lltoa(timer.st_size);
	ft_putstr(temp);
	ft_putchar(' ');
	ft_memdel((void **)&temp);
	print_xattr(toggle, timer);
	if ((len = readlink(file, buf, sizeof(buf) - 1)) != -1)
	{
		buf[len] = '\0';
		temp = ft_strjoin(str, " -> ");
		prnt = ft_strjoin(temp, buf);
		ft_memdel((void **)&temp);
		ft_putchar(' ');
		ft_putendl(prnt);
		ft_memdel((void **)&prnt);
	}
	else
	{
		ft_putchar(' ');
		ft_putendl(str);
	}
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
	ft_putchar(' ');
	if ((toggle->i = (toggle->size - ft_numullen(items.st_size))) > 0)
		print_spacing(toggle, dir);
	print_date_name(toggle, str, items, file);
	ft_memdel((void **)&file);
}
