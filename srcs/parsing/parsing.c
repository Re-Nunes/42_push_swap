#include "../../includes/push_swap.h"

int	ft_is_whitespace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

long long	ft_atoll(const char *str, int *error)
{
	long long	nb;
	int			i;
	int			sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		*error = 1;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		if ((sign == 1 && nb > 2147483647) || (sign == -1 && nb > 2147483648))
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	if (str[i] != '\0')
		*error = 1;
	return (sign * nb);
}

int	ft_is_digit_str(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
