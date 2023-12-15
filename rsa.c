#include <stdio.h>
#include <stdlib.h>

/**
 * isPrime - Checks if a number is prime.
 * @num: The number to check.
 *
 * Return: 1 if prime, 0 otherwise.
 */
int isPrime(long long int num)
{
	if (num <= 1)
		return (0);

	for (long long int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
			return (0); /* Not a prime number */
	}

	return (1); /* Prime number */
}

/**
 * factorizePrime - Factorizes a number into prime factors.
 * @number: The number to factorize.
 */
void factorizePrime(long long int number)
{
	if (number <= 1)
	{
		fprintf(stderr, "Error: Invalid number in the file.\n");
		return;
	}

	printf("%lld=", number);

	/* Start with the smallest prime factor, which is 2 */
	int isPairPrinted = 0;

	for (long long int i = 2; i <= number; ++i)
	{
		int count = 0;

		while (number % i == 0)
		{
			number /= i;
			count++;
		}

		if (count > 0)
		{
			if (isPairPrinted)
				printf("*");

			if (count > 1)
				printf("%lld^%d", i, count);
			else
				printf("%lld", i);

			isPairPrinted = 1;
		}
	}

	printf("\n");
}

/**
 * main - main function reads  number from file and factorize it into primes.
 * @argc: The number of command-line arguments.
 * @argv: The array of command-line arguments.
 *
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
	/* Read the single number from the file and factorize it into primes */
	char buffer[1024];

	if (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		long long int number;

		if (sscanf(buffer, "%lld%*c", &number) == 1)
		{
			factorizePrime(number);
		}
		else
		{
			fprintf(stderr, "Error: Invalid number in the file: %s\n", buffer);
		}
	}
	else
	{
		fprintf(stderr, "Error: Empty file\n");
	}
	fclose(file);
	return (0);
}
