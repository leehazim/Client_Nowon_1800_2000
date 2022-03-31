#include <stdio.h>

typedef struct tag_Person {
	char Name[20];
	union tag_Job {
		char SchoolName[20];
		char CompanyName[20];
	}JOB;
}PERSON, * LPPERSON;

int main(void) {

	PERSON a, b;
	strcpy(a.Name, "Lee");
	strcpy(a.JOB.SchoolName, "KoreaSchool");
	strcpy(b.Name, "Lim");
   	strcpy(b.JOB.CompanyName, "StrongCompany");
	printf("a 이름 : %s, JOB : %s\n", a.Name, a.JOB.SchoolName);
	printf("b 이름 : %s, JOB : %s\n", b.Name, b.JOB.CompanyName);

	return 0;
}