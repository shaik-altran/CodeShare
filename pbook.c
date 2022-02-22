#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct contactbook
{
	char firstname[30];
	char lastname[30];
	char mobileno[12];
	char company[30];
        struct contactbook *next;
}CB;
void addcontacts(CB**);
void displaycontacts(CB*);
void searchcontacts(CB*);
void modifycontacts(CB*);
void deletecontacts(CB**);
int main()
{
   int select;
   char choice;
   CB *hptr=0;
      do{
	    printf("\n1.Add contacts in phonebook.\n2.display all contacts.\n3.search contact in phonebook.\n4.modify contact from contact list\n5.delete contact.\n6.Exit from phonebook\n");
	    printf("\nselect the operation which you want to perform on phonebook....");
	    scanf("%d",&select);
	    switch(select)
	    {
		case 1:do{
		            addcontacts(&hptr);
			       printf("Do you want to add more contacts in a contact list(y/n).....");
			       scanf(" %c",&choice);
			    }while((choice=='y')||(choice=='Y'));	
			  break;		
		case 2:    
                           if(hptr==0)
	                   {
                               printf("\ntheir is no contacts available in phonebook..please add contacts in list.....\n");
	                          break;
	                   }
			  displaycontacts(hptr);
			  break;
		case 3:			
			   if(hptr!=0)
			   {
				 do
				 {
			          searchcontacts(hptr);
				  printf("\nDo you want to continue with searching contact(y/n)....");
				  scanf(" %c",&choice);
				 }while((choice=='y')||(choice=='Y'));
			   }
		           else
			   {    
				printf("\nphone book is empty,please add contacts in a list.....");
			   }
			         break;
		case 4:if(hptr!=0)
		       {
			 do{
			     modifycontacts(hptr);
			     printf("Do you want to modify another contact(y/n)..... ");
			     scanf(" %c",&choice);
			   }while((choice=='y')||(choice=='Y'));
		       }
		       else
		       {
			     printf("\nphone book is empty,please add contacts in a list.....\n");
		       }
			    break;
		case 5:if(hptr!=0)
                       {
                          do{
			       deletecontacts(&hptr);
			       printf("\nDo you want to delete any other cantact or you want to delete by other opiton....(y/n)");
			       scanf(" %c",&choice);
			    }while((choice=='y')||(choice=='Y'));
		       }
		       else
		       {
			    printf("\nphone book is empty,please add contacts in a list.....\n"); 
		       }
			 break;
	        case 6:
			 exit(0);
                default:
			printf("enter right operation number from menu which you want to perform......");
	    }
	    printf("\nDo you want to perform more operations from menu(y/n).....");
	    scanf(" %c",&choice);          
	}while((choice=='y')||(choice=='Y'));	
}

void addcontacts(CB **ptr)
{
	CB *temp,*last;
	temp=(CB*)malloc(sizeof(CB));
	printf("Enter contact details as a first name,last name,mobile number,company name.....");
	scanf("%s%s%s%s",&temp->firstname,&temp->lastname,&temp->mobileno,&temp->company);
	if(*ptr==0)
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		last=*ptr;
		while(last->next!=0)
		  last=last->next;

		temp->next=last->next;
		last->next=temp;
	}
}

void searchcontacts(CB *ptr)
{   
	char fname[30],lname[30],mobile[12];
	CB *kptr,*sptr;
	int count=0,option;
        char choice;
	printf("\n1.first name\n2.last name\n3.mobile number.");
	printf("\nFor search contact choose above options....");
	scanf("%d",&option);
	
	switch(option)
	{
		case 1:
			kptr=ptr;
			count=0; 
			printf("\nenter the first name...");
			scanf("%s",fname);
			
			while(kptr!=0)
			{	
			   if(strcmp(kptr->firstname,fname)== 0)
			   {
				count++;
				kptr=kptr->next;
			   }
                           else
			   {
				kptr=kptr->next;
			   }
			}

			if(count>1)
			{
			    printf("\nfirst name is present %d times in contact list try to search by other option...  ",count);
			}
			else if(count==1)
			{
			     kptr=ptr;
			     while(kptr!=0)
			     {
				 if(strcmp(kptr->firstname,fname) == 0)
				 {
				      printf("%s\t%s\t%s\t%s\t\n",kptr->firstname,kptr->lastname,kptr->mobileno,kptr->company);
		                      kptr=kptr->next;
				 }
			         else
				 {
				      kptr=kptr->next;
				 }
			     }
			}
			else
			{
			     printf("\nentered first name is not present in contact list search by other option....\n");
			}
				break;

		case 2:
			sptr=ptr;
			count=0;
			printf("\nenter the last name...");
			scanf("%s",lname);
		
			while(sptr!=0)
			{
			    if(strcmp(sptr->lastname,lname)== 0)
			    {
				count++;
			        sptr=sptr->next;
			    }
			    else
			     {
				sptr=sptr->next;
			     }
			}

			if(count>1)
			{
			     printf("last name is present %d times in contact list try to search by other option...  ",count);
			}
			else if(count==1)
			{
			     sptr=ptr;
			     while(sptr!=0)
			    {
				if(strcmp(sptr->lastname,lname) == 0)
				 {
				      printf("%s\t%s\t%s\t%s\t\n",sptr->firstname,sptr->lastname,sptr->mobileno,sptr->company);
		                      sptr=sptr->next;
				 }
				else
				 {
				      sptr=sptr->next;
				 }
			    }

			}
			else
			{
			     printf("\nentered last name is not present in contact list search by other option....\n");
			}
				break;
			
		  case 3:
			sptr=ptr;
			count=0;
			printf("\nenter the mobile number...");
			scanf("%s",mobile);
		
			     while(sptr!=0)
			    {
				if(strcmp(sptr->mobileno,mobile) == 0)
				 {
					count++;
				      printf("%s\t%s\t%s\t%s\t\n",sptr->firstname,sptr->lastname,sptr->mobileno,sptr->company);
		                      sptr=sptr->next;
				 }
				else
				 {
				      sptr=sptr->next;
				 }
			    }

			     if(count==0)
			     {
			     printf("\nentered mobile number is not present in contact list search by other option...\n.");
			     }
			     break;
		default:
			     printf("please enter correct option....\n");
	}
}


void modifycontacts(CB *ptr)
{
	CB *temp;
	int option,count,count1,rn=0;
	char fname[30],f_name[30],lname[30],l_name[30],mobile[12],m_obile[12],cname[30],c_name[30];
	printf("\n1.first name\n2.last name\n3.phonebook\n4.company.\nenter option..");
	scanf("%d",&option);
	switch(option)
	{
		case 1: 
			count=0;
			count1=0;
			rn=0;
			printf("\nenter the first name  from list to modify....");
			scanf("%s",fname);
			printf("\nenter the name which you want to replace with....");
			scanf("%s",f_name);
                        temp=ptr;
			while(temp!=0)
			{
				if(strcmp(temp->firstname,fname)==0)
				{
					count++;
					temp=temp->next;
				}
				else
				{
					temp=temp->next;
				}
			}
			//printf("%d\n ",count);
			if(count>1)
			{
				int rn=0;
				temp=ptr;
				while(temp!=0)
			        {
				     if(strcmp(temp->firstname,fname)==0)
				     {
					 rn++;
					 printf("\n%d.%s\t%s\t%s\t%s\t\n",rn,temp->firstname,temp->lastname,temp->mobileno,temp->company);
					 temp=temp->next;
				     }
				     else
				     {
					temp=temp->next;
				     }
			        }
				printf("\nfirst name is available %d times in contacts,enter record no from above which you want to modify...",rn);
				scanf("%d",&rn);
				temp=ptr;
				while(temp!=0)
			        {
				     if(strcmp(temp->firstname,fname)==0)
				     {
					    count1++;
					    if(count1==rn)
					    {
					       strcpy(temp->firstname,f_name);
					       temp=temp->next;	
					    }
					    else
					    {
						temp=temp->next;	
					    }	
					  
				     }
				     else
				     {
					  temp=temp->next;
				     }
			        }
				printf("contact has been modify successfully.....");
			}
			else if(count==1)
			{
				while(temp!=0)
			        {
				     if(strcmp(temp->firstname,fname)==0)
				     {
					     strcpy(temp->firstname,f_name);
					     temp=temp->next;	
				     }
				     else
				     {
					  temp=temp->next;
				     }
			        }
				 printf("contact has been modify successfully.....");
			}
			else
			{
				printf("\nfirst name is not present in a contacts!try again....\n");
			}
				break;
                case 2:			
			count=0;
			rn=0;
			count1=0;
			temp=ptr;
			printf("\nenter the last name from a list....");
			scanf("%s",lname);
			printf("\nenter the name which you want to replace with....");
			scanf("%s",l_name);
			while(temp!=0)
			{
				if(strcmp(temp->lastname,lname)==0)
				{
					count++;
					temp=temp->next;
				}
				else
				{
					temp=temp->next;
				}
			}
			//printf("%d\n ",count);
			if(count>1)
			{
			        rn=0;
				temp=ptr;
				while(temp!=0)
			        {
				     if(strcmp(temp->lastname,lname)==0)
				     {
					 rn++;
					 printf("%d.%s\t%s\t%s\t%s\t\n",rn,temp->firstname,temp->lastname,temp->mobileno,temp->company);
					 temp=temp->next;
				     }
				     else
				     {
					temp=temp->next;
				     }
			        }
				printf("\nlast name is available %d times in contacts,enter record no from below which you want to modify...",rn);
				scanf("%d",&rn);
				temp=ptr;
				count1=0;
				while(temp!=0)
			        {
				     if(strcmp(temp->lastname,lname)==0)
				     {
					  count1++;
					  if(count1==rn)
					  {
					     strcpy(temp->lastname,l_name);
					     temp=temp->next;	
					  }
					  else
					  {	
					     temp=temp->next;
					  }
				     }
				     else
				     {
					  temp=temp->next;
				     }
			        }
				printf("contact has been modify successfully.....");
			}
			else if(count==1)
			{
				while(temp!=0)
			        {
				     if(strcmp(temp->lastname,lname)==0)
				     {
					     strcpy(temp->lastname,l_name);
					     temp=temp->next;	
			             }
				     else
				     {
					     temp=temp->next;
				     }
			        }
				printf("contact has been modify successfully.....");
			}
			else
			{
				printf("\nlast name is not present in a contacts!try again....\n");
			}
				break;
		case 3:
			count=0;
			temp=ptr;
			printf("\nenter the mobile nummber from list to change....");
			scanf("%s",mobile);
			printf("\nenter the mobile nummber you want to replace with....");
			scanf("%s",m_obile);
			while(temp!=0)
			{
				if(strcmp(temp->mobileno,mobile)==0)
				{
					count++;
					strcpy(temp->mobileno,m_obile);
					temp=temp->next;
				}
				else
				{
					temp=temp->next;
				}
			}
			if(count==0)
			{
				printf("\nmobile number is not present in a contacts!try again....\n");
			}
			else
			{
				printf("contact has been modify successfully.....");
			}
			break;
		case 4:
			count=0;
			rn=0;
			count1=0;
			temp=ptr;
			printf("\nenter the company name from  list to change....");
			scanf("%s",cname);
			printf("\nenter the company name which you want to replace with....");
			scanf("%s",c_name);
			while(temp!=0)
			{
				if(strcmp(temp->company,cname)==0)
				{
					count++;
					temp=temp->next;
				}
				else
				{
					temp=temp->next;
				}
			}
			//printf("%d\n ",count);
			if(count>1)
			{
				temp=ptr;
				while(temp!=0)
			        {
				     if(strcmp(temp->company,cname)==0)
				     {
					 rn++;
					 printf("%d.%s\t%s\t%s\t%s\t\n",rn,temp->firstname,temp->lastname,temp->mobileno,temp->company);
					 temp=temp->next;
				     }
				     else
				     {
					temp=temp->next;
				     }
			        }
				printf("\nfirst name is available %d times in contacts,enter record no from below which you want to modify...",rn);
				scanf("%d",&rn);
				temp=ptr;
				while(temp!=0)
			        {
				     if(strcmp(temp->company,cname)==0)
				     {
					  count1++;
					  if(count1==rn)
					  {
					      strcpy(temp->company,c_name);
					      temp=temp->next;
					  }
					  else
					  {
					      temp=temp->next;
					  }	
				     }
				     else
				     {
					  temp=temp->next;
				     }
			        }
				printf("contact has been modify successfully.....");
			}
			else if(count==1)
			{
				while(temp!=0)
			        {
				     if(strcmp(temp->company,cname)==0)
				     {
					     strcpy(temp->company,c_name);
					     temp=temp->next;	
			             }
				     else
				     {
					     temp=temp->next;
				     }
			        }
				printf("contact has been modify successfully.....");
			}
			else
			{
				printf("\ncompany name is not present in a contacts!try again....\n");
			}
			break;
			
	       default:
				printf("please enter right choice to modify....\n");
	}
}

void deletecontacts(CB **ptr)
{    
     char fname[30],lname[30],mobile[12];
     int option,count,rn,count1;
     printf("\n1.first name.\n2.last name.\n3.mobile number.\n");
     printf("\nEnter the option you want to delete by.....");
     scanf("%d",&option);
     CB *temp,*prev;

    switch(option)
    {
      case 1:
	     printf("Enter the first name:-");
	     scanf("%s",fname);
	     count=rn=0;
             prev=temp=*ptr;
	     while(temp!=0)
	     {
		 if(strcmp(temp->firstname,fname)==0)
		 {
                     count++;
		     temp=temp->next;
		 }
		 else
		 {
		      temp=temp->next;
		 }
	     }
	     if(count>1)
	     {     
		   temp=*ptr;
		   while(temp!=0)
		   {
			 if(strcmp(temp->firstname,fname)==0)
		         {
                               rn++;
			       printf("%d.%s\t%s\t%s\t%s\t\n",rn,temp->firstname,temp->lastname,temp->mobileno,temp->company);
			       temp=temp->next;
                         }
			 else
			 {
			     temp=temp->next;
			 }
                   }
		   printf("\nfirst name is present %d times in contact list please enter contact no from above list which you want to delete...",rn);
		   scanf("%d",&rn);
		   temp=*ptr;
		   count1=0;
                   while(temp!=0)
                   {
	                 if(strcmp(temp->firstname,fname)==0)
		         {
			      count1++;
			      if(temp==*ptr && count1==rn)
			      {
				  *ptr=temp->next;
				   printf("contact has been deleted successfully*****\n");
				   break;
			      }
			      else
			      {    
				   if(count1==rn)
				   {	
		                        prev->next=temp->next;
				        free(temp);
				        temp=NULL;
				        printf("contact has been deleted successfully*****\n");
				        break;
				   }
				   else
				   {
					prev=temp;
			                temp=temp->next;
				   }
			      }
		         }
		         else
		        {
                                   prev=temp;
			           temp=temp->next;
		        }	
                  }
            }
	    else if(count==1)
            {
		 temp=*ptr;
		 while(temp!=0)
                 {
	                 if(strcmp(temp->firstname,fname)==0)
		         {
			      if(temp==*ptr)
			      {
				  *ptr=temp->next;
				   printf("contact has been deleted successfully*****\n");
				   break;
			      }
			      else
			      {    
				   if(count1==rn)
				   {	
		                       prev->next=temp->next;
				       free(temp);
				       temp=NULL;
				       printf("contact has been deleted successfully*****\n");
				       break;
				   }
			      }
		         }
		         else
		         {
                                   prev=temp;
			           temp=temp->next;
		         }	
                  } 
	    }
	    else
	    {
		 printf("\nthe first name is not available in a contact list.....");
	    }
	    break;
	 case 2:
	        printf("Enter the last name:-");
	        scanf("%s",lname);
	        count=rn=0;;
                prev=temp=*ptr;
	     while(temp!=0)
	     {
		 if(strcmp(temp->lastname,lname)==0)
		 {
                     count++;
		     temp=temp->next;
		 }
		 else
		 {
		      temp=temp->next;
		 }
	     }
	     if(count>1)
	     {     
		   temp=*ptr;
		   while(temp!=0)
		   {
			 if(strcmp(temp->lastname,lname)==0)
		         {
                               rn++;
			       printf("%d.%s\t%s\t%s\t%s\t\n",rn,temp->firstname,temp->lastname,temp->mobileno,temp->company);
			       temp=temp->next;
                         }
			 else
			 {
			     temp=temp->next;
			 }
                   }
		   printf("\nlast name is present %d times in contact list please enter contact no from above list which you want to delete...",rn);
		   scanf("%d",&rn);
		   temp=*ptr;
		   count1=0;
                   while(temp!=0)
                   {
	                 if(strcmp(temp->lastname,lname)==0)
		         {
			      count1++;
			      if(temp==*ptr && count1==rn)
			      {
				  *ptr=temp->next;
				   printf("contact has been deleted successfully*****\n");
				   break;
			      }
			      else
			      {    
				   if(count1==rn)
				   {	
		                        prev->next=temp->next;
				        free(temp);
				        temp=NULL;
				        printf("contact has been deleted successfully*****\n");
				        break;
				   }
				   else
				   {
					prev=temp;
			                temp=temp->next;
				   }
			      }
		         }
		         else
		        {
                                   prev=temp;
			           temp=temp->next;
		        }	
                  }
            }
	    else if(count==1)
            {
		 temp=*ptr;
		 while(temp!=0)
                 {
	                 if(strcmp(temp->lastname,lname)==0)
		         {
			      if(temp==*ptr)
			      {
				  *ptr=temp->next;
				   printf("contact has been deleted successfully*****\n");
				   break;
			      }
			      else
			      {    
				   if(count1==rn)
				   {	
		                       prev->next=temp->next;
				       free(temp);
				       temp=NULL;
				       printf("contact has been deleted successfully*****\n");
				       break;
				   }
			      }
		         }
		         else
		         {
                                   prev=temp;
			           temp=temp->next;
		         }	
                  } 
	    }
	    else
	    {
		 printf("\nthe last name is not available in a contact list.....");
	    }
		break;
         case 3:
		 printf("Enter the mobile number:-"); 
                 scanf("%s",mobile);
                 prev=temp=*ptr;
		 count1=0;
		 while(temp!=0)
                 {
	                 if(strcmp(temp->mobileno,mobile)==0)
		         {
			      count1++;
			      if(temp==*ptr)
			      {
				  *ptr=temp->next;
				   printf("contact has been deleted successfully*****\n");
				   break;
			      }
			      else
			      {    
		                    prev->next=temp->next;
				    free(temp);
				    temp=NULL;
				    printf("contact has been deleted successfully*****\n");
				    break;   
			      }
		         }
		         else
		         {
                                   prev=temp;
			           temp=temp->next;
		         }	
                } 
		if(count1==0)
                {
		       printf("\nthe mobile number is not available in a contact list.....");
		}
		break;
     }
}

void displaycontacts(CB *ptr)
{
     while(ptr!=0)
     {
        printf("%s\t%s\t%s\t%s\t\n",ptr->firstname,ptr->lastname,ptr->mobileno,ptr->company);
		ptr=ptr->next;
     }
}