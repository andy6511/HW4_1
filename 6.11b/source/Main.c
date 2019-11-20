#include <stdio.h> 
#include <stdlib.h> 
#define LEN 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void shakerSort(int*, int, int(*)(int, int));
int bubbleL2R(int* arr, int from, int to, int(*)(int, int));
int bubbleR2L(int* arr, int from, int to, int(*)(int, int));

void print(int*, int len);
int ascending(int, int);
int descending(int, int);

int main(void) {
	int number[LEN] = { 10, 9, 1, 2, 5, 3, 8, 7, 12, 11 };

	shakerSort(number, LEN, ascending);
	print(number, LEN);

	shakerSort(number, LEN, descending);
	print(number, LEN);

	return 0;
}

void shakerSort(int* number, int len, int(*compar)(int, int)) {
	int left, right;
	for (left = 0, right = len - 1;
		left < right;
		right = bubbleL2R(number, left, right, compar),
		left = bubbleR2L(number, left, right, compar));
}

int bubbleL2R(int* arr, int left, int right, int(*compar)(int, int)) {
	int i, swapped;
	for (i = left, swapped = left;
		i < right; i++) if (compar(arr[i + 1], arr[i]) < 0) {
		SWAP(arr[i + 1], arr[i]);
		swapped = i;
	}
	return swapped;
}

int bubbleR2L(int* arr, int left, int right, int(*compar)(int, int)) {
	int i, swapped;
	for (i = right, swapped = right;
		i > left; i--) if (compar(arr[i], arr[i - 1]) < 0) {
		SWAP(arr[i], arr[i - 1]);
		swapped = i;
	}
	return swapped;
}

void print(int* arr, int len) {
	int i;
	for (i = 0; i < len; i++) { printf("%d ", arr[i]); }
	printf("\n");
}

int ascending(int a, int b) { return a - b; }
int descending(int a, int b) { return -ascending(a, b); }