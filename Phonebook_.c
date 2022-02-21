#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct contacts{
        char *Name;
        char *phoneNumber;
        char *address;
        char *mailId;
};

struct contacts contact;

char *getstring()
{
        char *ptr = NULL;
        int i=0;
        do{
                ptr     = realloc(ptr,i+1);
                ptr[i]  = getchar();
        }while(ptr[i++]!='\n');
        ptr[i-1] = '\0';
        return ptr;
}


void AddNewContact()
{
	FILE *fp;
	char ch = 32;
	char ch1 = '\n';
	fp = fopen("contacts.txt","a");

	printf("enter the name:");
	contact.Name = getstring();
	
	fputs(contact.Name,fp);
	fputc(ch,fp);
	
	printf("enter the phonenumber:");
	contact.phoneNumber = getstring();
	
	fputs(contact.phoneNumber,fp);
	fputc(ch,fp);

	
	printf("enter the address:");
        contact.address=getstring();
	
	fputs(contact.address,fp);
	fputc(ch,fp);

	
	printf("enter the email id:");
        contact.mailId = getstring();
	
	fputs(contact.mailId,fp);
	fputc(ch1,fp);

	fclose(fp);

}
void DisplayContacts()
{
	
	char *str;
        int size;
        int i = 0;
        FILE *fp;
        fp = fopen("contacts.txt","r");
        fseek(fp,0,2);
        size = ftell(fp)+1;
        rewind(fp);
        str = calloc(size,sizeof(int));
        fread(str,size-1,1,fp);
	for(i=0;str[i];i++)
        {
                printf("%c",str[i]);
        }
}
void SearchContact()
{
	FILE *fp;
        fp = fopen("contacts.txt","r");
	char line[100];
	char ContacttoSearch[30];
	printf("Enter The Contact Name You Want to Search\n");
	scanf("%s",ContacttoSearch);
	while(fgets(line,sizeof(line),fp))
        {
                if(strstr(line,ContacttoSearch))
                {
                        printf("%s",line);
                }

	 }
}
int main()
{
	while(1)
	{
		int choice;
		printf("*********PHONEBOOK*****\n");
		printf("1.ADDCONTACT\n");
		printf("2.DISPLAYCONTACTS\n");
		printf("3.SEARCHCONTACTS\n");
		printf("4.EXIT\n");
		printf("Enter Your Choice: \n");
		scanf("%d",&choice);
		if(choice == 1)
		 	AddNewContact();
		else if(choice == 2)
			DisplayContacts();
		else if(choice == 3)
			SearchContact();
		else if(choice == 4)
			exit(0);
		else
			printf("Wrong Choice...\n");

	}
}
