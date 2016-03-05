
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount)
{

	int i;
	int index = 0;
	int flag = 0;
	int singleFlag = 0;
	int equalFlag = 0;

	if (len < 0 || Arr == 0)
		return 0;
	

	if (len == 1)
		singleFlag = 1;

	for (i = 0; i<len; i++)
	{

		if (Arr[i] == score) {
			index = i;
			break;
		}
		else if (Arr[i] >score)
		{
			index = i;
			flag = 1;
			break;
		}

	}
	
	if (singleFlag == 1 && Arr[0]<score)
		*lessCount = index + 1;
	else
		*lessCount = index;

	if (flag == 0)
		*moreCount = len - index - 1;
	else if (flag == 1)
		*moreCount = len - index;

	for (i = 1; i<len; i++)
	{
		if (Arr[i] == Arr[i - 1]){
			equalFlag = 1;
			break;
		}

	}
	if (equalFlag)
	{
		*lessCount = 0;
		*moreCount = 0;
	}
}

