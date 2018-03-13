/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 00:45:59 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/24 01:20:32 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>

# define NAME "ft_ssl: md5:"
# define INIT_A 0x67452301
# define INIT_B 0xefcdab89
# define INIT_C 0x98badcfe
# define INIT_D 0x10325476
# define LEFTROTATE(x, c) ((x << c) | (x >> (32 - c)))

extern int g_s[64];
extern int g_k[64];

typedef unsigned int	t_uint;

typedef struct			s_md5flag
{
	bool	in;
	bool	quiet;
	bool	reverse;
	bool	string;
	bool	file;
}						t_md5flag;

typedef struct			s_md5parts
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
}						t_md5parts;

typedef struct			s_main_md5
{
	t_md5flag	flag;
	int			input_len;
	char		*message;
	char		*filename;
	int			digest_len;
	t_md5parts	part;
}						t_md5;

void					ft_md5(int argc, char **argv, bool cbc_mode);
t_md5					*ft_md5parse(int argc, char **argv, bool *last);
char					*ft_md5get_message(t_md5 *main, int argc, char **argv);
int						ft_isfile(const char *name);
char					*ft_md5get_mff(char *filename, t_md5 *main);
char					*ft_md5read_file(int fd, t_md5 *main);
void					ft_md5_algo_wrap(t_md5 *main);
uint8_t					*ft_md5get_bits(t_md5 *main, int *new_len);
void					ft_md5_algo(t_md5 *main, int new_len, uint8_t *msg);
void					ft_md5_algo_main(t_md5 *main, uint32_t *word);
void					ft_md5print_hash(uint32_t *parts);
void					ft_md5print_output(uint32_t *parts, t_md5 *main);
uint32_t				ft_md5f_function(t_md5 *main, uint32_t *g, uint32_t i);
uint32_t				ft_md5g_function(t_md5 *main, uint32_t *g, uint32_t i);
uint32_t				ft_md5h_function(t_md5 *main, uint32_t *g, uint32_t i);
uint32_t				ft_md5i_function(t_md5 *main, uint32_t *g, uint32_t i);
int						ft_md5handle_file(
						t_md5 *main, char *filename, bool *flag);
int						ft_md5handle_string(t_md5 *main);
int						ft_md5handle_input(t_md5 *main);
void					ft_usage(void);

#endif
