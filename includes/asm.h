/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:53:02 by alecott           #+#    #+#             */
/*   Updated: 2018/05/23 09:40:06 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
#include "../libft/libft.h"

typedef struct		s_chain
{
	unsigned int	nb_col;
	unsigned int	nb_lines;
	char			*category;
	int				nb_op_tab;
	char			*content;
	struct s_chain	*next;
}					t_chain;

typedef struct		s_op
{
	char			*str;
	int				nb_args;
	int				args[3];
	int				opcode;
	int				nb_cycles;
	char			*name;
	int				ocp;
	int				label_size;
}					t_op;

extern t_op			op_tab[];

int		main(int argc, char **argv);
void	ft_pass_comment(char *str, int *i);
void	ft_parsing(char *str, header_t *header);
void	ft_is_an_error(char *str, int i);
t_chain	*ft_get_in_chain(char *str, int j);
void	ft_verify_label(char *str, int j, t_chain *block);
t_op	*ft_get_op_tab(void);
t_op	*ft_search_op(char *str);
t_op	*ft_get_op(int opcode);

#endif
