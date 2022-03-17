#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;
void Test(LIST *p)
{
    if(p==NULL)
    {
        cout<<"Alocarea nu a reusit!";
    }
}
ListPeople::ListPeople(){
    head=new LIST;
    Test(head);
    head->next=NULL;
}
ListPeople::~ListPeople(){
}
void ListPeople::addMember(char fn[20],char ln[20],char data[20]){
    LIST *aux,*prev;
    aux=head;
    if(aux->next!=NULL)
        for(;aux!=NULL;prev=aux,aux=aux->next);
    aux=new LIST;
    strcpy(aux->date,data);    
    strcpy(aux->firstName,fn);
    strcpy(aux->lastName,ln);
    aux->next=NULL;
    prev->next=aux;
}
void ListPeople::showList(){
    LIST *aux;
    for(aux=head;aux->next==NULL;aux=aux->next)
        cout<<aux->firstName<<" "<<aux->lastName<<" "<<aux->date<<endl;
}