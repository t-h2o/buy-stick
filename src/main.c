#include	<stdio.h>
#include	<stdlib.h>

/* error manager
 */
int	ft_error(int argc, char** argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != '\0')
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return(1); 		
		}
		return 0;
}

/* convert string to int
 */
int	ft_strnbr(char* str)
{
	int	nbr;
	int	ten;
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;

	nbr = 0;
	ten = 1;
	while (i-- > 0)
	{
		nbr += (str[i] - 48) * ten;
		ten *= 10;
	}

	return (nbr);
}

/* sort table bigger to littler
 */
void	ft_decroissant(int* ls, int argc)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < argc - 2)
	{
		j = i;
		while (++j < argc - 2)
		{
			if (ls[i] < ls[j])
			{
				temp = ls[i];
				ls[i] = ls[j];
				ls[j] = temp;
			}
		}
	}
}
   
/* create an int array 
 * with the argument
 */
int*	ft_poutre(int argc, char** argv)
{
	int*	poutre;
	int	i;
	
	poutre = (int*)malloc(sizeof(int*) * (argc - 2));

	i = -1;
	while (++i < argc - 2)
		poutre[i] = ft_strnbr(argv[i+2]);

	return (poutre);
}

int	main(int argc, char** argv)
{
	int	achat;
	int*	poutre;
	int	i;
	int	j;
	int	nbr;
	int	sum;
	
	if (ft_error(argc, argv))
		printf("error: letter in arguments\n");
	if (ft_error(argc, argv))
		return (0);

	achat = ft_strnbr(argv[1]);
	poutre = ft_poutre(argc, argv);

	printf("achat %d\tcm\n\n", achat);
	
	ft_decroissant(poutre, argc);

	i = -1;
	while (++i < argc -2)
		printf("%d.\tpoutre %d\tcm\t%p\n", i + 1, poutre[i], &poutre[i]);

	nbr = 0;
	i = -1;
	while (++i < argc - 2)
	{
		j = i;
		sum = 0;
		if (poutre[i] <= achat)
		{
			nbr++;
			printf("\n\n\nTige %d\n\n", nbr);
			printf("long: %d\n", poutre[i]);
			sum += poutre[i];
			poutre[i] = achat + 1;
			while (++j < argc -2 )
			{
				if (poutre[j] + sum <= achat)
				{
				 
					printf("long. %d\n", poutre[j]);
					sum += poutre[j];
					poutre[j] = achat + 1;
				}
			}
		}
		if (sum > 0)
			printf("\nchute %d cm\n", achat - sum);
	}

	free(poutre);
}
