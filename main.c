#include "main.h"

/**
* main - tests code
* Return: success(0)
*/
int main(void)
{
	unsigned int status;

	do {
		status = eshell();
		if (status == 3)
		{
			status = 0;
		}
	} while (status);

	return (0);
}
