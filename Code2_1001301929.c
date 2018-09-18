/* Esau Noya | 1001301929 | CSE 1320-005 */
#include <stdio.h>
/*
	Function Declarations
*/
void convertDecimalToBinary(int decimal, int arr[], int max);
void printBinary(int arr[], int max);
int findMax(int decimal);
/*
main():
	Prompts user for a decimal number to convert to binary.
	Checks if input is 0 or greater
		if not prompts user for input again
	Calls findMax()
	Creates binArry array with size found with findMax()
	Calls convertDecimalToBinary
	Calls printbinary
*/
int main(void){
	// decimal to be converted to binary later
	int decimal = -1;
	int max = -1;
	printf("Decimal to binary converter\n\n");
	//while loop prompting user for input and checking if its greater than 0
	while(decimal < 0){
		printf("Please enter a decimal number 0 or greater: ");
		scanf("%d", &decimal);
		if(decimal < 0){
			printf("\nYou entered a number less than 0\n\n");
		}
	}
	max = findMax(decimal);
	//integer array to hold the 1's and 0's of our output
	//I called it binArry... I think it's a pretty funny name
	int binArry[max];
	printf("\n");
	convertDecimalToBinary(decimal, binArry, max);
	printf("Decimal %d converts to binary ", decimal);
	printBinary(binArry, max);
	return 0;
}
/*
findMax()

	finds bit lenght of decimal
*/
int findMax(int decimal){
	int bitLen = 0;
	int mul = 1;
	while(decimal >= mul){
		bitLen++;
		mul*=2;
	}
	if(bitLen==0)bitLen=1;
	return bitLen;
}
/*
ConvertDecimalToBinary()

	Takes in decimal input by user and empty array

	Converts decimal to binary by divinding in half, ignoring the remainder
	writing 1's for odd numbers and 0's for even, and repeat.
*/
void convertDecimalToBinary(int decimal, int arr[], int max){
	for(int i = 0; i < max; i++){
		//using bitmask &1 finds out if the current value of decimal is odd,
		//if so, writes 1 to array, else writes odd
		arr[(max-1)-i]=(decimal&1)?1:0;
		//right bitshifts decimal by 1, equivalent to dividing by 2
		decimal = decimal >> 1;
	}
	return;
}
/*
Print Binary()

	Takes array and prints it... not much to it
*/
void printBinary(int arr[], int max){
	for(int i = 0; i < max; i++){
		printf("%d", arr[i]);	
	}
	printf("\n\n");
	return;
}
