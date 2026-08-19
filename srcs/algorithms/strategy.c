/* srcs/algorithms/strategy.c */
#include "../../includes/push_swap.h"

void	ft_bubble_sort(t_stack **a, t_stack **b, t_config *config);
void	ft_bucket_sort(t_stack **a, t_stack **b, t_config *config);
void	ft_radix_sort(t_stack **a, t_stack **b, t_config *config);

static void	ft_run_adaptive_strategy(t_stack **a, t_stack **b, t_config *config, double disorder)
{
	if (disorder < 0.2)
	{
		config->strategy = 0; // Simple
		ft_bubble_sort(a, b, config);
	}
	else if (disorder < 0.5)
	{
		config->strategy = 1; // Medium
		ft_bucket_sort(a, b, config);
	}
	else
	{
		config->strategy = 2; // Complex
		ft_radix_sort(a, b, config);
	}
}

void	ft_execute_strategy(t_stack **a, t_stack **b, t_config *config)
{
	double	disorder;

	disorder = compute_disorder(*a);
	if (config->strategy == 0)
		ft_bubble_sort(a, b, config);
	else if (config->strategy == 1)
		ft_bucket_sort(a, b, config);
	else if (config->strategy == 2)
		ft_radix_sort(a, b, config);
	else
		ft_run_adaptive_strategy(a, b, config, disorder);
}