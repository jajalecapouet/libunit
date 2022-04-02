/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:58:45 by njaros            #+#    #+#             */
/*   Updated: 2022/04/02 15:30:50 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strlen_tests.h"

int	strlen_launcher(void)
{
	t_list	*testlist;

	load_test(&testlist, "STRLEN", "Basic test", basic_test);
	read_tests(testlist);
	freezbi(&testlist);
	return (1);
}
