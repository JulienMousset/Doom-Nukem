# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmousset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 16:43:26 by jmousset          #+#    #+#              #
#    Updated: 2019/12/11 21:21:27 by pasosa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

HDR = libft.h

SRCS = ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memccpy.c\
	   ft_memmove.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strlen.c\
	   ft_strdup.c\
	   ft_strcpy.c\
	   ft_strncpy.c\
	   ft_strcat.c\
	   ft_strncat.c\
	   ft_strlcat.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strstr.c\
	   ft_strnstr.c\
	   ft_strcmp.c\
	   ft_strncmp.c\
	   ft_atoi.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_memalloc.c\
	   ft_memdel.c\
	   ft_strnew.c\
	   ft_strdel.c\
	   ft_strclr.c\
	   ft_striter.c\
	   ft_striteri.c\
	   ft_strmap.c\
	   ft_strmapi.c\
	   ft_strequ.c\
	   ft_strnequ.c\
	   ft_strsub.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_strsplit.c\
	   ft_itoa.c\
	   ft_putchar.c\
	   ft_putstr.c\
	   ft_putendl.c\
	   ft_putnbr.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_lstnew.c\
	   ft_lstdelone.c\
	   ft_lstdel.c\
	   ft_lstadd.c\
	   ft_lstiter.c\
	   ft_lstmap.c\
	   ft_swap.c\
	   ft_range.c\
	   ft_strlcpy.c\
	   ft_str_is_lowercase.c\
	   ft_str_is_uppercase.c\
	   get_next_line.c\
	   detorad.c\
	   ft_print_tab.c\
	   ft_print_array.c\
	   end.c\
	   per.c\
	   rgb_to_int.c\
	   ft_swap_double.c\
	   ft_islower.c\
	   ft_tabdel.c\
	   ft_arraydel.c

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

-include $(DEPS)

./%.o : ./%.c makefile
	@gcc $(FLAGS) -I -MMD -MP -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(DEPS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
