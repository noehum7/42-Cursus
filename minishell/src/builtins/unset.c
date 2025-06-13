/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:42:23 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 13:42:27 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unset(char **args, t_shell *shell)
{
	int	i;
	int	has_error;

	if (!args[1])
		return (EXIT_SUCCESS);
	i = 0;
	has_error = 0;
	while (args[++i])
	{
		if (!is_valid_var_name(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(args[i], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			has_error = 1;
		}
		else if (unset_env_var(&shell->env_list, args[i]) == EXIT_SUCCESS)
			update_env_array(shell);
	}
	if (has_error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
