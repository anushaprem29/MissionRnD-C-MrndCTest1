/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]

	int iter, start=0, end, d, s, n = 0, *result = (int *)malloc(sizeof(int) * 6);
	float f;
	if (arr == NULL || len < 0)
		return NULL;

	d = arr[1] - arr[0];
	for (iter = 1; iter < len - 1; iter++){
		if ((arr[iter + 1] - arr[iter]) == d){
			end = iter + 1;

		}
		else{
			if (end - start > 1){
				break;
			}
			d = arr[iter + 1] - arr[iter];
			start = iter + 1;
		}
	}
	result[0] = start;
	result[1] = end;
	start = iter++;
	d = arr[iter + 1] - arr[iter];
	for (iter = iter + 1; iter < len - 1; iter++){
		if (arr[iter + 1] - arr[iter] == d){
			end = iter + 1;
		}
		else{
			if (end - start > 1) break;
			d = arr[iter + 1] - arr[iter];
			start = iter + 1;
		}
	}

	result[2] = start;
	result[3] = end;
	iter = 0;
	f = arr[iter + 1] / arr[iter];
	for (iter++; iter < len - 1; iter++){
		if (arr[iter + 1] == 0){
			if (end - start > 1){
				break;
			}
			f = 0;
			start = iter + 1;
		}
		else if (arr[iter + 1] / arr[iter] == f){
			end = iter + 1;
		}
		else{
			if (end - start > 1){
				break;
			}
			f = arr[iter] / arr[iter + 1];
			start = iter + 1;
		}
	}
	result[4] = start;
	result[5] = end;
	return result;
}