/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:42:05 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 13:42:14 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(void)
{
	char	current_dir[4096];

	if (getcwd(current_dir, 4096) == NULL)
	{
		perror("minishell: pwd");
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(current_dir, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
