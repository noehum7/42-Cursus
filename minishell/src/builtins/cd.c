/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:38:01 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 13:38:27 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_current_directory(void)
{
	char	current_dir[4096];

	if (getcwd(current_dir, 4096) == NULL)
	{
		perror("minishell: cd");
		return (NULL);
	}
	return (ft_strdup(current_dir));
}

static int	cd_to_dir(char *dir, t_shell *shell)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = get_current_directory();
	if (!oldpwd)
		return (EXIT_FAILURE);
	if (chdir(dir) != 0)
	{
		perror("minishell: cd");
		free(oldpwd);
		return (EXIT_FAILURE);
	}
	pwd = get_current_directory();
	if (!pwd)
	{
		free(oldpwd);
		return (EXIT_FAILURE);
	}
	set_env_var(&shell->env_list, "OLDPWD", oldpwd);
	set_env_var(&shell->env_list, "PWD", pwd);
	free(oldpwd);
	free(pwd);
	return (EXIT_SUCCESS);
}

static int	cd_to_home(t_shell *shell)
{
	char	*home;

	home = get_env_value(shell->env_list, "HOME");
	if (!home)
	{
		ft_putendl_fd("minishell: cd: HOME not set", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (cd_to_dir(home, shell));
}

static int	cd_to_previous(t_shell *shell)
{
	char	*oldpwd;
	int		result;

	oldpwd = get_env_value(shell->env_list, "OLDPWD");
	if (!oldpwd)
	{
		ft_putendl_fd("minishell: cd: OLDPWD not set", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(oldpwd, STDOUT_FILENO);
	result = cd_to_dir(oldpwd, shell);
	return (result);
}

int	builtin_cd(char **args, t_shell *shell)
{
	if (!args[1] || (args[1][0] == '~' && args[1][1] == '\0'))
		return (cd_to_home(shell));
	if (args[1][0] == '-' && args[1][1] == '\0')
		return (cd_to_previous(shell));
	return (cd_to_dir(args[1], shell));
}
