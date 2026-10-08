/* Agustin Acevedo Ferman
	January 13, 2024
	ENGR 2220, Section 001, 2nd Semester, Lottery.c
Purpose: Program to allow user to choose their number picks for a lottery ticket
and compare to a winning ticket until they win
Assumptions: Assume user will only input numbers and not characters. 
Will take in values as input from the user. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	// Variables
	int NumList[6], WinList[6], sum=0, temp=0, goAgain=1, value=0, attempt=1, winner=1;

	//Initialize random number generator
	srand(time(0));

	//Read user input
	do {
		printf("\n");
		do {
			printf("Please input a number from 1 to 5: ");
			scanf("%d", &NumList[0]);
		} while ((NumList[0] < 1) || (NumList[0] > 5));
		for (int i=0; i<2; i++) {
			do {
				printf("Please input a number from 1 to 10: ");
				scanf("%d", &NumList[i+1]);
			} while ((NumList[i+1] < 1) || (NumList[i+1] > 10));
		}
		do {
			printf("Please input a number from 10 to 12: ");
			scanf("%d", &NumList[3]);
		} while ((NumList[3] < 10) || (NumList[3] > 12));
		for (int i=4; i<6; i++) {
			do {
				printf("Please input a number from 8 to 15: ");
				scanf("%d", &NumList[i]);
			} while ((NumList[i] < 8 ) || (NumList[i] > 15));
		}

		// Sort Numbers in order and Print to Screen
		temp = 0;
		for (int i=0; i<5; i++) {
			for (int j=0; j<5; j++) {
				if (NumList[j] > NumList[j+1]) {
					temp = NumList[j];
					NumList[j] = NumList[j+1];
					NumList[j+1] = temp;
				}
			}
		}
		sum = 0;
		printf("\nYour delta numbers are: ");
		for (int i=0; i<6; i++) {
			printf("%d ", NumList[i]);
			sum = sum + NumList[i];
		}
		printf("\n");
		if (sum <= 50) {
			goAgain = 0;
		} else {
			printf("Input six numbers again until the sum is no greater than 50\n");
		}
	} while (goAgain == 1);

	// Randomly create a different sequence of the same six numbers
	for (int i=0; i<6; i++) {
		value = rand() % 6;
		if (NumList[i] != NumList[value]) {
			temp = NumList[i];
			NumList[i] = NumList[value];
			NumList[value] = temp;
		}
	}
	printf("Your final delta sequence is: ");
	for (int i=0; i<6; i++) {
		printf("%d ", NumList[i]);
	}
	return 0;
}
