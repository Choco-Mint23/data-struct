#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char String[30];
typedef struct Node {
    String spell;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
}Set;

// Create a new empty set
Set* createSet();

// Add a spell to the set (no duplicates)
bool addSpell(Set* set, String spell);

// Remove a spell from the set
bool removeSpell(Set** set, String spell);

// Check if a spell exists in the set
bool containsSpell(Set* set, String spell);

// Print all spells in the set
void printSet(Set* set);

// Free all memory associated with the set
void destroySet(Set* set);

Set* unionSets(Set* set1, Set* set2);
Set* intersectSets(Set* set1, Set* set2);

int main() {
    String spell;
    Set* fireSpells = createSet();
    Set* waterSpells = createSet();

	strncpy(spell,"Flame Burst",12);
	spell[11]='\0';
	addSpell(fireSpells, spell);

	strncpy(spell,"Inferno",8);
	spell[7]='\0';
	addSpell(fireSpells, spell);

	strncpy(spell,"Aqua Jet",9);
	spell[8]='\0';
	addSpell(waterSpells, spell);

	strncpy(spell,"Inferno",8);
	spell[7]='\0';
	addSpell(waterSpells, spell);

	Set* commonSpells = intersectSets(fireSpells, waterSpells);
	Set* allSpells = unionSets(fireSpells, waterSpells);

	printf("Common Spells:\n");
	printSet(commonSpells);

	printf("\nAll Spells:\n");
	printSet(allSpells);

	strncpy(spell,"Aqua Jet",9);
	spell[8]='\0';
	removeSpell(&allSpells,spell);

	printf("\nAll Spells:\n");
	printSet(allSpells);

	destroySet(fireSpells);
	destroySet(waterSpells);
	destroySet(commonSpells);
	destroySet(allSpells);

return 0;
}

Set* createSet() {
	
	Set *ptr = malloc(sizeof(Set));
	ptr->head = NULL;
	ptr->size = 0;
	
	return ptr;
}
bool addSpell(Set* set, char* spell) {
    
    if (containsSpell(set, spell)) {
        return 0; 
    }

    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->spell, spell);
    newNode->next = NULL;

    
    if (set->head == NULL || strcmp(spell, set->head->spell) < 0) { 
        newNode->next = set->head;
        set->head = newNode;
        set->size++;
        return 1;
    }

    
    Node* trav = set->head;
    while (trav->next != NULL && strcmp(trav->next->spell, spell) < 0) { //if what u want to insert comes after other nodes alphabetically
        trav = trav->next;
    }

    newNode->next = trav->next;
    trav->next = newNode;
    set->size++;

    return 1; 
}
		
bool removeSpell(Set** set, String spell) {
	
	
	
	if((*set)->head == NULL) {
		return 0;
	}
	Node *trav = (*set)->head;
	Node *prev = NULL;
	
	if(strcmp((*set)->head->spell,spell)==0) {
		Node *temp = (*set)->head;
		(*set)->head = (*set)->head->next;
		free(temp);
		(*set)->size--;
		return 1;
	}
	
	
	while(trav!=NULL) {
		if(strcmp(trav->spell,spell)==0) {
			prev->next = trav->next;
			free(trav);
			(*set)->size--;
			return 1;
		} 	
		prev = trav;
		trav = trav->next;
	}
	return 0;
}

bool containsSpell(Set* set, String spell) {
	
	Node *trav = set->head;
	while(trav!=NULL) {
		if(strcmp(trav->spell,spell)==0) {
			return 1;
		}
		trav = trav->next;
	}
	return 0;
}
void printSet(Set* set) {
	int i = 1;
	Node *trav = set->head;
   while(trav!=NULL) {
   	printf("  %d. %s\n",i,trav->spell);
   	trav = trav->next;
   	i++;
   }	
}
void destroySet(Set* set) {
	
	Node *trav = set->head;
	Node *temp;
	while(trav!=NULL) {
		temp = trav;
		trav = trav->next;
		free(temp);
	}
}
Set* unionSets(Set* set1, Set* set2) {
	Set *set3 = createSet();
	
	Node *trav1 = set1->head;
	Node *trav2 = set2->head;
	
	while(trav2!=NULL) {
		addSpell(set3,trav2->spell);
		trav2 = trav2->next;
	}
	
	while(trav1!=NULL) {
		addSpell(set3,trav1->spell);
		trav1 = trav1->next;
	}
	
	
	
	return set3;
}
Set* intersectSets(Set* set1, Set* set2) {
	
	Set *set3 = createSet();
	int i;
	
Node *trav1 = set1->head;

while (trav1 != NULL) {
   
   Node *trav2 = set2->head;

    while (trav2 != NULL) {
    	
    	if(strcmp(trav1->spell,trav2->spell)==0) {
    	addSpell(set3,trav1->spell);
    	break;
	}
        
        trav2 = trav2->next;
    }

    trav1 = trav1->next;
}

 return set3;
}

	
	
	
