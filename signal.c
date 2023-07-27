#include "main.h"

/**
 * find_sigint - ctrl c
 * @signl: signals
 */
void find_sigint(int signl)
{
	(void)signl;

	write(STDOUT_FILENO, "\n:)$ ", 5);
}
