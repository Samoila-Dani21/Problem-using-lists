#include "ListPeople.cpp"
typedef struct PeopleList{

    char lastName[20],firstName[20],date[11];
    struct PeopleList *next;
}LIST;
class ListPeople {
    private:
        LIST *head;

    public:
    ListPeople();
    ~ListPeople();
        void addMember(char fn[20],char ln[20],char data[20]);
        void showList();
};