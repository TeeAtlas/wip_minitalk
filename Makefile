# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 12:01:14 by taboterm          #+#    #+#              #
#    Updated: 2023/03/29 13:47:28 by taboterm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# target input - dependencies
NAME_CLIENT = client
NAME_SERVER = server

# directory
# IDIR = inc

# source id
# two seperate sources because we are compiling two seperate programs
CFILES_C = client.c
CFILES_S = server.c

# create object files from corresponding c files
OBJ_C = $(CFILES_C:%.c=%.o)
OBJ_S = $(CFILES_S:%.c=%.o)

# compiling info
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g


# make desired targets
all: $(NAME_CLIENT) $(NAME_SERVER)

# $@ says to put the output of the compilation 
# in the file named on the left side of the :
# !! STILL NOT SURE WHAT $^ MEANS
$(%.o): $(%.c)
	$(CC) $(CFLAGS) -o $@ -c $^

# make target executable 
$(NAME_CLIENT): $(OBJ_C) 
	$(CC) -o $@ $(OBJ_C)

$(NAME_SERVER): $(OBJ_S)
	$(CC) -o $@ $(OBJ_S)

clean:
	rm -rf $(OBJ_C) $(OBJ_S)

fclean: clean
	rm -rf $(OBJ_C) $(OBJ_S) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all
