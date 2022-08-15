#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct event{
    struct event *link;
    char name[40];
    char date[20];
    char address[300];
    int expense;
    char organiser[30];
    char theme[35];
    char chiefg[20];
};struct event *head;
void entry()
{
    struct event *temp;
    temp=malloc(sizeof(struct event*));
    temp->link=NULL;
    printf("Event Entry form\n");
    if(head==NULL)
    {
        head=temp;
        printf("Enter the name of event\n");
        scanf("%s",temp->name);
        printf("Enter the date of event\n");
        scanf("%s",temp->date);
        printf("Enter the address of event\n");
        scanf("%s",temp->address);
        printf("Enter the expense of event\n");
        scanf("%d",&temp->expense);
        printf("Enter the organiser of event\n");
        scanf("%s",temp->organiser);
        printf("Enter the chiefguest of event\n");
        scanf("%s",temp->chiefg);
        printf("Enter the theme of event\n");
        scanf("%s",temp->theme);
        return;
    }
    temp->link=head;
    head=temp;
        printf("Enter the name of event\n");
        scanf("%s",temp->name);
        printf("Enter the date of event\n");
        scanf("%s",temp->date);
        printf("Enter the address of event\n");
        scanf("%s",temp->address);
        printf("Enter the expense of event\n");
        scanf("%d",&temp->expense);
        printf("Enter the organiser of event\n");
        scanf("%s",temp->organiser);
        printf("Enter the chiefguest of event\n");
        scanf("%s",temp->chiefg);
        printf("Enter the theme of event\n");
        scanf("%s",temp->theme);
        return;
}
void printh()
{
    struct event *temp=head;
    if(head==NULL)
       return;
    while(temp!=NULL)
    {
                printf("\nname of event\n");
                printf("%s",temp->name);
                printf("\ndate of event\n");
                printf("%s",temp->date);
                printf("\naddress of event\n");
                printf("%s",temp->address);
                printf("\nexpense of event\n");
                printf("%d",temp->expense);
                printf("\norganiser of event\n");
                printf("%s",temp->organiser);
                printf("\nchiefguest of event\n");
                printf("%s",temp->chiefg);
                printf("\ntheme of event\n");
                printf("%s",temp->theme);
                temp=temp->link;
    }
    return;
}
void search()
{
    struct event *temp=head;
    int opn,a;
    char key[30];
    printf("\t\t\t\tEVENT SEARCH MENU\nCHOOSE YOUR DESIRED OPTION\n");
    printf("1.SEARCH BY NAME\n2.SEARCH BY THEME\n3.RETURN TO MAIN MENU\n");
    scanf("%d",&opn);
    switch(opn)
    {
            case 1:
            printf("Enter the name of event");
            scanf("%s",key);
            while(temp!=NULL)
            {
                if(strcmp(temp->name,key)==0)
                {
                    printf("\nname of event\n");
                    printf("%s",temp->name);
                    printf("\ndate of event\n");
                    printf("%s",temp->date);
                    printf("\naddress of event\n");
                    printf("%s",temp->address);
                    printf("\nexpense of event\n");
                    printf("%d",temp->expense);
                    printf("\norganiser of event\n");
                    printf("%s",temp->organiser);
                    printf("\nchiefguest of event\n");
                    printf("%s",temp->chiefg);
                    printf("\ntheme of event\n");
                    printf("%s",temp->theme);
                    return;
                }
                temp=temp->link;
            }
            printf("\nno any event found with the entered key\n");
            break;
            case 2:
            printf("Enter the theme of event");
            scanf("%s",key);
            while(temp!=NULL)
            {
                if(strcmp(temp->theme,key)==0)
                {
                    printf("\nname of event\n");
                    printf("%s",temp->name);
                    printf("\ndate of event\n");
                    printf("%s",temp->date);
                    printf("\naddress of event\n");
                    printf("%s",temp->address);
                    printf("\nexpense of event\n");
                    printf("%d",temp->expense);
                    printf("\norganiser of event\n");
                    printf("%s",temp->organiser);
                    printf("\nchiefguest of event\n");
                    printf("%s",temp->chiefg);
                    printf("\ntheme of event\n");
                    printf("%s",temp->theme);
                    return;
                }
                temp=temp->link;
            }
            printf("\nno any event found with the entered key\n");
            return;
            break;
            case 3:return;
            default:return;
    }

}
int intro()
{
    int opn;
    printf("\n\t\t\t\tMAIN MENU\nCHOOSE YOUR DESIRED FUNCTION\n");
    printf("1.NEW EVENT ENTRY\n2.EDIT EXISTING EVENT\n3.SEARCH ANY EVENT\n4.DELETE ANY EXISTING EVENT\n5.EXIT\nEnter the desired option\n");
    scanf("%d",&opn);
    return opn;
}
void delete()
{
    struct event *temp=head,*temp1;
    int opn;
    char key[30],del[30];
    printf("\t\t\t\tEVENT SEARCH MENU\nCHOOSE YOUR DESIRED OPTION\n");
    printf("1.DELETE BY NAME\n2.DELETE BY THEME\3.RETURN TO MAIN MENU\n");
    scanf("%d",&opn);
    switch(opn)
    {
            case 1:
            printf("Enter the name of event");
            scanf("%s",key);
            if(strcmp(temp->name,key)==0)
            {
                head=temp->link;
                strcpy(del,temp->name);
                free(temp);
                printf("\nAn event with name %s is deleted\n",del);
                return;
            }
            while(strcmp(temp->name,key))
            {
                temp1=temp;
                temp=temp->link;
            }
            strcpy(del,temp->name);
            temp1->link=temp->link;
            free(temp);
            printf("\nAn event with name %s is deleted\n",del);
            return;
            break;
            case 2:printf("Enter the theme of event");
            scanf("%s",key);
            if(strcmp(temp->theme,key)==0)
            {
                head=temp->link;
                strcpy(del,temp->name);
                free(temp);
                printf("\nAn event with name %s is deleted\n",del);
                return;
            }
            while(strcmp(temp->theme,key))
            {
                temp1=temp;
                temp=temp->link;
            }
            strcpy(del,temp->name);
            temp1->link=temp->link;
            free(temp);
            printf("\nAn event with name %s is deleted\n",del);
            case 3:return;
            break;
            default:exit(0);
    }
}
void edit()
{
    struct event *temp=head;
    int opn,ch,ex;
    char key[30];
    char param[40];
    printf("\t\t\t\tEVENT EDITING MENU\nCHOOSE YOUR DESIRED OPTION\n");
    printf("1.SEARCH BY NAME\n2.SEARCH BY THEME\n3.RETURN TO MAIN MENU\n");
    scanf("%d",&opn);
    switch(opn)
    {
        case 1:
            printf("Enter the name of event");
            scanf("%s",key);
            while(temp!=NULL)
            {
              if(strcmp(temp->name,key)==0)
              {
                printf("\nWhich paramater you want to change\n");
                printf("1.name\n2.date\n3.address\n4.expense\n5.organiser\n6.chief guest\n7.theme\n");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:printf("enter new parameter\n");
                           scanf("%s",temp->name);
                           return;
                           break;
                    case 2:printf("enter new parameter\n");
                           scanf("%s",temp->date);
                           return;
                           break;
                    case 3:printf("enter new parameter\n");
                           scanf("%s",temp->address);
                           return;
                           break;
                    case 4:printf("enter new parameter\n");
                          scanf("%d",temp->expense);
                           return;
                           break;
                    case 5:printf("enter new parameter\n");
                           scanf("%s",temp->organiser);
                           return;
                           break;
                    case 6:printf("enter new parameter\n");
                           scanf("%s",temp->chiefg);
                           return;
                           break;
                    case 7:printf("enter new parameter\n");
                           scanf("%s",temp->theme);
                           return;
                           break;
                    default:return;
                }
              } 
                temp=temp->link;
            }
            printf("\nno any event found with the entered key\n");
            break;
            case 2:
            printf("Enter the theme of event");
            scanf("%s",key);
            while(temp!=NULL)
            {
              if(strcmp(temp->theme,key)==0)
              {
                    printf("\nWhich paramater you want to change\n");
                    printf("1.name\n2.date\n3.address\n4.expense\n5.organiser\n6.chief guest\n7.theme\n");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1:printf("enter new parameter\n");
                            scanf("%s",temp->name);
                            return;
                            break;
                        case 2:printf("enter new parameter\n");
                            scanf("%s",temp->date);
                            return;
                            break;
                        case 3:printf("enter new parameter\n");
                            scanf("%s",temp->address);
                            return;
                            break;
                        case 4:printf("enter new parameter\n");
                            scanf("%d",temp->expense);
                            return;
                            break;
                        case 5:printf("enter new parameter\n");
                            scanf("%s",temp->organiser);
                            return;
                            break;
                        case 6:printf("enter new parameter\n");
                            scanf("%s",temp->chiefg);
                            return;
                            break;
                        case 7:printf("enter new parameter\n");
                            scanf("%s",temp->theme);
                            return;
                            break;
                        default:return;
                    }
               }  
                temp=temp->link;
            }
            printf("\nno any event found with the entered key\n");
            break;
            case 3:return;
            break;
            default:return;
    }        
}
int main()
{
    int opn,a=1;
    char uname[20],passwd[20];
    char uno[20]="mvit",pass[20]="mvit12345";
    printf("\t\t\tWELCOME TO MVIT EVENT MANAGEMENT SYSTEM\n");
    printf("Enter login credential to continue\n");
    printf("Enter username \n");
    scanf("%s",uname);
    printf("enter password\n");
    scanf("%s",passwd);
    if(!(strcmp(uname,uno)) && !(strcmp(passwd,pass)))
    {
        while(a)
        {
            opn=intro();
            switch(opn)
            {
                case 1:
                entry();
                break;
                case 2:edit();
                break;
                case 3:search();
                break;
                case 4:delete();
                break;
                case 5:printh();
                break;
                default:a=0;
                exit(0);

            }
        }
    }
    else
    {
        printf("Wrong login credential!!! TRY AGAIN !");
    }
    getch();
}