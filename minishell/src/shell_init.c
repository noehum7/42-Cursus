/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:43:07 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 13:43:08 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*init_shell(char **envp)
{
	t_shell	*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->env_list = init_env_list(envp);
	shell->env_array = env_list_to_array(shell->env_list);
	shell->exit_status = 0;
	return (shell);
}

void	free_shell(t_shell *shell)
{
	free_env_list(shell->env_list);
	ft_free_array(shell->env_array);
	free(shell);
}
