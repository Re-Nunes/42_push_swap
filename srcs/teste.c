#include "parsing.h"
#include "stack.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_stack		*a;
	t_config	confing;

	if (argc < 2)
		return (0);
	a = ft_stack_new();
	if (!a)
		return (1);
	parse_arguments(argc, argv, &a, &confing);
}