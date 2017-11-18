# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 23:38:02 by mikim             #+#    #+#              #
#    Updated: 2017/11/14 22:09:56 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	  parse_handler.c\
	  check_handler.c\
	  diff_handler.c\
	  put_handler.c\
	  fill_handler.c\
	  mlx_handler.c\
	  draw_handler.c

OBJ = $(SRC:.c=.o)

SRCDIR = srcs
OBJDIR = objs
LIBDIR = libs/libft
MLXDIR = libs/mlx
FRAMEWORK = -framework OpenGL -framework Appkit

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
LIBS = -L $(LIBDIR) -lft -L $(MLXDIR) -lmlx $(FRAMEWORK)
HEADER = -I includes -I $(LIBDIR)/includes -I $(MLXDIR)

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

NAME = filler

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBDIR)
	@make -C $(MLXDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "\x1B[32;1m[filler - 모래반지 빵야빵야!]\x1B[0m"

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean
	@make -C $(MLXDIR) clean
	@echo "\x1B[35;1m[filler - clean]\x1B[0m"

fclean:
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -f filler.trace
	@make -C $(LIBDIR) fclean
	@make -C $(MLXDIR) clean
	@echo "\x1B[31m[filler - fclean]\x1B[0m"

re: fclean all
