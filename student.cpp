#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct student{
	char Name[15];
	int Age;
	char Gender[8];
	char Grades[5];
	char Address[100];
	char Id[4];
};
//function to add student 
void addstudent(){
	struct student studentdata;
	int valid=0,j;
	//Name
	do{
	valid=1;
	printf(" \n ENTER YOUR NAME : ");
	scanf("%[^\n]",studentdata.Name);
	getchar();
	for(j=0;studentdata.Name[j]!='\0';j++){
		if(studentdata.Name[j]>'0'&& studentdata.Name[j]<'9'){
		printf("\n PLEASE ONLY WRITE ALPHACHARACTERS\n");
	valid=0;
	break;
	}	
	}
}while(!valid);
//AGe
	printf(" \n ENTER YOUR AGE: ");
	scanf("%d",&studentdata.Age);
	getchar();
	//ID
	printf(" \n ENTER YOUR ID: ");
	scanf("%[^\n]",studentdata.Id);
	getchar();
//GENDER
	printf(" \n ENTER YOUR GENDER: ");
	scanf("%[^\n]",studentdata.Gender);
	getchar();
//GRADES
	printf(" \n ENTER YOUR GRADES: ");
	scanf("%[^\n]",studentdata.Grades);
	getchar();
//ADDRESS
	printf(" \n ENTER YOUR ADDRESS: ");
	scanf("%[^\n]",studentdata.Address);
	getchar();
//SAve to FILE 
FILE *file=fopen("studentdata.txt","a+");
if(file==NULL){
	perror(" \n ERROR CREATING FILE \n");
	return;
}
    fprintf(file, "%s,%d,%s,%s,%s,%s\n",
    studentdata.Name, studentdata.Age, studentdata.Id,
     studentdata.Gender, studentdata.Grades, studentdata.Address);

    fclose(file);
printf("FILE SAVED SUCCESSFULLY \n");
}

//SEARCH FOR A STUDENT IN A FILE 
void searchforstudent(){
	struct student studentdata;
	char search[10];
	char line[256];
	int found=0;
	
	
	printf("SEARCH FOR A STUDENT :\n ID :\n ");
scanf("%s",search);
getchar();
FILE *file=fopen("studentdata.txt","r");
if(file==NULL){
	perror("ERROR\n");
	return;
}
while(fgets(line,sizeof(line),file)){
sscanf(line,"%[^,],%d,%[^,],%[^,],%[^,],%[^\n]",studentdata.Name,&studentdata.Age,studentdata.Id,studentdata.Gender,studentdata.Grades,studentdata.Address);
if(strcmp(search,studentdata.Id)==0){
printf("NAME:  %s \n",studentdata.Name);
printf("AGE:  %d \n",studentdata.Age);
printf("ID: %s \n",studentdata.Id);
printf("GENDER:  %s \n",studentdata.Gender);
printf("GRADES:  %s \n",studentdata.Grades);
printf("ADDRESS: %s \n",studentdata.Address);
found=1;
}
}

fclose(file);
if(!found){
	printf("Error Student not found \n");
	return;
}
}
int main(){
	int choice;
do{
printf("\n WELCOME TO OUR PROGRAM \n");
printf("\n PLEASE SELECT THE OPTIONS BELOW \n");
printf("\n 1.ADD STUDENT \n");
printf("\n 2.SEARCH FOR STUDENT \n");
printf("\n 3.EXIT \n");
scanf("%d",&choice);
getchar();


switch (choice){
	case 1:
		printf("ADDING STUDENT \n");
		addstudent();
		break;
	case 2:
		printf("SEARCH STUDENT \n");
	    searchforstudent();
	    break;
	case 3:
		printf("EXITING PROGRAM \n");
		break;
	default:
		printf("PLEASE ENTER VALID OPTION");
}
}while(choice!=3);

	return 0;
}
