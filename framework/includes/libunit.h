/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:41:18 by njaros            #+#    #+#             */
/*   Updated: 2022/04/02 14:48:01 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft.h"

typedef struct s_test
{
	int		ret;
	char	*fonction;
	char	*test_name;
}	t_test;

// FONCTIONS QUI FONT LES TRUCS

t_test	*new_test(char *fonction_name, char	*test_name);
int		load_test(t_list **testlist, char *fonction_name, char *test_name, int(*f)(void));
void	my_swaggy_writer(char *a, char *b, char *c, int context);
int		check_success(t_test *test);
void	read_tests(t_list *lst);

// FONCTIONS QUI GERE LES ERREURS ET LES FREES

void	freelance(void *lst);
void	freezbi(void *alst);
void	err(void *to_free, void (*del)(void*), int context);

#endif