/* Esau Noya | 1001301929 | CSE 1320-005 */
#include <stdio.h>
/*
	Function Declarations
*/
void convertDecimalToBinary(int decimal, int arr[]);
void printBinary(int arr[]);
/*
main():
	Prompts user for a decimal number to convert to binary.
	Checks if input is between 0 and 255
		if not prompts user for input again
	Calls convertDecimalToBinary
	Calls printbinary
*/
int main(void){
	// decimal to be converted to binary later
	int decimal = -1;
	//integer array to hold the 1's and 0's of our output
	//I called it binArry... I think it's a pretty funny name
	int binArry[8];
	printf("Decimal to binary converter\n\n");
	//while loop prompting user for input and checking if its between 0 and 255
	while(decimal < 0 || decimal > 255){
		printf("Please enter a decimal number between 0 and 255 ");
		scanf("%d", &decimal);
		if(decimal < 0 || decimal > 255){
			printf("\nYou entered a number not between 0 and 255\n\n");
		}
	}
	printf("\n");
	convertDecimalToBinary(decimal, binArry);
	printf("Decimal %d converts to binary ", decimal);
	printBinary(binArry);
	return 0;
}
/*
ConvertDecimalToBinary()

	Takes in decimal input by user and empty array

	Converts decimal to binary by divinding in half, ignoring the remainder
	writing 1's for odd numbers and 0's for even, and repeat.
*/
void convertDecimalToBinary(int decimal, int arr[]){
	for(int i = 0; i < 8; i++){
		//using bitmask &1 finds out if the current value of decimal is odd,
		//if so, writes 1 to array, else writes odd
		arr[7-i]=(decimal&1)?1:0;
		//right bitshifts decimal by 1, equivalent to dividing by 2
		decimal = decimal >> 1;
	}
	return;
}
/*
Print Binary()

	Takes array and prints it... not much to it
*/
void printBinary(int arr[]){
	for(int i = 0; i < 8; i++){
		printf("%d", arr[i]);	
	}
	printf("\n\n");
	return;
}
