#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cfile.h"
#define LEN sizeof(struct Contact)



struct Contact* add()
{
    char sex[5];
    struct Contact *head=NULL,*p1,*p2;
    p1=(struct Contact*)malloc(sizeof(struct Contact));
    p2=p1;
    printf("*Input will be finished when name is 0.\n\n");
    printf("Name:");
    gets(p1->name);
    if(strcmp(p1->name,"0")==0)return NULL;
    do
    {
        printf("Gender[0(Male)/1(Female)]:");
        gets(sex);
    }while(strcmp(sex,"0")&&strcmp(sex,"1"));
    if(strcmp(sex,"0")==0)strcpy(p1->gender,"Male");
    else strcpy(p1->gender,"Female");
    printf("Tel:");
    gets(p1->tel);
    printf("E-mail:");
    gets(p1->email);
    printf("\n");
    int n=0;
    while(strcmp(p1->name,"0")!=0)
    {
        n++;
        if(n==1)head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct Contact*)malloc(sizeof(struct Contact));
        printf("Name:");
        gets(p1->name);
        if(strcmp(p1->name,"0")==0)break;
        do
        {
            printf("Gender[0(Male)/1(Female)]:");
            gets(sex);
        }while(strcmp(sex,"0")&&strcmp(sex,"1"));
        if(strcmp(sex,"0")==0)strcpy(p1->gender,"Male");
        else strcpy(p1->gender,"Female");
        printf("Tel:");
        gets(p1->tel);
        printf("E-mail:");
        gets(p1->email);
        printf("\n");
    }
    p2->next=NULL;
    return head;
}

void writec(struct Contact* head,char s[])
{
    FILE *con;
    extern char FILENAME[20];
    con=fopen(FILENAME,s);
    while(head!=NULL)
    {
        fwrite(head,LEN,1,con);
        head=head->next;
    }
    fclose(con);
    printf("\n");
    //sleep(1);
    char t[5];
}

