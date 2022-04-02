/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:37:01 by njaros            #+#    #+#             */
/*   Updated: 2022/04/02 13:14:03 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	freelance(void *lst)
{
	t_list	*to_free_lst;
	t_test	*to_free_test;

	to_free_lst = lst;
	to_free_test = to_free_lst->content;
	free(to_free_test->test_name);
	free(to_free_test->fonction);
	free(to_free_test);
	free(to_free_lst);
}

void	freezbi(void *alst)
{
	t_list	**to_free;
	to_free = alst;

	ft_lstclear(to_free, freelance);
}

void	err(void *to_free, void (*del)(void*), int context)
{
	if ((*del) && to_free)
		(*del)(to_free);
	if (context == 12)
		ft_putendl_fd("memory problem, generally not gud", 2);
	if (context == 11)
		ft_putendl_fd("no memory to fork(), or process max is reached", 2);
	exit(context);
}
