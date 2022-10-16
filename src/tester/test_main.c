
#include <push_swap.h>
#include <operations.h>

void	print_stkstk(t_stack a, t_stack b, int v);
void	sort_decide(t_stack *a, t_stack *b, int bit);

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	if (argc < 2)
		return (1);
	push_swap_init(argv + 1, argc - 1, &a, &b);
	print_stkstk(a, b, 1);
	push_swap_sort(&a, &b);
	print_stkstk(a, b, 1);
}
