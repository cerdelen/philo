#include "philo.h"

int	main(int argc, char **argv)
{
	philo_data	data;

	if(!check_arguments(argc, argv))
		return(0);
	fill_struct(argc, argv, &data);
	start_philosophers(&data);

}