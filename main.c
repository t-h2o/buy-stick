#include	<stdio.h>
#include	<stdlib.h>

/* string to int
 */
int	ft_strnbr(char* str)
{
	int	nbr= 0;
	int	ten = 1;
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
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
	int	i = -1;

	while (++i < argc - 2)
	{
		int	j = i;
		while (++j < argc - 2)
		{
			if (ls[i] < ls[j])
			{
				int temp = ls[i];
				ls[i] = ls [j];
				ls[j] = temp;
			}
		}
	}
}
   
int*	ft_poutre(int argc, char** argv)
{
	int*	poutre;
	poutre = (int*)malloc(sizeof(int*) * (argc - 2));
	int	i = -1;
	while (++i < argc - 2)
	{
		poutre[i] = ft_strnbr(argv[i+2]);
	}
	return (poutre);
}

int	main(int argc, char** argv)
{
	int	achat = ft_strnbr(argv[1]);
	int*	poutre = ft_poutre(argc, argv);
	int	i;
	int	nbr;

	printf("achat %d\tcm\n\n", achat);
	
	ft_decroissant(poutre, argc);

	i = -1;
	while (++i < argc -2)
	{
		printf("%d.\tpoutre %d\tcm\t%p\n", i + 1, poutre[i], &poutre[i]);
	}

	nbr = 0;
	i = -1;
	while (++i < argc - 2)
	{
	
		int	j = i;
		int	sum = 0;
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
	return 0;	
}
