#include <stdio.h>

void insert(int arr[4][4],int row, int column);
void display(int arr[4][4]);
void initialize(int arr[4][4]);
int main() {
	
	int matrix[4][4];
	initialize(matrix);
	insert(matrix,0,1);
	insert(matrix,0,3);
	insert(matrix,1,2);
	insert(matrix,3,1);
	insert(matrix,3,2);
	insert(matrix,2,2);
	insert(matrix,1,3);
	display(matrix);
}
void initialize(int arr[4][4]) {
	
	
	int i;
	int j;
	for(i=0;i<4;i++) {
	for(j=0;j<4;j++) {
		arr[i][j] = 0;
	}
	
	}
}
void display(int arr[4][4]) {
	
	int i;
	int j;
	int k;

	 
	for(i=0;i<4;i++) {
	
		
	for(j=0;j<4;j++) {
	
		printf("%d|",arr[i][j]);
	}
	
	  printf("\n");
	  
	}
}
void insert(int arr[4][4],int row, int column) {
	
	arr[row][column] = 1;
}
