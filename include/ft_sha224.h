/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:22:51 by jtahirov          #+#    #+#             */
/*   Updated: 2018/02/01 22:05:45 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA224_H
# define FT_SHA224_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>

# define NAMES_224 "ft_ssl: sha224:"
# define INIT_SHA224_A 0xc1059ed8
# define INIT_SHA224_B 0x367cd507
# define INIT_SHA224_C 0x3070dd17
# define INIT_SHA224_D 0xf70e5939
# define INIT_SHA224_E 0xffc00b31
# define INIT_SHA224_F 0x68581511
# define INIT_SHA224_G 0x64f98fa7
# define INIT_SHA224_H 0xbefa4fa4
# define DBL_INT_ADD(a,b,c) if (a > 0xffffffff - (c)) ++b; a += c;
# define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
# define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))
# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
# define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
# define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
# define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

typedef struct	s_sha224flag
{
	bool	in;
	bool	quiet;
	bool	reverse;
	bool	string;
	bool	file;
}				t_sha224flag;

typedef struct	s_sha224parts
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
}				t_sha224parts;

typedef struct	s_main_sha224
{
	t_sha224flag		flag;
	int					input_len;
	char				*message;
	uint8_t				data[64];
	int					data_len;
	unsigned long long	bitlen;
	char				*filename;
	t_sha224parts		part;
}				t_sha224;

extern int		g_sha224k[64];

void			ft_sha224(int argc, char **argv, bool cbc_mode);
t_sha224		*ft_sha224parse(int argc, char **argv, bool *last);
char			*ft_sha224get_message(t_sha224 *main, int argc, char **argv);
int				ft_isfile(const char *name);
char			*ft_sha224get_mff(char *filename, t_sha224 *main);
char			*ft_sha224read_file(int fd, t_sha224 *main);
void			ft_sha224_algo_wrap(t_sha224 *main);
uint8_t			*ft_sha224get_bits(t_sha224 *main, int *new_len);
void			ft_sha224_algo(t_sha224 *main, int new_len, uint8_t *msg);
void			ft_sha224_algo_main(t_sha224 *main, uint32_t *word);
void			ft_sha224assign_workers(uint32_t worker[], t_sha224 *main);
void			ft_sha224assign_states(uint32_t worker[], t_sha224 *main);
void			ft_sha224print_hash(uint8_t hash[]);
void			ft_sha224reverse_hash(t_sha224 *main, uint8_t hash[]);
void			ft_sha224get_m(uint32_t m[], uint8_t data[]);
void			ft_sha224init_parts(t_sha224 *main);
void			ft_sha224init_parts(t_sha224 *main);
int				ft_sha224handle_file(t_sha224 *main, char *filename, bool *f);
int				ft_sha224handle_string(t_sha224 *main);
int				ft_sha224handle_input(t_sha224 *main);
void			ft_sha224algo_final_helper(t_sha224 *main);
void			ft_sha224print_output(t_sha224 *main, uint8_t hash[]);

#endif
