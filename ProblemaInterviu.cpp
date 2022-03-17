#include <iostream>
#include <fstream>
#include <cstdio>
#include "ListPeople.h"
using namespace std;
ifstream fin("Input.txt");
int main()
{

    int nr=0;
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
}