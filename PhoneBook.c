#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct person
{
    char name[30];
    char country_code[4];
    long int mble_no;
    char sex[8];
    char mail[100];
    struct person *next;
}*head;
struct person* last_node(struct person* head)
{
    struct person* temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}
struct person* parition(struct person* first, struct person* last)
{

    struct person* pivot = first;
    struct person* front = first;
    int temp = 0;
    while (front != NULL && front != last)
    {
        if (front->mble_no < last->mble_no)
        {
            pivot = first;


            temp = first->mble_no;
            first->mble_no = front->mble_no;
            front->mble_no = temp;


            first = first->next;
        }


        front = front->next;
    }


    temp = first->mble_no;
    first->mble_no = last->mble_no;
    last->mble_no = temp;
    return pivot;
}
struct person *middle(struct person* start,struct person* last)
{
    if (start == NULL)
        return NULL;

    struct person* slow = start;
    struct person* fast = start -> next;

    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    return slow;
}

//Search
struct person* search(struct person *head, int value)
{
    struct person* start = head;
    struct person* last = NULL;

    do
    {

        struct person *mid = middle(start, last);


        if (mid == NULL)
            return NULL;


        if (mid -> mble_no == value)
            return mid;

        else if (mid -> mble_no < value)
            start = mid -> next;


        else
            last = mid;

    }
    while (last == NULL ||
            last != start);
    return NULL;
}




void insert(char* name,char * country_code,long int phone,char *sex, char* mail)
{
    struct person * p1 = (struct person *) malloc(sizeof(struct person));
    p1->mble_no= phone;
    strcpy(p1->name, name);
    strcpy(p1->country_code, country_code);
    strcpy(p1->sex,sex);
    strcpy(p1->mail,mail);
    p1->next = NULL;
    if(head==NULL)
    {
        head = p1;

    }
    else
    {
        p1->next = head;
        head = p1;
    }

}

void update(int phone)
{

    struct person * temp = head;
    while(temp!=NULL)
    {
        if(temp->mble_no==phone)
        {
            printf("\n\t\t\tEnter new name: ");
            fflush(stdin);
            scanf("%s", temp->name);
            printf("\t\t\tEnter new phone number: ");
            fflush(stdin);
            scanf("%ld", &temp->mble_no);
            printf("\t\t\tEnter new country code : ");
            fflush(stdin);
            scanf("%s",temp->country_code);
            printf("\t\t\tEnter gender : ");
            fflush(stdin);
            scanf("%s",temp->sex);
            printf("\t\t\tEnter your email : ");
            fflush(stdin);
            scanf("%s",temp->mail);
            printf("\t\t\tUpdation Successful!!!\n");
            return;
        }
        temp = temp->next;

    }
    printf("\n\t\t\tSearched mobile number is not found \n");
}
void Delete(long int phone)
{
    struct person * temp1 = head;
    struct person* temp2 = head;
    while(temp1!=NULL)
    {

        if(temp1->mble_no==phone)
        {

            if(temp1==temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next = temp1->next;
                free(temp1);
            }

            printf("\n\t\t\tRecord Successfully Deleted !!!\n");
            return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("\n\t\t\tSearched number is not found\n");

}


int  display()
{
    int count=0;
    int i;
    struct person * temp = head;
    printf("\n\t\t\t\t******************************************************************************\n");
    printf("\t\t\t\t*                  Here is all records listed in phonebook                   *\n");
    printf("\t\t\t\t******************************************************************************\n\n\n");
    printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    GENDER\t\t          EMAIL\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
    while(temp!=NULL)
    {

        int i;
        int len1 = 40 - strlen(temp->name);
        int len2 = 19 - strlen(temp->country_code);
        int len3 = 15;
        int len4 = 21 - strlen(temp->sex);
        printf("%s",temp->name);
        for(i=0; i<len1; i++)
            printf(" ");

        printf("%s",temp->country_code);
        for(i=0; i<len2; i++)
            printf(" ");

        printf("%ld",temp->mble_no);
        for(i=0; i<len3; i++)
            printf(" ");

        printf("%s",temp->sex);
        for(i=0; i<len4; i++)
            printf(" ");

        printf("%s",temp->mail);
        printf("\n");
        fflush(stdin);
        temp=temp->next;
    }
}
//Quick Sort
void quick_sort(struct person* first, struct person* last)
{
    if (first == last)
    {
        return;
    }
    struct person* pivot = parition(first, last);

    if (pivot != NULL && pivot->next != NULL)
    {
        quick_sort(pivot->next, last);
    }

    if (pivot != NULL && first != pivot)
    {
        quick_sort(first, pivot);
    }

}
void menu()
{
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                  Welcome TO My phone book                    *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t1) Add Person\n\n");
    printf("\t\t\t2) Search Person\n\n");
    printf("\t\t\t3) Remove person\n\n");
    printf("\t\t\t4) Update person\n\n");
    printf("\t\t\t5) Print Contacts\n\n");
    printf("\t\t\t6) Sort the contacts \n\n");
};

int main()
{
    int size;
    head = NULL;
    int choice;
    char name[100];
    long int phone;
    char ccode[7];
    char sex[10];
    char mail[500];
    struct person *temp1;
    menu();
    while(choice!=0)
    {
        printf("\n\t\t\tEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n\t\t\tEnter name: ");
            fflush(stdin);
            scanf("%[^\n]s", name);
            printf("\t\t\tEnter country code : ");
            fflush(stdin);
            scanf("%s", ccode);
            printf("\t\t\tEnter phone number: ");
            scanf("%ld",&phone);
            printf("\t\t\tEnter gender : ");
            fflush(stdin);
            scanf("%s",sex);
            printf("\t\t\tEnter your email : ");
            fflush(stdin);
            scanf("%s",mail);
            insert(name, ccode, phone, sex,mail);
            break;

        case 2:
            printf("\n\t\t\tEnter phone number to search: ");
            scanf("%ld", &phone);

            if (search(head,phone) == NULL)
                printf("Value not present\n");
            else
            {
                struct person * s=search(head,phone);
                struct person * temp = head;
                printf("\n\t\t\t\t******************************************************************************\n");
                printf("\t\t\t\t*               \t   Searched Person Found !!!       \t             *\n");
                printf("\t\t\t\t******************************************************************************\n\n\n");
                printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    GENDER\t\t          EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
                while(temp!=NULL)
                {

                    int i;
                    int len1 = 40 - strlen(temp->name);
                    int len2 = 19 - strlen(temp->country_code);
                    int len3 = 15;
                    int len4 = 21 - strlen(temp->sex);
                    printf("%s",temp->name);
                    for(i=0; i<len1; i++)
                        printf(" ");

                    printf("%s",temp->country_code);
                    for(i=0; i<len2; i++)
                        printf(" ");

                    printf("%ld",temp->mble_no);
                    for(i=0; i<len3; i++)
                        printf(" ");

                    printf("%s",temp->sex);
                    for(i=0; i<len4; i++)
                        printf(" ");

                    printf("%s",temp->mail);
                    printf("\n");
                    fflush(stdin);
                    temp=temp->next;
                }
                break;

            case 3:
                printf("\n\t\t\tEnter phone number to delete: ");
                scanf("%ld", &phone);
                Delete(phone);
                break;

            case 4:
                printf("\n\t\t\tEnter phone number to update: ");
                scanf("%ld", &phone);
                update(phone);
                break;
            case 5:
                display();
                break;

            case 6:
                quick_sort(head,last_node(head));
                display();
                break;
            }
        }
    }
}
