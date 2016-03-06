/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	int index1 = 0, index2 = len - 1;
	int i, j, flag1 = 0, flag2 = 0;
	struct student temp;
	if (len < 0 || students == 0)
		return 0;

	for (i = 0, j = len - 1; i<len&&j>i; i++, j--)
	{
		if (students[i + 1].score>students[i].score){
			index1 = i;
			flag1 = 1;
		}
		if (students[j - 1].score<students[j].score)
		{
			index2 = j;
			flag2 = 1;
		}
		if (flag1&&flag2)
			break;
	}

	if (index1 == 0 && index2 == len - 1 && flag1 == 0 && flag2 == 0)
		return 0;


	temp = students[index1];
	students[index1] = students[index2];
	students[index2] = temp;
}