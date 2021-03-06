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
	struct comp std_printf[6];
	struct comp  our_printf[6];
	int x = 0, y = 0, num = 1, i = 0;
        int len = 0;
        int len2 = 0;
	int signal = 0;
	char *format = "%c\n";

	               /* 1    2     3     4    5    6   */
	char array[] = {'\0', 'a', '\n', '\t', ' ', '\\'};


/*STD LIBRARY PRINTF EDGE TESTS*/
printf("<std library printf edge cases located below>\n");
printf("--------------------------------\n");
for (i = 0; i < 6; i++)
{
	printf("Test %d:\n", i + 1);
	len = printf(format, array[i]);
	std_printf[x].return_val = len, std_printf[x].line_num = num, num++, x++;
}

/*reset x*/
x = 0;
num = 1;
/*OUR PRINTF EDGE TESTS*/
printf("<our _printf edge cases located below>\n");
printf("--------------------------------\n");
for (i = 0; i < 6; i++)
{
	printf("Test %d:\n", i + 1);
	len2 = _printf(format, array[i]);
	our_printf[x].return_val = len2, our_printf[x].line_num = num, num++, x++;
}

/*TRANSITION TO RESULTS*/
printf("-----------------\n");
printf("<ran all edge cases>\n");
printf("-----------------\n");
printf("<below are the line numbers where _printf function fails in testfile>");
printf("\n<refer to the \"format\" array in the test file to see which edge case your _printf is failing>\n");
printf(" an edge case>\nEXAMPLE: /* 1 2 etc... */\n");
printf("-----------------\n");
/*RESULTS AFTER COMPARING*/
for (y = 0; y < 6; y++)
{
	if (std_printf[y].return_val != our_printf[y].return_val)
	{
		printf("Test %d failure. Edge case: \"%c\"", y + 1, array[y]);
		printf("\"\n\tStd printf return val: %d\n\tYour _printf return val: %d\n\n", std_printf[y].return_val, our_printf[y].return_val);
		signal = 1;
	}
}
if (signal == 0)
	printf("NO ERRORS DETECTED\n");
return (0);
}
