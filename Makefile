# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njaros <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:17:57 by njaros            #+#    #+#              #
#    Updated: 2022/04/02 14:52:22 by njaros           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

## LES INCONTOURNABLES ##

NAME = libunit.a
CC = gcc
FLAGS = -Werror -Wextra -Wall

## LES CHEMINS ##

PATH_SRCS = src
PATH_OBJS = obj
PATH_INCLUDES = includes

## LES CHEMINS DES LIBRAIRIES ##

LIB = lib/libft/libft.a

## LES SOURCES, OBJETS et INCLUDES ##

LST_SRCS =	libunit_utils1.c \
			error_handler.c
LST_OBJS = ${LST_SRCS:.c=.o}
LST_INCLUDES = libunit.h
SRC = $(addprefix ${PATH_SRCS}/,${LST_SRCS})
OBJS = $(addprefix ${PATH_OBJS}/,${LST_OBJS})
INCLUDES = $(addprefix ${PATH_INCLUDES}/,${LST_INCLUDES})

## LES REGLES DE COMPILATION DU PROGRAMME ##

all :				${LIB} ${NAME}

${NAME} :			${OBJS}
					ar rcs ${NAME} ${OBJS}

${PATH_OBJS}/%.o:	${PATH_SRCS}/%.c ${INCLUDES} Makefile | ${PATH_OBJS}
					${CC} ${FLAGS} -c $< -o $@ -I ${PATH_INCLUDES}

${PATH_OBJS}:
					mkdir obj

## LES REGLES DE COMPILATION DES LIBRAIRIES ##

${LIB}:
					make -C ./lib/libft

## LES REGLES DE SUPPRESSION ET RE ##

clean:
					make clean -C ./lib/libft
					rm -rf obj

fclean:				clean
					make fclean -C ./lib/libft
					rm -f ${NAME}

re:					fclean all

## LES REGLES POUR LANCEMENTS DES TESTS ##



## LE TRUC ##

.PHONY: all re clean fclean

## FIN ##