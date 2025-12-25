#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char answers[10];
} BitVect;

void setAnswer(BitVect* profile, int index, int value);
int getAnswer(BitVect profile, int index);
int countYesAnswers(BitVect profile);
void printAnswers(BitVect profile);
int compareProfiles(BitVect a, BitVect b);

BitVect unionProfiles(BitVect a, BitVect b);
BitVect intersectProfiles(BitVect a, BitVect b);
BitVect differenceProfiles(BitVect a, BitVect b);

int main() {
    BitVect inie = {0};
    BitVect jobo = {0};

    setAnswer(&inie, 0, 1); // Q1: Yes
    setAnswer(&inie, 1, 1); // Q2: Yes
    setAnswer(&inie, 3, 1); // Q4: Yes
    setAnswer(&inie, 5, 1); // Q6: Yes
    setAnswer(&inie, 8, 1); // Q9: Yes
    setAnswer(&jobo, 0, 1); // Q1: Yes
    setAnswer(&jobo, 2, 1); // Q3: Yes
    setAnswer(&jobo, 4, 1); // Q5: Yes
    setAnswer(&jobo, 5, 1); // Q6: Yes
    setAnswer(&jobo, 6, 1); // Q7: Yes
    setAnswer(&jobo, 7, 1); // Q8: Yes

    printf("Inie's answers: ");
    printAnswers(inie);

    printf("Jobo's answers: ");
    printAnswers(jobo);

    printf("\nMatching answers: %d\n", compareProfiles(inie, jobo));

    printf("Jobo answered %s to question %d\n",(getAnswer(jobo,0))?"yes":"no",1);
    printf("Jobo answered %s to question %d\n",(getAnswer(jobo,1))?"yes":"no",2);
    printf("Inie said yes to %d questions\n\n", countYesAnswers(inie));

	BitVect unionSet = unionProfiles(inie, jobo);
	BitVect intersectSet = intersectProfiles(inie, jobo);
	BitVect diffSet = differenceProfiles(inie, jobo);

	printf("Union:        "); printAnswers(unionSet);
	printf("Intersection: "); printAnswers(intersectSet);
	printf("Difference:   "); printAnswers(diffSet);

	return 0;
}

void setAnswer(BitVect* profile, int index, int value) {
	
	int i;
	for(i=0;i<10;i++) {
		profile->answers[index] = value; 
	}
	
}
int getAnswer(BitVect profile, int index) {
	
	int answer = profile.answers[index];
	
	return answer;
}
int countYesAnswers(BitVect profile) { 

   int count= 0;
   
   int i;
   for(i=0;i<10;i++) {
   	if(profile.answers[i] == 1) {
   		count++;
	   }
   }
   
   return count;
   
   
}
void printAnswers(BitVect profile) {
	
	int i;
	for(i=9;i>=0;i--) {
		printf("%d",profile.answers[i]);
	}
	printf("\n");
}

int compareProfiles(BitVect a, BitVect b) {
	
	int count = 0;
	int i;
	for(i=0;i<10;i++) {
		if(a.answers[i]== b.answers[i]) {
			count++;
		}
	
}
	return count; 

}
	

BitVect unionProfiles(BitVect a, BitVect b) {
	
	BitVect Union;
	
	int i;
	
	for(i=0;i<10;i++) {
	    Union.answers[i] = a.answers[i] | b.answers[i];	
	}
	return Union;
}
BitVect intersectProfiles(BitVect a, BitVect b) {
	
	BitVect intersect;
	
	int i;
		for(i=0;i<10;i++) {
	    intersect.answers[i] = a.answers[i] & b.answers[i];	
	}
	return intersect;
}
BitVect differenceProfiles(BitVect a, BitVect b) {
	
	BitVect difference;
	int i;
		for(i=0;i<10;i++) {
	    difference.answers[i] = a.answers[i] &~ b.answers[i];	
	}
	return difference;
}
