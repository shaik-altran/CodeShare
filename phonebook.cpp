#include<iostream>
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
		void editContact(contact *con[],string editcontact,string modifycontact)
                {


                        for(int j=0;j<i;j++)
                        {
                                if(editcontact==con[j]->getName())
                                {
                                        con[j]->setName(modifycontact);
                                }
                                if(editcontact==con[j]->getNumber())
                                {
                                        con[j]->setNumber(modifycontact);
                                }
                        }
                }

};
class phonebook
{
        public:
                void addNewContact(contact *con[],string nam,string numb)
                {
                        cout<<"in add!"<<endl;
			cout<<"i="<<i<<endl;
                        con[i]->setName(nam);
                        con[i]->setNumber(numb);
                        i++;
			cout<<"addedd"<<endl;
	               	delete con[i];         

                }

                void displayContact(contact *con[])
                {

                        cout<<"in display!"<<endl;
                        for(int j=0;j<i;j++)
                        {
                                cout<<"name:";
                                cout<<con[j]->getName();
                                cout<<"   ";
                                cout<<"number:";
                                cout<<con[j]->getNumber()<<endl;
                        }
                }
                void searchContact(contact *con[],string searchcontact)
                {
                        for(int j=0;j<i;j++)
                        {
                                if(searchcontact==con[j]->getName()||searchcontact==con[j]->getNumber())
                                {
                                        cout<<"name:";
                                        cout<<con[j]->getName();
                                        cout<<" ";
                                        cout<<"number:";
                                        cout<<con[j]->getNumber()<<endl;
                                }
                        }
                }

		void deleteContact(contact *con[],string deletecontact)
                {
                        int pos=0;
                        for(int j=0;j<i;j++)
                        {

                                if(deletecontact==con[j]->getName()||deletecontact==con[j]->getNumber())
                                {
                                        for(j=pos;j<i-1; j++)
                                        {
                                                con[j]=con[j+1];
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
	contact *con[10]={new contact()};
	string *ptr=(string *)con;
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
                        p.addNewContact(con,name,number);

                }
                else if(choice==2)
                {
                        p.displayContact(con);
                }
                else if(choice==3)
                {
                        string searchstring;
                        cout<<"enter the contact to search:";
                        cin>>searchstring;
                        p.searchContact(con,searchstring);
                }
                else if(choice==4)
                {
                        string editstring;
                        string modifystring;
                        cout<<"enter the contact to edit:";
                        cin>>editstring;
                        cout<<"enter the new name:";
                        cin>>modifystring;
                        c.editContact(con,editstring,modifystring);
                }
                else if(choice==5)
                {
                        string deletestring;
                        cout<<"enter the contact to delete:";
			cin>>deletestring;
                        p.deleteContact(con,deletestring);
                }
                else if(choice==6)
                {
                        exit(0);
                }
                else
                        printf("wrong choice!!!\n");

        }
}

