#include "../../includes/push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	ft_parse_flag(char *arg, t_config *config)
{
	if (ft_strcmp(arg, "--simple") == 0)
		config->strategy = 0;
	else if (ft_strcmp(arg, "--medium") == 0)
		config->strategy = 1;
	else if (ft_strcmp(arg, "--complex") == 0)
		config->strategy = 2;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		config->strategy = 3;
	else if (ft_strcmp(arg, "--bench") == 0)
		config->has_bench = 1;
	else
		return (0);
	return (1);
}
