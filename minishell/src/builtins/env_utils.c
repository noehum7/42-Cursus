/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:39:49 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 13:40:17 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_env_vars(t_env *list)
{
	int		count;
	t_env	*current;

	count = 0;
	current = list;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static char	*create_env_string(char *key, char *value)
{
	char	*key_eq;
	char	*result;

	key_eq = ft_strjoin(key, "=");
	if (!key_eq)
		return (NULL);
	result = ft_strjoin(key_eq, value);
	free(key_eq);
	return (result);
}

char	**env_list_to_array(t_env *list)
{
	char	**array;
	int		count;
	int		i;
	t_env	*current;

	count = count_env_vars(list);
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	current = list;
	i = 0;
	while (current)
	{
		array[i] = create_env_string(current->key, current->value);
		current = current->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	free_env_list(t_env *list)
{
	t_env	*current;
	t_env	*next;

	current = list;
	while (current)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
}

void	free_env_node(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}
