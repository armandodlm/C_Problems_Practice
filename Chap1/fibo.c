#include <stdio.h>
#include <stdint.h>

// find kth fibonacci 
/*

		O(n)*
		* -> finds same number twice at least
*/

// 

uint64_t findKFib_recursive(int16_t k){
	
	// base case 
	if(k == 1 || k == 2){
 		return 1;
	} else if(k < 1){
		return 0;
	}
	
	return findKFib_recursive(k -1) + findKFib_recursive(k-2);
}

/*
	O(n) 

*/
uint64_t findKFib(int16_t k){

	if(k == 1 || k == 2){
		return 1;
	}else if(k < 1){
		return 0;
	}

	int counter = 3;
	uint64_t n_1 = 1;
	uint64_t n_2 = 1;
	uint64_t result = 0;
	// 1 1 2 3 5 ...

	while(counter <= k){
		result = n_1 + n_2;
		n_2 = n_1;
		n_1 = result;
		counter++;
	}

	return result;

}

// Hypothetical array -> O(1)

int main(){

	uint64_t x = findKFib(2);
	printf("this fib is %llu\n",x);
	x = findKFib(5);
	printf("this fib is %llu\n",x);

	x = findKFib(6);
	printf("this fib is %llu\n",x);

	x = findKFib(7);
	printf("this fib is %llu\n",x);

	x = findKFib(8);
	printf("this fib is %llu\n",x);

	x = findKFib(9);
	printf("this fib is %llu\n",x);

	x = findKFib(10);
	
	printf("this fib is %llu\n",x);
	x = findKFib(11);
	
	printf("this fib is %llu\n",x);

	x = findKFib(-10);
	
	printf("this fib is %llu\n",x);

	x = findKFib(50);
	printf("this fib is %llu\n",x);




	return 0;
}
