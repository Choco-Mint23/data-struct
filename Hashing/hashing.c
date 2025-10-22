#include <stdio.h>


typedef struct {
	char colorName;
	int RGBval[3];
	
}Color;


int hash(int r, int g, int b);
int main() {
	
	
	
}

int hash(int r, int g, int b) {
	
	return (r*3 + g*5 + b*7)%64;  //multiply by prime numbers to avoid collision
	
}
