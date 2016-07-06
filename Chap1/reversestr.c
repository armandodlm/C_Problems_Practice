#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void reverse(char *str);

void reverse(char *str){

	// possibly use strnlen for max size
	uint16_t size = strlen(str);
	char *left = str;
	char *right = str+size-1;

	printf("String is: %s \n",str);

	while(left < right){
		char temp = *left;
		*left = *right;
		*right = temp;
		left ++;
		right --;
	}

	printf("The string is now %s\n",str);
}


int main(int argc, char **args){
	if(argc > 1){
		reverse(args[1]);
	}
	return 0;
}