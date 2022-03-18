#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
using namespace std;

ifstream fin("Input.txt");             //declared and openning file

typedef struct MemberList{             //the structure of the members of a family

    char firstName[20],date[11];
    struct MemberList *next;
}MEMBER;
typedef struct FamilyList{              //the structure of family
    char lastName[20];  
    struct MemberList *members;
    struct FamilyList *next;
    
}LIST;
void Test(LIST *p)
{
    if(p==NULL)
    {
        cout<<"Alocarea nu a reusit!";
    }
}
void Test(MEMBER *p)
{
    if(p==NULL)
    {
        cout<<"Alocarea nu a reusit!";
    }
}
class ListPeople {
private:
    LIST *head;

public:
    ListPeople();
    ~ListPeople();
    void addMember(char fn[20],char ln[20],char data[20]);
    void showList();
    void sortByDate();
};
ListPeople::ListPeople(){  
    head=NULL;
    
}
ListPeople::~ListPeople(){
}
void ListPeople::addMember(char fn[20],char ln[20],char data[20]){
    LIST *aux,*q;
    MEMBER *memb,*temp;
    if(head==NULL)                      
        {
            head=new LIST;                  //creating first family 
            Test(head);
            head->next=NULL;
            strcpy(head->lastName,ln);
            memb=new MEMBER;                //adding a member

            strcpy(memb->date,data);    
            strcpy(memb->firstName,fn);
            memb->next=NULL;
            head->members=memb;             
        }
    else if(head!=NULL)
    {
        
        for(aux=head ; aux!=NULL ; q=aux,aux=aux->next)     //goes to an existing family if the new member is from the same family
            if(strcmp(aux->lastName,ln)==0)                 //or makes the variable NULL by going thru the list
                break;
        if(aux==NULL)
        {
            aux=new LIST;                           //creating first family 
            Test(aux);
            aux->next=NULL;
            strcpy(aux->lastName,ln);
            memb=new MEMBER;
            Test(memb);

            strcpy(memb->date,data);                //adding a member
            strcpy(memb->firstName,fn);
            memb->next=NULL;
            aux->members=memb;

            q->next=aux;
        }
        else                                        //case in whitch there is a family with the same name
        {
            for(temp=aux->members;temp!=NULL;memb=temp,temp=temp->next);  
                                                    //makes the variable NULL by going thru the list
            temp=new MEMBER;
            strcpy(temp->date,data);    
            strcpy(temp->firstName,fn);
            temp->next=NULL;
            memb->next=temp;
        }
        
        
    }
}
void ListPeople::showList(){
    LIST *aux;
    MEMBER *temp;
    for(aux=head;aux!=NULL;aux=aux->next)
        {
            cout<<aux->lastName<<": ";
            for(temp=aux->members; temp!=NULL; temp=temp->next)
                cout<<temp->firstName<<" ";
            cout<<endl;
        }
}
void ListPeople::sortByDate(){
    LIST *aux;
    MEMBER *temp,*cont;
    char copyFirstName[20],copyDate[11];
    for( aux=head ; aux!=NULL ; aux=aux->next )
        for( temp=aux->members ; temp->next!=NULL ; temp=temp->next)
            for( cont=aux->members->next ; cont != NULL ; cont=cont->next )
                if(strcmp(temp->date,cont->date)>0)
                {                                                      
                    
                    strcpy(copyDate,temp->date);    
                    strcpy(copyFirstName,temp->firstName);


                    strcpy(temp->date,cont->date);    
                    strcpy(temp->firstName,cont->firstName);


                    strcpy(cont->date,copyDate);    
                    strcpy(cont->firstName,copyFirstName);

                }
}
int main()
{
    int nr=0,i;
    char firstName[20],lastName[20],date[20];
    ListPeople list;
    fin>>nr;  
    for(i=0;i<nr;i++)
        {
            fin>>firstName;
            fin>>lastName;
            fin>>date;
            list.addMember(firstName,lastName,date);
        }
    
    list.sortByDate();
    list.showList();
    fin.close();
    return 0;
}