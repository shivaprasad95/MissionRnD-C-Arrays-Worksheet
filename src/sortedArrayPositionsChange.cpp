/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int index1 = 0, index2 = len - 1;
	int i, j, flag1 = 0, flag2 = 0;
	int temp;

	if (len < 0 || Arr == 0)
		return 0;

	for (i = 0, j = len - 1; i<len&&j>i; i++, j--)
	{
		if (Arr[i + 1]<Arr[i]){
			index1 = i;
			flag1 = 1;
		}
		if (Arr[j - 1]>Arr[j])
		{
			index2 = j;
			flag2 = 1;
		}
		if (flag1&&flag2)
			break;
	}


	temp = Arr[index1];
	Arr[index1] = Arr[index2];
	Arr[index2] = temp;


	return Arr;

}