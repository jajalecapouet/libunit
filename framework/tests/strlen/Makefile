# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:17:57 by njaros            #+#    #+#              #
#    Updated: 2022/04/02 15:59:32 by njaros           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

## LES INCONTOURNABLES ##

NAME = strlen_tester
CC = gcc
FLAGS = -Werror -Wextra -Wall

## LES CHEMINS ##

PATH_SRCS = .
PATH_OBJS = obj
PATH_INCLUDES = ../../../project_to_test/libft

## LES CHEMINS DES LIBRAIRIES ##

LIB = ../../../project_to_test/libft/libft.a

## LES SOURCES, OBJETS et INCLUDES ##

LST_SRCS =	00_launcher.c \
			01_basic_test.c \
			02_null_test.c \
			../main.c
LST_OBJS = ${LST_SRCS:.c=.o}
LST_INCLUDES = libft.h
SRC = $(addprefix ${PATH_SRCS}/,${LST_SRCS})
OBJS = $(addprefix ${PATH_OBJS}/,${LST_OBJS})
INCLUDES = $(addprefix ${PATH_INCLUDES}/,${LST_INCLUDES})

## LES REGLES DE COMPILATION DU PROGRAMME ##

all :				${LIB} ${NAME}

${NAME} :			${OBJS}
					${CC} ${FLAGS} ${OBJS} ${LIB} -o $@

${PATH_OBJS}/%.o:	${PATH_SRCS}/%.c ${INCLUDES} ${LIB} Makefile | ${PATH_OBJS}
					${CC} ${FLAGS} -c $< -o $@ -I ${PATH_INCLUDES}

${PATH_OBJS}:
					mkdir obj

## LES REGLES DE COMPILATION DES LIBRAIRIES ##

${LIB}:

## LES REGLES DE SUPPRESSION ET RE ##

clean:
					rm -rf obj

fclean:				clean
					rm ${NAME}

re:					fclean all

## LE TRUC ##

.PHONY: all re clean fclean

## FIN ##