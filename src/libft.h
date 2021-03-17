/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:12:02 by ielmoudn          #+#    #+#             */
/*   Updated: 2021/03/17 17:07:36 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_free
{
	void			*address;
	struct s_free	*next;
}					t_free;


typedef struct				s_tags
{
	int						flags;
	int						f_w;
	int						precision;
	int						l_m;
	int						c_c;
}							t_tags;

typedef struct				s_ilist
{
	int						val;
	struct s_ilist			*next;
}							t_ilist;

typedef struct				s_db
{
	size_t					m:52;
	unsigned int			p:11;
	unsigned int			s:1;

}							t_db;

typedef union				u_double
{
	double					f;
	t_db					d;
}							t_double;

typedef struct				s_ld
{
	size_t					m:63;
	unsigned int			q:1;
	unsigned int			p:15;
	unsigned int			s:1;
}							t_ld;

typedef union				u_long_double
{
	long double				l;
	t_ld					ld;

}							t_long_double;

typedef union				u_d
{
	int						d;
	long int				ld;
	long long int			lld;
	short int				hd;
	char					hhd;
}							t_d;

typedef union				u_u
{
	unsigned int			u;
	long unsigned int		lu;
	long long unsigned int	llu;
	short unsigned int		hu;
	unsigned char			hhu;
}							t_u;

typedef void				(*t_f)(t_tags, va_list);



int					ft_islower(int c);
int					ft_atoi(const char *str);
int					ft_isupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar_fd(char c, int fd);
int					ft_putchar(int c);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putnbr(int nb);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putstr(const char *str);
char				*ft_strcat(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *dest, const char *src, size_t nb);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strchr(const char *s, int c);
char				*ft_strrev(char *str);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *b, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
char				*ft_itoa(int nbr);
char				**ft_strsplit(char const *s, char c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
unsigned int		ft_strcntfirstchar(char *str, const char *charset);
unsigned int		ft_strcntlastchar(char *str, const char *charset);
char				*ft_strtrim(char const *s);
char				**ft_strsplitchrset(char *str, const char *charset);
void				*ft_dup(void const *content, size_t content_size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstaddend(t_list **alst, t_list *new);
int					ft_atoi_base(char *str, char *base);
char				*ft_itoa_base(int value, char *base);




int							number_lenth(t_tags tag,
		long long unsigned int nbr, int b);
void						print_nbr(long long unsigned int nbr,
		char *base, unsigned int b);
int							ft_printf(char *d, ...);
void						ft_printf_rep(char *d, ...);
char						*ft_get_space(int l);
char						*ft_get_zeros(int l);
t_f							ft_get_functions(int i);
int							ft_in(char c, char *str);
void						ft_printf_u1(t_u var, t_tags tag,
		int b, char *base);
void						ft_printf_c(t_tags tag, va_list l);
void						ft_printf_s(t_tags tag, va_list l);
void						ft_printf_p(t_tags tag, va_list l);
void						ft_printf_d(t_tags tag, va_list l);
void						ft_printf_u(t_tags tag, va_list l);
void						ft_printf_f(t_tags tag, va_list l);
void						ft_printf_pr(t_tags tag, va_list l);
t_ilist						*ft_ilistnew(int i);
void						ft_printf_base(t_tags tag, va_list l);
int							ft_in(char c, char *str);
void						ft_sep1(int *i, int *j, char *d);
t_ilist						*ft_sep(char *d, int *i);
char						**getall(char *d, t_ilist *p, int i);
void						ft_del_ilist(t_ilist *ilist);
char						**get_separate(char *d, int *i);
int							ft_in1(char c, char *str);
int							get_flags(char *out, int *j);
int							get_f_w(char *out, int *j);
int							get_precision(char *out, int *j);
int							get_l_m(char *out, int *j);
int							get_c_c(char *out, int *j);
void						get_tags(char **out, t_tags **tags);
void						ft_multiply(size_t **k, int l);
void						ft_cp(size_t *c, size_t **b, int l);
void						bit_shift_right(size_t **t, int shift, int o);
void						bit_shift_left(size_t **t, int l, int o);
void						bit_shift(size_t **t, int shift, int l);
int							ver_carry(size_t *carry, int l);
char						*ft_int(size_t *table_float, int dim, int carry,
		t_tags tag);
size_t						*new_table(int l);
void						ft_printf_td(t_tags tag, va_list l, char *str);
void						ft_printf_ts(t_tags tag, va_list l, char *str);
void						ft_add(size_t **a, size_t **b, int l);
void						ft_add_int(size_t **a, size_t *b, unsigned int l);
void						bit_shift_right(size_t **t, int shift, int o);
void						bit_shift_left(size_t **t, int l, int o);
void						bit_shift(size_t **t, int shift, int l);
size_t						*new_table(int l);
int							regulate_fl(char **part_fl, size_t k,
		int precision);
int							ft_fl(t_tags tag, size_t *table_float,
		char **part_fl, int dim);
void						ft_display_float1(int s, t_tags tag,
		char *part_int, char *part_fl);
void						ft_display_float(t_tags tag,
		size_t *table_float, int dim, int s);
void						ft_put_nan(t_tags tag, int s, size_t m);
#endif
