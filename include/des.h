/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:01:18 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/03 19:43:07 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DES_H
# define DES_H

# include "../libft/libft.h"
# include <stdbool.h>
# include "../include/ft_ssl.h"

# define TIMES(x) (x == 0 || x == 1 || x == 8 || x == 15 ? 1 : 2)
# define CAPTURE_BIT(x, y) (((0x01 << y) & x) != 0 ? 1 : 0)
# define S_ROW(x) (CAPTURE_BIT(x, 5) << 1 | CAPTURE_BIT(x, 0))
# define S_COL(x) ((x & 0x1E) >> 1)

# define H1(x) (x >= 'a' && x <= 'f')
# define H2(x) (x >= 'A' && x <= 'F')
# define H3(x) (x >= '0' && x <= '9')
# define HEXRANGE(x) ((H1(x) || H2(x) || H3(x)) ? 1 : 0)

typedef	struct		s_dflag
{
	bool	encode;
	bool	decode;
	bool	key;
	bool	input;
	bool	output;
	bool	base64;
	bool	nopad;
	bool	cbc_mode;
	bool	iv;
}					t_dflag;

typedef struct		s_dmain
{
	int				len;
	char			*input_filename;
	char			*output_filename;
	unsigned long	key;
	unsigned long	iv;
	unsigned long	next_iv;
	unsigned long	left_message;
	unsigned long	right_message;
	t_dflag			flag;
	int				init_k;
	char			*command;
}					t_dinput;

typedef unsigned long	t_long;
typedef unsigned char	t_char;

extern int				g_perm1[56];
extern int				g_perm2[48];
extern int				g_ip[64];
extern int				g_selection[48];
extern int				g_sboxes[8][4][16];
extern int				g_p[32];
extern int				g_ip2[64];

t_dinput			*create_dstruct(bool cbc);
void				ft_parse_des_flags(t_dinput *input, int argc, char **argv);
unsigned long		ft_des_getkey(unsigned char *rawkey);
int					ft_check_bit(unsigned long block, int num, int s, bool f);
unsigned long		permutation(int order[], int out, void *data, bool flag);
char				*ft_des_hencode(int fd_input, t_dinput *input);
unsigned long		ft_des_subkey(t_dinput *input);
unsigned long		ft_get_subkey(t_dinput *input, bool rev);
unsigned long		ft_get_revsubkey(t_dinput *input);
unsigned char		*ft_des_getmessage(int fd_input, t_dinput *input);
unsigned long		ft_des_sboxes(unsigned long	afterxor);
t_binput			*create_bstruct(t_dinput *input);
unsigned int		ft_des_get_sbit6(unsigned long input);
int					ft_get_length(t_dinput *input);
unsigned long		ft_des_encript(t_dinput *input);
void				ft_des_to_base64(t_dinput *input, char **res);
void				ft_des_get_key_stdin(t_dinput *input);
char				*ft_remove_pad(unsigned char *message);
char				*ft_des_cbc_encode(int fd_input, t_dinput *input);
void				ft_des_getiv(unsigned char *rawiv, t_dinput *input);
unsigned long		ft_get_block(unsigned char *message);
unsigned long		ft_des_algo(t_dinput *input);
char				*ft_des_pad(char *message, t_dinput *input);
void				ft_parse_des_flags2(t_dinput *i, int *ac, char **f, int *c);

#endif
