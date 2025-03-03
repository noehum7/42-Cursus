#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac != 5)
	{
		ft_putstr_fd("Error: You must use: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(1);
	}
	pipex(av, envp);
	return (0);
}
