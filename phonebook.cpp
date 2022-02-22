#include<iostream>
#include<string.h>
using namespace std;
static int i=0;
class contact
{

                string name;
                string number;
        public:
                string getName()
                {
                   return name;
                }
		string setName(string nam)
		{
			name=nam;
			return name;
		}
                string getNumber()
                {
                   return number;
                }
		string setNumber(string num)
		{
			number=num;
			return number;
		}

};
class phonebook
{
	contact *contactObj[10];

	public:
                void addNewContact(string nam,string numb)
                {
			contactObj[i]={new contact};	
			contactObj[i]->setName(nam);
                        contactObj[i]->setNumber(numb);
                        i++;
		}

                void displayContact()
                {

                        for(int j=0;j<i;j++)
                        {
                                cout<<"name:";
                                cout<<contactObj[j]->getName();
                                cout<<"   ";
                                cout<<"number:";
                                cout<<contactObj[j]->getNumber()<<endl;
                        }
                }
		void searchContact(string searchcontact)
                {
                        for(int j=0;j<i;j++)
                        {
                                if(searchcontact==contactObj[j]->getName()||searchcontact==contactObj[j]->getNumber())
                                {
                                        cout<<"name:";
                                        cout<<contactObj[j]->getName();
                                        cout<<" ";
                                        cout<<"number:";
                                        cout<<contactObj[j]->getNumber()<<endl;
                                }
                        }
                }
		
		void deleteContact(string deletecontact)
                {
                        int pos=0;
                        for(int j=0;j<i;j++)
                        {

                                if(deletecontact==contactObj[j]->getName()||deletecontact==contactObj[j]->getNumber())
                                {
                                        
					for(j=pos;j<i-1; j++)
                                        {
                                	 	contactObj[j]=contactObj[j+1];
                                        }
                                        i--;

                                }
                                pos++;
                        }

                }
};

int main()
{
        phonebook p;
	contact c;
	int choice;
        while(1)
        {
                cout<<"select the operation you want to perform:"<<endl;
                cout<<"1.add_NewContact"<<endl<<"2.displayContact"<<endl<<"3.searchContact"<<endl<<"4.Edit_contact"<<endl<<"5.deleteContact"<<endl<<"6.Exit"<<endl;
                cout<<"enter your choice:";
                cin>>choice;
                if(choice==1)
                {
                        string name;
                        string number;
                        cout<<"enter name:";
                        cin>>name;
                        cout<<"enter phno:";
                        cin>>number;
                        p.addNewContact(name,number);

                }
                else if(choice==2)
                {
                        p.displayContact();
                }
                else if(choice==3)
                {
                        string searchstring;
                        cout<<"enter the contact to search:";
                        cin>>searchstring;
                        p.searchContact(searchstring);
                }
		else if(choice==5)
                {
                        string deletestring;
                        cout<<"enter the contact to delete:";
                        cin>>deletestring;
                        p.deleteContact(deletestring);
                }

		else if(choice==6)
                {
                        exit(0);
                }
                else
                        printf("wrong choice!!!\n");

	}

               
}

