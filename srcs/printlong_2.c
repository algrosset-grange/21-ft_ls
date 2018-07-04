/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlong_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static void	print_l_f_p2(struct stat items, t_flags *toggle, struct passwd user,
		char *str)
{
	char			*temp;
	struct group	group;

	group = *getgrgid(items.st_gid);
	temp = ft_itoa(items.st_nlink);
	ft_putstr(temp);
	ft_putchar(' ');
	ft_memdel((void **)&temp);
	if ((toggle->i = (toggle->fuid - ft_strlen(user.pw_name))) > 0)
		print_spacing(toggle, str);
	ft_putstr(user.pw_name);
	ft_putstr("  ");
	if ((toggle->i = (toggle->fgid - ft_strlen(group.gr_name))) > 0)
		print_spacing(toggle, str);
	ft_putstr(group.gr_name);
	ft_putchar(' ');
	if ((toggle->i = (toggle->fsize - ft_numullen(items.st_size))) > 0)
		print_spacing(toggle, str);
}

void		print_l_f(char *str, char *file, t_flags *toggle)
{
	struct stat		items;
	struct passwd	user;
	char			*bits;

	lstat(str, &items);
	grab_format_file(str, toggle);
	bits = perms(items.st_mode);
	user = *getpwuid(items.st_uid);
	ft_putstr(bits);
	suffix(file);
	if ((toggle->i = (toggle->fnlinks - ft_numlen(items.st_nlink))) > 0)
		print_spacing(toggle, str);
	print_l_f_p2(items, toggle, user, str);
	ft_putstr(" ");
	print_size_device(items, toggle, ".");
	print_date_name(toggle, str, items, file);
}
