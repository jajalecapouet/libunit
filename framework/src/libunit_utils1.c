/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:36:07 by njaros            #+#    #+#             */
/*   Updated: 2022/04/02 14:50:24 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_test	*new_test(char *fonction_name, char	*test_name)
{
	char	*str_fonction;
	char	*str_test;
	t_test	*new;

	str_test = ft_strdup(test_name);
	if (!str_test)
		err(NULL, NULL, 12);
	str_fonction = ft_strdup(fonction_name);
	if (!str_fonction)
		err(str_test, free, 12);
	new = malloc(sizeof(t_test));
	if (!new)
	{
		free(str_fonction);
		err(str_test, free, 12);
	}
	new->test_name = str_test;
	new->ret = -2;
	return (new);
}

int	load_test(t_list **testlist, char *fonction_name, char *test_name, int(*f)(void))
{
	pid_t	p_fork;
	t_list	*new;
	t_test	*ptr;

	new = ft_lstnew(new_test(fonction_name, test_name));
	if (!new || !new->content)
		err(testlist, freezbi, 12);
	p_fork = fork();
	if (p_fork == -1)
		err(testlist, freezbi, 11);
	if (p_fork == 0)
		return ((*f)());
	ptr = new->content;
	wait(&(ptr->ret));
	ft_lstadd_back(testlist, new);
	return (1);
}

void	my_swaggy_writer(char *a, char *b, char *c, int context)
{
	if (context)
	{
		ft_putstr_fd(a, 1);
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(b, 1);
		ft_putstr_fd(": ", 1);
		ft_putendl_fd(c, 1);
	}
	else
	{
		ft_putnbr_fd((long unsigned int)a, 1);
		ft_putchar_fd('/', 1);
		ft_putnbr_fd((long unsigned int)b, 1);
		ft_putchar_fd(' ', 1);
		ft_putendl_fd(c, 1);
	}
}

int	check_success(t_test *test)
{
	if (test->ret == 0)
	{
		my_swaggy_writer(test->fonction, test->test_name, "[OK](kette)", 1);
		return (1);
	}
	if (test->ret == -1)
		my_swaggy_writer(test->fonction, test->test_name, "[KO](nnard)", 1);
	if (test->ret == SIGSEGV)
		my_swaggy_writer(test->fonction, test->test_name, "[SEGV]", 1);
	if (test->ret == SIGBUS)
		my_swaggy_writer(test->fonction, test->test_name, "[🚌 ERROR]", 1);
	return (0);
}

void	read_tests(t_list *lst)
{
	long unsigned int		total;
	long unsigned int		succeed;
	t_test					*ptr;

	total = 0;
	succeed = 0;
	while (lst)
	{
		ptr = lst->content;
		total++;
		succeed += check_success(ptr);
		lst = lst->next;
	}
	my_swaggy_writer((char *)succeed, (char *)total, "test(s) succeed", 0);
}