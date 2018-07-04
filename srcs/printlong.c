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

void		print_size_device(struct stat items, t_flags *toggle, char *dir)
{
	char	*temp;

	if (!S_ISCHR(items.st_mode) && !S_ISBLK(items.st_mode))
	{
		if ((toggle->i = (toggle->size - ft_numullen(items.st_size) + 1)) > 0)
			print_spacing(toggle, dir);
		temp = ft_lltoa(items.st_size);
		ft_putstr(temp);
	}
	else
	{
		if ((toggle->i =
				(toggle->major - ft_numullen(major(items.st_rdev)) + 1)) > 0)
			print_spacing(toggle, dir);
		temp = ft_lltoa(major(items.st_rdev));
		ft_putstr(temp);
		ft_memdel((void **)&temp);
		ft_putstr(",");
		if ((toggle->i =
				(toggle->minor - ft_numullen(minor(items.st_rdev)) + 3)) > 0)
			print_spacing(toggle, dir);
		temp = ft_lltoa(minor(items.st_rdev));
		ft_putstr(temp);
	}
	ft_memdel((void **)&temp);
}

void		print_date_name(t_flags *toggle, char *str,
	struct stat timer, char *file)
{
	char			buf[1024];
	ssize_t			len;
	char			*temp;
	char			*prnt;

	ft_putchar(' ');
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
