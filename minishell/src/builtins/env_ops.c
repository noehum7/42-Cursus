/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:39:23 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 13:39:39 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(t_env *list, char *key)
{
	t_env	*var;

	var = find_env_var(list, key);
	if (var)
		return (var->value);
	return (NULL);
}

char	*get_var_value(const char *var_name, t_shell *shell)
{
	char	*value;

	if (ft_strncmp(var_name, "?", 2) == 0)
		return (ft_itoa(shell->exit_status));
	value = get_env_value(shell->env_list, (char *)var_name);
	if (value)
		return (ft_strdup(value));
	return (ft_strdup(""));
}

int	unset_env_var(t_env **list, char *key)
{
	t_env	*current;
	t_env	*prev;

	if (!list || !*list)
		return (EXIT_FAILURE);
	if (ft_strcmp((*list)->key, key) == 0)
	{
		current = *list;
		*list = current->next;
		free_env_node(current);
		return (EXIT_SUCCESS);
	}
	prev = *list;
	current = prev->next;
	while (current && ft_strcmp(current->key, key))
	{
		prev = current;
		current = current->next;
	}
	if (!current)
		return (EXIT_FAILURE);
	prev->next = current->next;
	free_env_node(current);
	return (EXIT_SUCCESS);
}

int	set_env_var(t_env **list, char *key, char *value)
{
	t_env	*var;

	if (!is_valid_var_name(key))
		return (EXIT_FAILURE);
	var = find_env_var(*list, key);
	if (var)
	{
		free(var->value);
		var->value = ft_strdup(value);
		return (EXIT_SUCCESS);
	}
	add_env_var(list, ft_strdup(key), ft_strdup(value));
	return (EXIT_SUCCESS);
}

void	update_env_array(t_shell *shell)
{
	if (shell->env_array)
		ft_free_array(shell->env_array);
	shell->env_array = env_list_to_array(shell->env_list);
}
