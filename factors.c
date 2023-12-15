#include <stdio.h>
#include <stdlib.h>
/**
 * factorize - Function to factorize a given number
 * @number: The number to be factorized.
 * This function takes a positive integer 'number' and prints its prime
 * factors along with their powers. The output is formatted as a
 * multiplication of prime factors.
 */
void factorize(long long int number)
{
	if (number <= 1)
	{
		fprintf(stderr, "Error: Invalid number in the file.\n");
		return;
	}
	printf("%lld=", number);
/* Start with the smallest prime factor, which is 2 */
	for (long long int i = 2; i <= number; ++i)
	{
		while (number % i == 0)
		{
			printf("%lld", i);
			/* If there are more prime factors, print '*' */
			if (number != i)
				printf("*");
			number /= i;
		}
	}
	printf("\n");
}
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * This function serves as the entry point of the program. It reads a file
 * containing natural numbers and calls the 'factorize' function for each
 * number, printing the results.
 * Return: 0 on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	/* Parse command line arguments */
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	/* Read each number from the file and factorize it */
	char buffer[1024];  /* Use a larger buffer */

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		long long int number;

		if (sscanf(buffer, "%lld%*c", &number) == 1)
		{
			factorize(number);
		}
		else
		{
			fprintf(stderr, "Error: Invalid number in the file: %s\n", buffer);
		}
	}
	fclose(file);
	return (0);
}

