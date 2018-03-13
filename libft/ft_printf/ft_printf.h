/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:46:58 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/28 19:22:34 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>
# include <wchar.h>

# define FORMAT_FLAGS *last_flag == ' ' FFG1
# define FFG1 || *last_flag == '#' FFG2
# define FFG2 || *last_flag == '0' || *last_flag == '-' FFG3
# define FFG3 || *last_flag == '+'

# define WIDTH_FLAGS (((*last_width >= '0' && *last_width <= '9')))

# define PRECISION_FLAGS (((*last_precision >= '0'PFG2
# define PFG2 && *last_precision <= '9') PFG1
# define PFG1 || (*last_precision == '+') || (*last_precision == '-')))

# define LENGTH_FLAGS (*last_length == 'l' LFG1
# define LFG1 || *last_length == 'h' || LFG2
# define LFG2 *last_length == 'j' || *last_length == 'z')

typedef union		u_value
{
	char			c;
	char			*str;
	intmax_t		sint;
	uintmax_t		uint;
	void			*ptr;
}					t_value;

typedef struct		s_flags
{
	bool			left_align;
	bool			zero;
	bool			alt_mode;
	bool			force_sign;
	bool			space;
}					t_flags;

typedef struct		s_arg
{
	int				width;
	int				precision;
	int				fd_output;
	char			*length;
	char			sp;
	char			sign;
	int				l;
	t_value			val;
	t_flags			flag;
}					t_arg;

typedef char* (*t_func)(t_arg*, va_list*);

/*
** Utility funcs
*/

t_arg				*ft_argnew(int	fd_output);
void				ft_argdelete(t_arg *args);
void				add_length_l(t_arg *args);
char				*ft_get_prefix(t_arg *args);
void				free_num(char **n, char **z, char **s, char **w);
t_flags				*get_flags(t_arg *args);
char				*ft_wstr_helper(char *res, t_arg *args);
char				*get_precision_str(t_arg *args);
char				*get_width_str(t_arg *args);

/*
** Conversion and typecasting if needed
*/

void				conversion_sint(t_arg *args, va_list *ap);
void				conversion_uint(t_arg *args, va_list *ap);
/*
** Handler funcs
*/
char				*ft_get_char(t_arg *args, va_list *ap);
char				*ft_get_str(t_arg *args, va_list *ap);
char				*ft_get_octal(t_arg *args, va_list *ap);
char				*ft_get_hex(t_arg *args, va_list *ap);
char				*ft_hex_wrapper(t_arg *args, va_list *ap);
char				*ft_get_addr(t_arg *args, va_list *ap);
char				*ft_get_number2(t_arg *args, va_list *ap);
char				*ft_get_unumber2(t_arg *args, va_list *ap);
char				*ft_get_mybinary(t_arg *args, va_list *ap);
char				*ft_get_wchar(t_arg *args, va_list *ap);
char				*ft_get_wstr(t_arg *args, va_list *ap);
/*
** Dispatch table
*/
t_func				get_func(char c);
/*
** Main logic
*/
int					ft_printf(char *format, ...);
int					parse_exec(char **format, va_list *ap, int fd_output);
int					ft_logic(va_list *ap, t_arg *args);
char				*ft_get_value(t_arg *args, va_list *ap);
/*
** Parse the argument command
*/
void				parse_flags(char **format, t_arg *args);
void				parse_width(char **format, t_arg *args, va_list *ap);
void				parse_precision(char **format, t_arg *args, va_list *ap);
void				parse_length(char **format, t_arg *args);
void				parse_specifier(char **format, t_arg *args);

#endif
