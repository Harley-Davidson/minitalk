/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:26:16 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/06/10 13:26:17 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libft/ft_printf.h"
# include <wchar.h>

typedef struct s_minitalk
{
	char	pid_ar[20];
	int		pid_size;
	int		is_pid;
	long	client_pid;
	char	ch;
	int		bit;
}	t_minitalk;

/*
** Macros
*/

# define WAIT_TIME 100

#endif
