#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libft/ft_printf.h"

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