/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:40:43 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 13:41:08 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parse_env_var(char *str, char **key, char **value)
{
	char	*equal_sign;

	if (!str || !key || !value)
		return ;
	equal_sign = ft_strchr(str, '=');
	if (equal_sign)
	{
		*key = ft_substr(str, 0, equal_sign - str);
		*value = ft_strdup(equal_sign + 1);
	}
	else
	{
		*key = ft_strdup(str);
		*value = ft_strdup("");
	}
	if (!*key || !*value)
	{
		free(*key);
		free(*value);
		*key = NULL;
		*value = NULL;
	}
}

int	builtin_env(t_command *cmd, t_shell *shell)
{
	t_env	*current;

	if (cmd->args[1])
	{
		ft_putendl_fd("env: too many arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	current = shell->env_list;
	while (current)
	{
		ft_putstr_fd(current->key, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putendl_fd(current->value, STDOUT_FILENO);
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

t_env	*add_env_var(t_env **list, char *key, char *value)
{
	t_env	*new;
	t_env	*current;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = NULL;
	if (!*list)
	{
		*list = new;
		return (new);
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new;
	return (new);
}

t_env	*init_env_list(char **envp)
{
	t_env	*list;
	int		i;
	char	*key;
	char	*value;

	list = NULL;
	i = 0;
	while (envp[i])
	{
		parse_env_var(envp[i], &key, &value);
		if (key && value)
			add_env_var(&list, key, value);
		else
		{
			free(key);
			free(value);
		}
		i++;
	}
	return (list);
}
