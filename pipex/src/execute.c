#include "pipex.h"

static char	*search_in_path(char *cmd, char **paths)
{
	char	*path;
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

static char	*get_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*result;
	char	*cmd_copy;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			cmd_copy = ft_strdup(cmd);
			return (cmd_copy);
		}
		return (NULL);
	}
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	paths = ft_split(*envp + 5, ':');
	result = search_in_path(cmd, paths);
	ft_free_array(paths);
	return (result);
}

static void	handle_command_error(char **args, char *cmd_path, int err)
{
	ft_free_array(args);
	free(cmd_path);
	if (err == EACCES)
		exit(126);
	else if (err == ENOENT)
		exit(127);
	error_exit("execve");
}

static char	*validate_and_get_path(char *cmd, char **envp)
{
	char	*cmd_path;

	if (!cmd || cmd[0] == '\0')
	{
		print_cmd_error("", "command not found");
		exit(127);
	}
	cmd_path = get_command_path(cmd, envp);
	if (!cmd_path)
	{
		print_cmd_error(cmd, "command not found");
		exit(127);
	}
	return (cmd_path);
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	if (!args)
		error_exit("memory allocation failed");
	cmd_path = validate_and_get_path(args[0], envp);
	if (execve(cmd_path, args, envp) == -1)
		handle_command_error(args, cmd_path, errno);
}
