#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct student{
    int matric;
    char name[50];
    char email[50];
    int year;
    char phoneNumber[20];
	//char data;
	//char program[10];
	struct student *nextPtr;
	//struct listNode *nextPtr;

};

//typedef struct listNode ListNode;
//typedef ListNode*ListNodePtr;

typedef struct student studentList;
typedef studentList *StudentNodePtr;

/*void insert (ListNodePtr*sPtr , char value, char value2[10]);
char delete (ListNodePtr *sPtr, char value);
int isEmpty (ListNodePtr sPtr);
void printList (ListNodePtr currentPtr);
void instructions();*/

void insert(StudentNodePtr *sPtr, int sMatric, char sName[50], char sEmail[50], int sYear, char sPhoneNumber[20]);
int delete(StudentNodePtr *sPtr, int sMatric);
int isEmpty(StudentNodePtr sPtr);
void displaylist(StudentNodePtr currentPtr);
void instructions();
int update(StudentNodePtr *sPtr, int sMatric, char sName[50], char sEmail[50], int sYear, char sPhoneNumber[20]);

int main(){
	StudentNodePtr startPtr = NULL;
	unsigned int choice;
	char item,item2[10];

	int sMatric;
	char sName[50];
    char sEmail[50];
    int sYear;
    char sPhoneNumber[20];

	instructions();
	printf("%s","Selection Menu >> ");
	scanf("%u",&choice);

	while (choice !=4){

		switch (choice){
			case 1:
				printf("\n\n%s","Enter Student Matric Number:");
				scanf("\n%d",&sMatric);
				printf("%s","Enter a Student Name:");
				scanf("\n%s",&sName);
				printf("%s","Enter a Student Email:");
				scanf("\n%s",&sEmail);
				printf("%s","Enter Student Year:");
				scanf("\n%d",&sYear);
				printf("%s","Enter a Student Phone Number:");
				scanf("\n%s",&sPhoneNumber);
				insert(&startPtr, sMatric, sName, sEmail, sYear, sPhoneNumber);
				displayList(startPtr);
				break;
			case 2 :
			    if (!isEmpty(startPtr)){
			    	printf("Enter student ID to be deleted: ");
			    	scanf("%d",&sMatric);

			    	if(delete(&startPtr, sMatric)){
			    		printf("\n%d deleted.\n", sMatric);
			    		displayList(startPtr);

					}else{
					printf("\n%d not found/\n\n", sMatric);
					}
				}else{
					puts("\nList is empty");
				}
				break;
            case 3 :
                if (!isEmpty(startPtr)){
			    	printf("Enter student ID to be updated: ");
			    	scanf("%d",&sMatric);

			    	if(delete(&startPtr, sMatric)){
			    		//printf("%d deleted.\n", sMatric);
			    		printf("%s","Update Student Name:");
                        scanf("\n%s",&sName);
                        printf("%s","Update Student Email:");
                        scanf("\n%s",&sEmail);
                        printf("%s","Update Student Year:");
                        scanf("\n%d",&sYear);
                        printf("%s","Update Student Phone Number:");
                        scanf("\n%s",&sPhoneNumber);
                        update(&startPtr, sMatric, sName, sEmail, sYear, sPhoneNumber);
			    		displayList(startPtr);
			    		printf("\n%d Updated.\n", sMatric);


					}else{
                        printf("\n%d cannot updated. Matric number given is not exist.\n\n", sMatric);
					}
				}else{
					puts("List is empty");
				}
				break;
			default:
			    puts("Invalid choice.\n");
				instructions();
				break;


		}
		printf("%s","Selection Menu >> ");
		scanf("%u", &choice);

	}
	puts("End of run.");
}
void instructions(){
	/*puts("Enter your choice:\n"
	" 1. to insert an element into the list.\n"
	" 2 to delete an element from the list.\n"
	" 3 to end.");*/

	printf("----------------------------------------------------");
	printf("\nCLUB MEMBER REGISTRATION SYSTEM FOR IT CLUB FSKTM");
	printf("\n---------------------------------------------------");
	puts("\n Enter your choice: \n"
	" 1. Insert Student Information.\n"
	" 2. Delete Student ID.\n"
	" 3. Update Student Information.\n 4. Close Program");
}

/*void insert(ListNodePtr *sPtr, char value,char value2[10]){
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;

	newPtr=malloc(sizeof(ListNode));

	if (newPtr != NULL){
		newPtr ->data=value;
		strcpy(newPtr->program,value2);
		newPtr ->nextPtr = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;

		while(currentPtr !=NULL && strcmp(value2,currentPtr->program)>=0){
			previousPtr =currentPtr;
			currentPtr = currentPtr->nextPtr;

		}
		if (previousPtr == NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else {
			previousPtr->nextPtr=newPtr;
			newPtr->nextPtr=currentPtr;
		}

	}
	    else {
	    	printf("%c not inserted. No memory available.\n", value);
	    }
} //not use */

void insert(StudentNodePtr *sPtr, int sMatric, char sName[50], char sEmail[50], int sYear, char sPhoneNumber[20])
{

    StudentNodePtr newPtr;
    StudentNodePtr previousPtr;
    StudentNodePtr currentPtr;

	newPtr=malloc(sizeof(studentList));
	if(newPtr!=NULL){
		newPtr->matric=sMatric;
		//newPtr->name = malloc(strlen(sName)+1);
		strcpy(newPtr->name,sName);
		//newPtr->email = malloc(strlen(sEmail)+1);
		strcpy(newPtr->email,sEmail);
		newPtr->year=sYear;
		strcpy(newPtr->phoneNumber,sPhoneNumber);
		newPtr->nextPtr=NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr !=NULL){
			previousPtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
		}
		if(previousPtr == NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}else {
			previousPtr->nextPtr=newPtr;
			newPtr->nextPtr=currentPtr;
		}
    }else{
        printf("%s not inserted. no memory available. \n",sName);
    }
}

/*char delete (ListNodePtr *sPtr, char value){
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	ListNodePtr tempPtr;

	if(value==(*sPtr)->data){
		tempPtr = *sPtr;
		*sPtr = (*sPtr)->nextPtr;
		free(tempPtr);
		return value;

	}
	else{
		previousPtr= *sPtr;
		currentPtr = (*sPtr)->nextPtr;

		while(currentPtr !=NULL && currentPtr->data != value){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if(currentPtr != NULL){
			tempPtr = currentPtr;
			previousPtr ->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return value;
		}//end if
	}//end else
	return '\0';
}*/

int delete (StudentNodePtr *sPtr, int sMatric){

    StudentNodePtr previousPtr;
    StudentNodePtr currentPtr;
    StudentNodePtr tempPtr;

	if (sMatric==(*sPtr)->matric){
		tempPtr=*sPtr;
		*sPtr=(*sPtr)->nextPtr;
		free(tempPtr);
		return sMatric;
	}else{
		previousPtr=*sPtr;
		currentPtr=(*sPtr)->nextPtr;

		while(currentPtr !=NULL && currentPtr->matric != sMatric){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if(currentPtr != NULL){
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return sMatric;
		}
	}
	return '\0';

}

/*int isEmpty(ListNodePtr sPtr){
	return sPtr ==NULL;
}*/

int isEmpty(StudentNodePtr sPtr){
    return sPtr == NULL;
}

 /*void printList(ListNodePtr currentPtr)  {
      if (isEmpty(currentPtr)){
      	puts("List is empty.\n");
	  }
	  else{
	  	puts("The list is : ");

	  	while (currentPtr !=NULL){
	  		printf("[%c,%s] ->",currentPtr->data,currentPtr->program);
	  		currentPtr =currentPtr->nextPtr;
		  }

		  puts("NULL\n");
	  }
}*/

void displayList(StudentNodePtr currentPtr)
{
	if(isEmpty(currentPtr)){
		puts("\n\nList is empty.\n");
	}else{
		puts("\n\nThe list is: ");

		while (currentPtr != NULL){
			printf("\nStudent Matric-> %d \nStudent Name -> %s \nStudent Email -> %s \nStudent Year -> %d \nStudent Phone Number -> %s \n", currentPtr->matric,currentPtr->name,currentPtr->email, currentPtr->year, currentPtr->phoneNumber);
			currentPtr = currentPtr->nextPtr;
		}
		puts("Next \n");
	}
}

//UPDATE DATA
//https://www.tutorialspoint.com/learn_c_by_examples/linked_list_update_program_in_c.htm
/*void update_data(int old, int new) {
   int pos = 0;

   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   }

   current = head;
   while(current->next!=NULL) {
      if(current->data == old) {
         current->data = new;
         printf("\n%d found at position %d, replaced with %d\n", old, pos, new);
         return;
      }

      current = current->next;
      pos++;
   }

   printf("%d does not exist in the list\n", old);
}*/

int update(StudentNodePtr *sPtr, int sMatric, char sName[50], char sEmail[50], int sYear, char sPhoneNumber[20])
{
    StudentNodePtr newPtr;
    StudentNodePtr previousPtr;
    StudentNodePtr currentPtr;

	newPtr=malloc(sizeof(studentList));
	if(newPtr!=NULL){
		newPtr->matric=sMatric;
		//newPtr->name = malloc(strlen(sName)+1);
		strcpy(newPtr->name,sName);
		//newPtr->email = malloc(strlen(sEmail)+1);
		strcpy(newPtr->email,sEmail);
		newPtr->year=sYear;
		strcpy(newPtr->phoneNumber,sPhoneNumber);
		newPtr->nextPtr=NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr !=NULL){
			previousPtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
		}
		if(previousPtr == NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}else {
			previousPtr->nextPtr=newPtr;
			newPtr->nextPtr=currentPtr;
		}
    }else{
        printf("%s not inserted. no memory available. \n",sName);
    }

	return '\0';
}


/*int update(StudentNodePtr *sPtr, int sMatric)
{
    StudentNodePtr newPtr;
    StudentNodePtr previousPtr;
    StudentNodePtr currentPtr;

    StudentNodePtr previousPtr;
    StudentNodePtr currentPtr;
    StudentNodePtr tempPtr;

	if (sMatric==(*sPtr)->matric){
		newPtr=malloc(sizeof(studentList));
        if(newPtr!=NULL){
            newPtr->matric=sMatric;
            //newPtr->name = malloc(strlen(sName)+1);
            strcpy(newPtr->name,sName);
            //newPtr->email = malloc(strlen(sEmail)+1);
            strcpy(newPtr->email,sEmail);
            newPtr->year=sYear;
            strcpy(newPtr->phoneNumber,sPhoneNumber);
            newPtr->nextPtr=NULL;

            previousPtr = NULL;
            currentPtr = *sPtr;

            while (currentPtr !=NULL){
                previousPtr=currentPtr;
                currentPtr=currentPtr->nextPtr;
            }
            if(previousPtr == NULL){
                newPtr->nextPtr = *sPtr;
                *sPtr = newPtr;
            }else {
                previousPtr->nextPtr=newPtr;
                newPtr->nextPtr=currentPtr;
            }
        }else{
            printf("%s not inserted. no memory available. \n",sName);
        }
	}else{
		previousPtr=*sPtr;
		currentPtr=(*sPtr)->nextPtr;

		while(currentPtr !=NULL && currentPtr->matric != sMatric){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if(currentPtr != NULL){
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return sMatric;
		}
	}
	return '\0';


}*/
