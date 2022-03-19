#include "philo.h"

int	check_arg_value_part2(char *nbr, int i)
{
	if (nbr[i] > '7')
		return (0);
	i++;
	if (nbr[i] > '4')
		return (0);
	i++;
	if (nbr[i] > '8')
		return (0);
	i++;
	if (nbr[i] > '3')
		return (0);
	i++;
	if (nbr[i] > '6')
		return (0);
	i++;
	if (nbr[i] > '4')
		return (0);
	i++;
	if (nbr[i] <= '7' || (nbr[0] == '-' && nbr[i] == '8'))
		return (1);
	return (0);
}

int	check_arg_value(char *nbr)
{
	int	a;
	int	i;

	i = 0;
	a = ft_strlen(nbr);
	if (a > 11 || (a == 11 && nbr[0] != '-'))
		return (0);
	if (a < 10 || (a < 11 && nbr[0] == '-'))
		return (1);
	if (nbr[0] == '-')
		i++;
	if (nbr[i] > '2')
		return (0);
	i++;
	if (nbr[i] > '1')
		return (0);
	i++;
	if (nbr[i] > '4')
		return (0);
	i++;
	return (check_arg_value_part2(nbr, i));
}

int	check_if_only_dig(char *s1)
{
	int	i;

	i = 0;
	while(s1[i] != 0)
	{
		if(!ft_isdigit(s1[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(int argc, char **argv)
{
	int	i;
	
	i = 1;
	if(argc != 5 && argc != 6)
	{
		if(argc < 5)
			write(2, "Not enough Arguments!\n", 22);
		else
			write(2, "Too many Arguments!\n", 20);
		return (0);
	}
	while(i < argc)
	{
		if(!check_if_only_dig(argv[i]))
		{
			write(2, "Arguments contain non digit Characters!\n", 40);
			return(0);
		}
		i++;
	}
	i = 1;
	while(i < argc)
	{
		if(!check_arg_value(argv[i]))
		{
			write(2, "Argument is bigger than an int!\n", 33);
			return(0);
		}
		i++;
	}
	return(1);
}
