/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 00:48:11 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/02 14:54:02 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../include/ft_ssl.h"

char			*g_table;

typedef struct	s_flag
{
	bool	encode;
	bool	decode;
	bool	input;
	bool	output;
}				t_bflag;

typedef struct	s_main
{
	int		len;
	char	*input_filename;
	char	*output_filename;
	t_bflag	flag;
}				t_binput;

void			check_argc(int argc);
t_binput		*create_struct(void);
void			ft_parse_base64_flags(t_binput *input, int argc, char **argv);
char			*ft_base64_hencode(int fd_input, t_binput *input);
char			*ft_base64_encode(char *message, t_binput *input);
char			*ft_base64_message(int fd_input, t_binput *input);
void			ft_get_base64chr(unsigned char **id, char **enc);
void			ft_get_chrbase64(unsigned char **id, char **enc);
char			*ft_base64_hdecode(int fd_input, t_binput *input);
char			*ft_base64_decode(char *message, t_binput *input);
unsigned char	ft_base_s(char x);
void			init_g_table(void);

#endif
