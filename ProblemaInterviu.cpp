#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
using namespace std;

ifstream fin("Input.txt");
typedef struct PeopleList{

    char lastName[20],firstName[20],date[11];
    struct PeopleList *next;
    struct PeopleList *prev;
}LIST;
void Test(LIST *p)
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
    void sortByFamily();
    void swap(LIST **head,LIST *p,LIST* q);
};
ListPeople::ListPeople(){  
    head=NULL;
    
}
ListPeople::~ListPeople(){
}
void ListPeople::addMember(char fn[20],char ln[20],char data[20]){
    LIST *aux,*q;
    if(head==NULL)
        {
            
            head=new LIST;
            Test(head);
            head->next=NULL;
            head->prev=NULL;
            aux=head;

            strcpy(aux->date,data);    
            strcpy(aux->firstName,fn);
            strcpy(aux->lastName,ln);
        }
    else if(head!=NULL)
    {
        for(aux=head;aux!=NULL;)
        {
            q=aux;
            aux=aux->next;
            
        }
        aux=new LIST;
        Test(aux);
        aux->prev=q;
        strcpy(aux->date,data);    
        strcpy(aux->firstName,fn);
        strcpy(aux->lastName,ln);
        aux->next=NULL;
        q->next=aux;
    }
}
void ListPeople::showList(){
    LIST *aux;
    for(aux=head;aux!=NULL;aux=aux->next)
        cout<<aux->firstName<<" "<<aux->lastName<<" "<<aux->date<<endl;
}
void ListPeople::sortByFamily(){
    LIST *aux,*p;
    char copyFirstName[20],copyLastName[20],copyDate[11];
    for(aux=head;aux!=NULL;aux=aux->next)
        for(p=aux->next;p!=NULL;p=p->next)
            if(strcmp(aux->date,p->date)>0)
                {
                    
                    strcpy(copyDate,aux->date);    
                    strcpy(copyFirstName,aux->firstName);
                    strcpy(copyLastName,aux->lastName);

                    strcpy(aux->date,p->date);    
                    strcpy(aux->firstName,p->firstName);
                    strcpy(aux->lastName,p->lastName);

                    strcpy(p->date,copyDate);    
                    strcpy(p->firstName,copyFirstName);
                    strcpy(p->lastName,copyLastName);
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
    
    list.sortByFamily();
    list.showList();
    fin.close();
}