#include "main.h"

/**
 * replace_token - replaces string
 * @h: beginning of the linked list
 * @tok: string
 * @new_tok: new string
 * @sum_b: length
 * Return: new str
 */
char *replace_token(varb_list **h, char *tok, char *new_tok, int sum_b)
{
	varb_list *index;
	int a, b, c;

	index = *h;
	for (b = a = 0; a < sum_b; a++)
	{
		if (tok[b] == '$')
		{
			if (!(index->varlen) && !(index->valuelen))
			{
				new_tok[a] = tok[b];
				b++;
			}
			else if (index->varlen && !(index->valuelen))
			{
				for (c = 0; c < index->varlen; c++)
					b++;
				a--;
			}
			else
			{
				for (c = 0; c < index->valuelen; c++)
				{
					new_tok[a] = index->value[c];
					a++;
				}
				b += (index->varlen);
				a--;
			}
			index = index->next;
		}
		else
		{
			new_tok[a] = tok[b];
			b++;
		}
	}

	return (new_tok);
}
