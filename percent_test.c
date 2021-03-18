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
	struct comp std_printf[13];
	struct comp our_printf[13];
	int x = 0, y = 0, num = 1, i = 0, ii = 0;
        int len = 0;
        int len2 = 0;
	int signal = 0;
	int args[] = {10, 0};

	              /*    1      2     3     4       5     6     7      8     9      10 */
	char *format[] = {"%%%d", "%%d", "%", "\n%", "%\n", "%%", "% ", " %", "hi% ", "hi% [ ",
	      /*  11         12       13    */
		" hi% ", " hi% [ ", "% \n "};


/* STD LIBRARY PRINTF EDGE TESTS */
printf("<std library printf edge cases located below>\n");
printf("--------------------------------\n");
for (i = 0; i < 13; i++)
{
	printf("Test %d:\n", i + 1);
	len = printf(format[i], args[ii]);
	std_printf[x].return_val = len, std_printf[x].line_num = num, num++, x++;
	printf("\n");
	if (ii < 1)
		ii++;
}
/* reset variables */
x = 0;
num = 1;
ii = 0;
/* OUR PRINTF EDGE TESTS */
printf("<our _printf edge cases located below>\n");
printf("--------------------------------\n");
for (i = 0; i < 13; i++)
{
	printf("Test %d:\n", i + 1);
	len2 = _printf(format[i], args[ii]);
	our_printf[x].return_val = len2, our_printf[x].line_num = num, num++, x++;
	printf("\n");
	if (ii < 1)
		ii++;
}

/* TRANSITION TO RESULTS */
printf("-----------------\n");
printf("<ran all edge cases>\n");
printf("-----------------\n");
printf("<below are the line numbers where your _printf function fails in testfile>");
printf("\n<refer to the \"format\" array in the test file to see which edge case your _printf is failing>\n");
printf("-----------------\n");
/* RESULTS AFTER COMPARING */
for (y = 0; y < 13; y++)
{
	if (std_printf[y].return_val != our_printf[y].return_val)
	{
		printf("Error on array member: %d\n", y + 1);
		signal = 1;
	}
}
if (signal == 0)
	printf("NO ERRORS DETECTED\n");
return (0);
}
