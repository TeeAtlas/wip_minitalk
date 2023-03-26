# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 12:01:14 by taboterm          #+#    #+#              #
#    Updated: 2023/03/26 19:10:46 by taboterm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# target input - dependencies
NAME_CLIENT := client
NAME_SERVER := server

# directory
IDIR = inc

# headers
DEPS := $(wildcard $(IDIR)/*.h)

# source id
# two seperate sources because we are compiling two seperate programs
CFILES_C = $(wildcard *client*.c)
CFILES_S = $(wildcard *server*.c)

# create object files from corresponding c files
OBJ_C = $(CFILES_C:%.c=%.o)
OBJ_S = $(CFILES_S:%.c=%.o)

# compiling info
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

# including libft
LIBFT = libft/libft.a

# make desired targets
all: $(NAME_CLIENT) $(NAME_SERVER)

# $@ says to put the output of the compilation 
# in the file named on the left side of the :
# !! STILL NOT SURE WHAT $^ MEANS
$(%.o): $(%.c) $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $^

# make target executable 
$(NAME_CLIENT): $(OBJ_C) 
	make -C ./libft
	$(CC) -o $@ $(OBJ_C)

$(NAME_SERVER): $(OBJ_S)
	make -C ./libft
	$(CC) -o $@ $(OBJ_S)

# bonus: all

clean:
	make -C ./libft
	rm -rf $(OBJ_C) $(OBJ_S)

fclean: clean
	make -C ./libft
	rm -rf $(OBJ_C) $(OBJ_S) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

#.PHONY: clean uninstall reinstall
.PHONY: all clean fclean re
