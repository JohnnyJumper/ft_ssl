/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 20:38:30 by jtahirov          #+#    #+#             */
/*   Updated: 2018/02/01 22:05:21 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include "base64.h"
# include "ft_md5.h"
# include "ft_sha256.h"
# include "ft_sha224.h"

typedef	void	(*t_prog)(int argc, char **argv, bool cbc_mode);

void		ft_ssl_help(int argc, char **argv, bool cbc_mode);
int			ft_openfile(char *filename, bool input);
void		ft_base64(int argc, char **argv, bool cbc_mode);
void		ft_des(int argc, char **argv, bool cbc_mode);
void		ft_des_cbc(int argc, char **argv);
void		init_progs(t_prog *progs);
t_prog		get_function(char *command, bool *cbc_mode);

#endif
