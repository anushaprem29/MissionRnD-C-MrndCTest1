/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	if (s1==NULL && s2==NULL && s3==NULL && s4==NULL)
		return NULL;
	int arr[26];
	bool flag = true;
	for (int iter = 0; iter < 100 && flag; iter++){
		flag = false;
		if (s1[iter] != NULL){ 
			arr[s1[iter] - 'a']++;
			flag = true;
		}
		if (s2[iter] != NULL){
			arr[s2[iter] - 'a']++;
			flag = true;
		}		
		if (s3[iter] != NULL){ 
			arr[s3[iter] - 'a']++;
			flag = true;
		}
		if (s4[iter] != NULL){ 
			arr[s4[iter] - 'a']++;
			flag = true;
		}
	}
}