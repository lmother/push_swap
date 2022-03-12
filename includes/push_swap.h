#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int				value;
	int				order;
	int				flag;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stacks
{
	int		size_a;
	int		size_b;
	int		flag;
	int		mid;
	int		val;
	int		max;
	t_stack	*head_a;
	t_stack	*tail_a;
	t_stack	*head_b;
	t_stack	*tail_b;
}				t_stacks;

void		ft_qsort_arr(int *arr, int l, int r);
int			ft_check_sort(int *arr, int size);
int			ft_check_strs(char **str);
int			ft_check_str_2(char *str, int j, int nbr);
t_stacks	ft_check_stack(int agrc, char **str);
void		ft_print_err(void);
long int	ft_atoi_long(const char *str);
int			ft_strslen(char **strs);
void		ft_free_strs(char **str);
void		ft_add_stacks(t_stacks *list, int val, int order);
t_stacks	ft_create_list(void);
void		ft_del_stack(t_stacks *list);
void		ft_print_err(void);
t_stacks	ft_init_stacks(int *arr, int size);
int			*ft_copy_arr(int *arr, int size);
void		ft_check_double(int *arr, int len);
int			ft_check_sort(int *arr, int size);
void		ft_init_array(int *arr, char **str, int len);
void		ft_pb(t_stacks *stacks, int flag);
void		ft_pa(t_stacks *stacks, int flag);
void		ft_sa(t_stacks *stacks, int flag);
void		ft_sb(t_stacks *stacks, int flag);
void		ft_ra(t_stacks *stacks, int flag);
void		ft_rb(t_stacks *stacks, int flag);
void		ft_rra(t_stacks *stacks, int flag);
void		ft_rrb(t_stacks *stacks, int flag);
void		ft_rrr(t_stacks *stacks, int flag);
void		ft_rr(t_stacks *stacks, int flag);
void		ft_ss(t_stacks *stacks, int flag);
void		ft_sort_3_digit(t_stacks *stacks);
void		ft_global_sort(t_stacks *stacks);
void		ft_sort(t_stacks *stacks);
int			ft_max_val(t_stack *stack);
int			ft_min(t_stack *stack);
int			ft_check_sort_a(t_stacks *stacks);
void		ft_first_action(t_stacks *stacks);
void		ft_sort_b_wile_not_empty(t_stacks *stacks);
void		ft_check_flag(t_stacks *stacks);
void		ft_if_flag_zero(t_stacks *stacks, int isort);
void		ft_beck_to_head(t_stacks *stacks);
void		ft_sort(t_stacks *stacks);

//checker:

int			get_next_line(int fd, char **line);
char		*ft_cstrcpy(char *dest, const char *src);
char		*ft_cstrdup(char *str);
void		ft_del_stack_b(t_stacks *list);
char		*ft_cstrchr(const char *str, int c);
char		*ft_cstrjoin(char *dest, char *src);
size_t		ft_cstrlen(const char *str);
t_stacks	ft_check_stack_checker(int agrc, char **str);
#endif
