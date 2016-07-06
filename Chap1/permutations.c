/*
 * Given two strings, write a method to decide if one is a permutation of the other
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bool{
	unsigned val : 1;
}bool;




char isPermutationSort(char *str_one, char *str_two);
char isPermutationCount(char *str_one, char *str_two);



char isPermutationSort(char *str_one, char *str_two){
	return 0;
}

char isPermutationCount(char *str_one, char *str_two){

	int len_one = strlen(str_one);
	int len_two = strlen(str_two);
	if(len_one != len_two){

		int count_one[128];
		int count_two[128];
		memset(count_one,0,128);
		memset(count_two,0,128);

		char iter = *str_one;
		while(iter != '\0'){
			count_one[iter] += 1;
			str_one++;
			iter = *str_one;
		}

		iter = *str_two;
		while(iter != '\0'){
			count_two[iter] += 1;
			str_two++;
			iter = *str_two;		
		}
		unsigned char i = 0;
		printf("[");
		for(i = 0; i < 128; i++){
			if(count_one[i]){
				printf(" %c : %d ",i,count_one[i]);
			}
		}
		printf("]\n");

		printf("[");
		for(i = 0; i < 128; i++){
			if(count_two[i]){
				printf(" %c : %d ",i,count_two[i]);
			}
		}
		printf("]\n");

		return 1;
	}else return 0;
}

int main(){

	char *one = "therewasamonster";
	char *two = "amonstertherewas";

	
	isPermutationCount(one,two);

	return 0;
}
