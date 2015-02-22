#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void swap(int *value1, int *value2){
	int temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

// Range: smallestInteger <= integer <= largestInteger
int getRandomInteger(int smallestInteger, int largestInteger){
	if(smallestInteger > largestInteger){
		swap(&smallestInteger, &largestInteger);
	}
	double random;
	do{
		random = (double)rand() / RAND_MAX;
	}while(random == 1);

	return smallestInteger + random * (largestInteger - smallestInteger + 1);
}

// Range: lowestIndex <= index <= highestIndex
// The pivot is always set the lowest index of this list partition
void runQuickSort(int list[], int lowestIndex, int highestIndex, bool applyRandom){
	if(lowestIndex >= highestIndex){
		return;
	}

	if(applyRandom){
		int pivotIndex = getRandomInteger(lowestIndex, highestIndex);
		swap(&list[lowestIndex], &list[pivotIndex]);
	}
	int pivotValue = list[lowestIndex];
	int pivotIndex = lowestIndex;

	for(int index = lowestIndex + 1; index <= highestIndex; index ++){
		if(list[index] < pivotValue){
			pivotIndex += 1;
			swap(&list[index], &list[pivotIndex]);
		}
	}
	swap(&list[lowestIndex], &list[pivotIndex]);

	//printf("%d\t%d\t%d\n", lowestIndex, pivotIndex, highestIndex);
	runQuickSort(list, lowestIndex, pivotIndex - 1, applyRandom);
	runQuickSort(list, pivotIndex + 1, highestIndex, applyRandom);
}

void assignDescendingList(int list[], int length){
	for(int i = 0; i < length; i ++){
		list[i] = length - i - 1;
	}
}

void printList(int list[], int length){
	for(int i = 0; i < length; i ++){
		printf("%d\t", list[i]);
	}
	printf("\n");
}

bool checkSortWorking(int list[], int length){
	for(int i = 1; i < length; i ++){
		if(list[i - 1] > list[i]){
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]){
	int length = atoi(argv[1]);
	bool applyRandom = (bool)atoi(argv[2]);

	srand(time(NULL));
	int list[length];
	
	assignDescendingList(list, length);

	runQuickSort(list, 0, length - 1, applyRandom);
	printf("%s\n", (checkSortWorking(list, length))? "OK": "Ohohoh");

	return 0;
}
