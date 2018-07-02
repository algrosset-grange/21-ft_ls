/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2018/07/02 02:12:28 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	help_ls(void)
{
	ft_putstr("Usage: ft_ls [OPTION]... [FILE]...\n");
	ft_putstr("List information about the FILES \
(the current directory by default).\n");
	ft_putstr("Mandatory arguments to long options are \
mandatory for short options too.\n");
	ft_putstr("-a,             do not ignore entries starting with .\n");
	ft_putstr("-l              use a long listing format\n");
	ft_putstr("-r,             reverse order while sorting\n");
	ft_putstr("-R,             list subdirectories recursively\n");
	ft_putstr("-t              sort by modification time, newest first\n");
	ft_putstr("-1              list one file per line\n");
	ft_putstr("--help          display this help and exit\n");
}

int		main(int ac, char **av)
{
	if (ac == 1)
		parse_single_lst("", ".");
	else if (ac == 2)
	{
		if (!(ft_strcmp(av[1], "--help")))
			help_ls();
		else if (av[1][0] == '-' && av[1][1] != '\0')
			parse_single_lst(av[1], ".");
		else
			parse_single_lst("", av[1]);
	}
	else
		parse_multi_lst(av);
	sleep(5);
	return (0);
}
