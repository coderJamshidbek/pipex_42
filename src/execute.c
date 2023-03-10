/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:59:19 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/18 11:55:56 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_pipex.h"

void	execute(char *cmd_with_flags, char **env)
{
	char	**cmd_2d;
	char	*cmd_path;
	char	*env_var_path;

	cmd_2d = ft_split(cmd_with_flags, ' ');
	if (is_full_path(cmd_2d[0]))
	{
		cmd_path = cmd_2d[0];
		execve(cmd_path, cmd_2d, env);
	}
	else
	{
		env_var_path = get_path(env);
		cmd_path = get_cmd_path(env_var_path, cmd_2d[0]);
		if (cmd_path == NULL)
		{
			ft_free_2d_array((void **)cmd_2d);
			cmd_not_found_exit(cmd_with_flags);
		}
		else if (execve(cmd_path, cmd_2d, env) != -1)
			exit(-1);
	}
}
