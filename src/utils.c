/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:56:35 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/16 14:55:43 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	ft_wait(void)
{
	int	exit_status;
	int	process_id;
	int	status;
	int	signal_number;

	process_id = waitpid(0, &status, 0);
	while (process_id != -1)
	{
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
				printf("Child process with pid: %d terminated with non-zero exit status %d\n", process_id, exit_status);
			else
				printf("Child process with pid: %d terminated with zero exit status %d\n", process_id, exit_status);
		}
		else if (WIFSIGNALED(status))
		{
			signal_number = WTERMSIG(status);
			printf("Child process with pid: %d terminated by signal %d\n", process_id, signal_number);
		}
		process_id = waitpid(0, &status, 0);
	}
}

void	check(void)
{
	system("leaks pipex");
}
