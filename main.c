#include <stdio.h>

#define curr students[i]
#define CLEAR clb();

typedef struct{
	char name[30];
	char surname[30];
	int writtenScore;
	int spokenScore;
	int practicalScore;
	int finalScore;
}Student;

int average(int,int,int);
void clb();
void printStudentData(Student[],int);

int main(){
	setbuf(stdout,NULL);

	Student students[300];

	int amount = 0;
	do{
		printf("Inserisci il numero di studenti: ");
		scanf("%d",&amount);
		CLEAR
	}while(amount < 1 || amount > 300);

	//Reading student data
	for(int i = 0; i < amount; i++){
		curr.writtenScore = 0;
		curr.spokenScore = 0;
		curr.practicalScore = 0;

		printf("\nInserisci il nome dello studente %d: ",i+1);
		fgets(curr.name,30,stdin);
		printf("Inserisci il cognome dello studente %d: ",i+1);
		fgets(curr.surname,30,stdin);
		printf("Inserisci il voto scritto dello studente %d: ",i+1);
		scanf("%d",&curr.writtenScore);
		CLEAR
		printf("Inserisci il voto orale dello studente %d: ",i+1);
		scanf("%d",&curr.spokenScore);
		CLEAR
		printf("Inserisci il voto pratico dello studente %d: ",i+1);
		scanf("%d",&curr.practicalScore);
		CLEAR

		curr.finalScore = average(curr.practicalScore,curr.spokenScore,curr.writtenScore);
	}

	//Printing student data
	printf("\n-----------\n");
	printStudentData(students,amount);
}

int average(int n1, int n2, int n3){
	return (n1+n2+n3)/3;
}

//22-10-2018, simple stdin buffer cleaner from high school
void clb()
{
    while(getchar() != '\n') {}
}

void printStudentData(Student students[], int amount){
	for(int i = 0; i < amount; i++){
		printf("%s %s - Media: %d\n",curr.name,curr.surname,curr.finalScore);
	}
}
