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
};
ListPeople::ListPeople(){  
    head=NULL;
    
   // head->prev=NULL;
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
           // aux->prev=p;
        }
        aux=new LIST;
        Test(aux);
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
    LIST *aux,*p,*copy;
    for(aux=head;aux!=NULL;aux=aux->next)
        for(p=aux->next;p!=NULL;p=p->next)
            if(strcmp(aux->firstName,p->firstName)<0)
                {
                    copy=aux->prev->next;
                    aux->prev->next=p->prev->next;
                    p->prev->next=aux;
                   /* copy=aux->next;
                    aux->next=p->next;
                    p->next=copy;
                    copy=aux;
                    aux=p;
                    p=copy;
               */
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

            fin>>lastName;
            fin>>firstName;
            fin>>date;

            list.addMember(firstName,lastName,date);
        }
    
    //list.sortByFamily();
    list.showList();
    fin.close();
}