/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:19:56 by ldias-fe          #+#    #+#             */
/*   Updated: 2023/01/31 17:58:53 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * 2);
	if (!data)
		return (1);
	if (check_arg(data, argc, argv))
		initialize(data);
	else
		free(data);
	return (0);
}
