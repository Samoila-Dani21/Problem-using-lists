#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
using namespace std;

ifstream fin("Input.txt");
typedef struct PeopleList{

    char lastName[20],firstName[20],date[11];
    struct PeopleList *next;
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
};
ListPeople::ListPeople(){
    head=new LIST;
    Test(head);
    head->next=NULL;
}
ListPeople::~ListPeople(){
}
void ListPeople::addMember(char fn[20],char ln[20],char data[20]){
    LIST *aux,*prev;
    if(head->next==NULL)
        {
            aux=head;
            strcpy(aux->date,data);    
            strcpy(aux->firstName,fn);
            strcpy(aux->lastName,ln);
        }
    else
    {
    aux=head;
    for(;aux!=NULL;prev=aux,aux=aux->next);
    aux=new LIST;
    Test(aux);
    strcpy(aux->date,data);    
    strcpy(aux->firstName,fn);
    strcpy(aux->lastName,ln);
    aux->next=NULL;
    prev->next=aux;
    }
}
void ListPeople::showList(){
    LIST *aux;
    for(aux=head;aux!=NULL;aux=aux->next)
        cout<<aux->firstName<<" "<<aux->lastName<<" "<<aux->date<<endl;
}

int main()
{

    int nr;
    char firstName[20],lastName[20],date[20];
    ListPeople list;
    fin>>nr;  
    for(int i=0;i<nr;i++);
        {
            fin>>lastName;
            fin>>firstName;
            fin>>date;
            list.addMember(firstName,lastName,date);
        }
    list.showList();
    fin.close();
}