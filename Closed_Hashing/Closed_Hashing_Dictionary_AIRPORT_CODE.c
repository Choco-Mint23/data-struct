#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

typedef struct {
	char code[4];
	int next;
	
}node; 

typedef struct {
     node table[MAX];
     int Avail;
}Dictionary;

typedef int List;
int allocSpace(Dictionary *D);
void insert(Dictionary *D, char code[4]);
void initialize(Dictionary *D);
void display(Dictionary *D);

int main() {

	Dictionary D;
	
    initialize(&D);
    insert(&D,"JFK");
    insert(&D,"LAX");
    insert(&D,"SFO");
    insert(&D,"CDG");
    insert(&D,"LHR");
    insert(&D,"NRT");
    insert(&D,"ATL");
    insert(&D,"DXB");
    insert(&D,"PEK");
    insert(&D,"MIA");
    insert(&D,"SYD");
    insert(&D,"ORD");
    
    display(&D);
    return 0;
}



void initialize(Dictionary *D) {
	  
	D->Avail =  MAX/2;
	int i;
	int j;
	for(i=0;i<10;i++) {
		D->table[i].code[0] = '\0';
		D->table[i].next = -1;
	}
	
	for(j=10;j<20;j++) {
		D->table[j].code[0] = '\0';
		D->table[j].next = j+1;
	}
	
	D->table[MAX-1].next = -1;
	
	
}
int hash(char code[3]) {
    
    int index = (code[0]-'A') *26 *26 + (code[1]-'A') *26 + (code[2]-'A');
	return index%10;
}
int allocSpace(Dictionary *D) {
	
	int temp = D->Avail;
	if(temp!=-1) {
		D->Avail = D->table[temp].next;
	}
	return temp;
}
void insert(Dictionary *D, char code[4]) {
	
	int i = 0;
	int index = hash(code);
	if(D->table[index].code[0] == '\0') { // if empty ang kana na index
		strcpy(D->table[index].code,code);
		D->table[index].next = -1;
		return;
	} else { //if occupied ang index (collision) adto sa kung occupied 
		i = index;
		while(D->table[i].next!=-1) { //finds the  index of the  hash root where i chain ang new elem
			i = D->table[i].next;
		}
		int newIndex = allocSpace(D); // gives an index sa first available index sa secondary
	    strcpy(D->table[newIndex].code,code);
		D->table[newIndex].next = -1;
		D->table[i].next = newIndex; //chains the newly inserted element in the hash root
	}
	
}
void display(Dictionary *D) {
	int i;
	printf("INDEX\tCODE\tNEXT\n");
printf("-----------------------\n");

for (int i = 0; i < MAX; i++) {
    if (D->table[i].code[0] != '\0')
        printf("%d\t%s->%d\t%d\n", i, D->table[i].code,hash(D->table[i].code), D->table[i].next);
    else
        printf("%d\t-\t%d\n", i, D->table[i].next);
}
}


