#include <limits.h>
#include <stdio.h>
#include "holberton.h"
int main(void)
{
struct comp
	{
		int line_num;
		int return_val;
	};
	struct comp std_printf[7];
	struct comp  our_printf[7];
	int x = 0, y = 0, num = 1, i = 0;
        int len = 0;
        int len2 = 0;
	int signal = 0;
	char *format = "%p\n";

	              /* 1   2        3      4   5     6    7 */
	int array[] = {0, INT_MAX, INT_MIN, 100, 99, -100, -99};
/* specs c s d i u o x X p + space # l h p */

/*STD LIBRARY PRINTF EDGE TESTS*/
printf("<std library printf edge cases located below>\n");
printf("--------------------------------\n");
for (i = 0; i < 7; i++)
{
	len = printf(format, &array[i]);
	std_printf[x].return_val = len, std_printf[x].line_num = num, num++, x++;
}

/*reset x*/
x = 0;
num = 1;
/*OUR PRINTF EDGE TESTS*/
printf("<our _printf edge cases located below>\n");
printf("--------------------------------\n");
for (i = 0; i < 7; i++)
{
	len2 = _printf(format, &array[i]);
	our_printf[x].return_val = len2, our_printf[x].line_num = num, num++, x++;
}

/*TRANSITION TO RESULTS*/
printf("-----------------\n");
printf("<ran all edge cases>\n");
printf("-----------------\n");
printf("<our _printf call fails on these indexed lines in the test file>\n\n");
printf("<below are the line numbers where _printf function fails in testfile>");
printf("\n<compare this list of numbers below to the test file to see where the");
printf("\ncomments above integer array initilization indicate where your _printf is failing");
printf(" an edge case>\nEXAMPLE: /* 1 2 etc... */\n");
printf("-----------------\n");
/*RESULTS AFTER COMPARING*/
for (y = 0; y < 7; y++)
{
	if (std_printf[y].return_val != our_printf[y].return_val)
	{
		if (std_printf[y].return_val > 7)
		{
			if (our_printf[y].return_val > 7)
			{
				printf("Error on array member: %d\n", our_printf[y].line_num);
				signal = 1;
			}
		}
	}
}
if (signal == 0)
	printf("NO ERRORS DETECTED\n");
return (0);
}
