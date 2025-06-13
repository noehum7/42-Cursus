/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:41:45 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 13:41:58 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_export_vars(t_shell *shell)
{
	t_env	*current;

	current = shell->env_list;
	while (current)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(current->key, STDOUT_FILENO);
		if (current->value && *current->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(current->value, STDOUT_FILENO);
			ft_putchar_fd('\"', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		current = current->next;
	}
}

static int	process_export_arg(char *arg, t_shell *shell)
{
	char	*key;
	char	*value;
	char	*equal_sign;

	equal_sign = ft_strchr(arg, '=');
	if (!equal_sign)
		return (EXIT_SUCCESS);
	key = ft_substr(arg, 0, equal_sign - arg);
	value = ft_strdup(equal_sign + 1);
	if (!is_valid_var_name(key))
	{
		ft_putstr_fd("minishell: export: `", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		free(key);
		free(value);
		return (EXIT_FAILURE);
	}
	set_env_var(&shell->env_list, key, value);
	update_env_array(shell);
	free(key);
	free(value);
	return (EXIT_SUCCESS);
}

int	builtin_export(char **args, t_shell *shell)
{
	int	i;
	int	has_error;

	if (!args[1])
	{
		print_export_vars(shell);
		return (EXIT_SUCCESS);
	}
	i = 1;
	has_error = 0;
	while (args[i])
	{
		if (process_export_arg(args[i], shell) != 0)
			has_error = 1;
		i++;
	}
	if (has_error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
