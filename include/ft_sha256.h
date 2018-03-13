/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:22:51 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/24 01:31:13 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>

# define NAMES "ft_ssl: sha256:"
# define INITS_A 0x6A09E667
# define INITS_B 0xBB67AE85
# define INITS_C 0x3C6EF372
# define INITS_D 0xA54FF53A
# define INITS_E 0x510E527F
# define INITS_F 0x9B05688C
# define INITS_G 0x1F83D9AB
# define INITS_H 0x5BE0CD19
# define DBL_INT_ADD(a,b,c) if (a > 0xffffffff - (c)) ++b; a += c;
# define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
# define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))
# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
# define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
# define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
# define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

typedef struct	s_sha256flag
{
	bool	in;
	bool	quiet;
	bool	reverse;
	bool	string;
	bool	file;
}				t_sha256flag;

typedef struct	s_sha256parts
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
}				t_sha256parts;

typedef struct	s_main_sha256
{
	t_sha256flag		flag;
	int					input_len;
	char				*message;
	uint8_t				data[64];
	int					data_len;
	unsigned long long	bitlen;
	char				*filename;
	t_sha256parts		part;
}				t_sha256;

extern int		g_shak[64];

void			ft_sha256(int argc, char **argv, bool cbc_mode);
t_sha256		*ft_sha256parse(int argc, char **argv, bool *last);
char			*ft_sha256get_message(t_sha256 *main, int argc, char **argv);
int				ft_isfile(const char *name);
char			*ft_sha256get_mff(char *filename, t_sha256 *main);
char			*ft_sha256read_file(int fd, t_sha256 *main);
void			ft_sha256_algo_wrap(t_sha256 *main);
uint8_t			*ft_sha256get_bits(t_sha256 *main, int *new_len);
void			ft_sha256_algo(t_sha256 *main, int new_len, uint8_t *msg);
void			ft_sha256_algo_main(t_sha256 *main, uint32_t *word);
void			ft_sha256assign_workers(uint32_t worker[], t_sha256 *main);
void			ft_sha256assign_states(uint32_t worker[], t_sha256 *main);
void			ft_sha256print_hash(uint8_t hash[]);
void			ft_sha256reverse_hash(t_sha256 *main, uint8_t hash[]);
void			ft_sha256get_m(uint32_t m[], uint8_t data[]);
void			ft_sha256init_parts(t_sha256 *main);
void			ft_sha256init_parts(t_sha256 *main);
int				ft_sha256handle_file(t_sha256 *main, char *filename, bool *f);
int				ft_sha256handle_string(t_sha256 *main);
int				ft_sha256handle_input(t_sha256 *main);
void			ft_sha256algo_final_helper(t_sha256 *main);
void			ft_sha256print_output(t_sha256 *main, uint8_t hash[]);

#endif
