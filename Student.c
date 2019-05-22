#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

void menu();
void new_add();
void change_del();
void aff_srch();
void autho();



 struct Student
 {
     int Id;
     char FullName[30];
     int  Birth;
     int Section;

 };



int main()
{
  SetConsoleTitle("Student list");
  autho();
  return 0;
}


 void autho()
 {
    const char name[20]="go";
    char user[20];
    int pass1;
    system("cls");
    printf("enter your username here:\n");
    gets(user);

    printf("enter your pass here:\n");
    scanf("%d",&pass1);

        if(strcmp(user,name)==0&&pass1==0000)
            {
                printf("welcom hicham");
                printf("\n Enter any key to go to menu");
                getch();
                menu();
            }
        else
            {
                printf("plz try again !!");
                getch();
                fflush(stdin);
                autho();
            }

 }

 void menu()
{
    system("cls");
    printf("\t******** WELCOME TO Student List *********\n");
    printf("\t*                                        *\n");
    printf("\t*                 MENU                   *\n");
    printf("\t*                                        *\n");
    printf("\t* 1.NEWFILE     2.CHANGE        3.ADD    *\n");
    printf("\t* 4.AFF         5.SEARCH        6.DELETE *\n");
    printf("\t*               7.EXIT                   *\n");
    printf("\t*                                        *\n");
    printf("\t******************************************\n");

     switch (getch())
     {
    case '1': new_add(1);
     break;
    case '2': change_del(1);
     break;
    case '3': new_add(0);
     break;
    case '4': aff_srch(1);
     break;
    case '5': aff_srch(0);
     break;
     case '6': change_del(0);
     break;
     case '7': exit(0);
     break;
     default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();
                menu();
     }
}

 void new_add(int op)
 {
     system("cls");
            FILE *fpr;
            struct Student student;

            if (op)
                fpr=fopen("file.txt","w");
            else
                fpr=fopen("file.txt","a");

            if (fpr==NULL)
                printf("can't found the file !!");
            else
             {
                printf("ID:");
                scanf("%d",&student.Id);

                printf("FullName:");
                fflush(stdin);
                gets(student.FullName);

                printf("Birth:");
                scanf("%d",&student.Birth);

                printf("Section:");
                scanf("%d",&student.Section);

                fprintf(fpr,"ID:%d FullName:%s Birth:%d Section:%d\n",student.Id,student.FullName,student.Birth,student.Section);

                fclose(fpr);
             }

                printf("\n Enter any key");
                getch();
                system("cls");
                 menu();




 }

 void change_del(int op)
    {
        FILE *fpr,*temp;
        struct Student student;
        int index,flag=0;
        system("cls");

       if((fpr=fopen("file.txt","r"))==NULL)
             printf("no tab found!!");
              else
              {
                    temp=fopen("temp.txt","w");
                    printf("give the student ID :");
                    scanf("%d",&index);

                    while(!feof(fpr))
                       {
                            fscanf(fpr,"ID:%d FullName:%s Birth:%d Section:%d\n",&student.Id,student.FullName,&student.Birth,&student.Section);
                             if((student.Id==index)&&(flag==0))
                             {
                                 flag=1;
                                if(op)
                                {
                                printf("ID:");
                                scanf("%d",&student.Id);
                                printf("FullName:");
                                fflush(stdin);
                                gets(student.FullName);
                                printf("Birth:");
                                scanf("%d",&student.Birth);
                                printf("Section:");
                                scanf("%d",&student.Section);
                                fprintf(temp,"ID:%d FullName:%s Birth:%d Section:%d\n",student.Id,student.FullName,student.Birth,student.Section);
                                }
                                else
                                continue;
                             }
                             else
                                fprintf(temp,"ID:%d FullName:%s Birth:%d Section:%d\n",student.Id,student.FullName,student.Birth,student.Section);

                        }
                        fclose(temp);
                        fclose(fpr);
                    if(flag!=1)
                        {
                            printf("NO CONACT'S FOUND");
                            remove("temp.txt");
                        }
                    else
                        {
                            remove("file.txt");
                            rename("temp.txt","file.txt");
                            printf("DONE.");

                        }
             }

               printf("\n Enter any key");
               getch();
               system("cls");
               menu();

    }

  void aff_srch(int op)
  {   FILE *fpr;
        struct Student student;
        char temp[30];
        int flag=0;
        system("cls");

       if((fpr=fopen("file.txt","r"))==NULL)
             printf("no file found!!");
              else
              {
                  if(!op)
                  {
                      printf("give the fullname:");
                      scanf("%s",&temp);
                  }
                    while(!feof(fpr))
                       {
                           fscanf(fpr,"ID:%d FullName:%s Birth:%d Section:%d\n",&student.Id,student.FullName,&student.Birth,&student.Section);
                           if(op)
                            {
                            flag++;
                           if (flag==5)
                           {
                               flag=1;
                                printf("\n Enter any key");
                                getch();
                                system("cls");
                           }
                            printf("ID:%d FullName:%s Birth:%d Section:%d\n\n",student.Id,student.FullName,student.Birth,student.Section);
                            }
                            else
                            {
                                if(!strcmp(temp,student.FullName))
                                    {
                                        printf("ID:%d FullName:%s Birth:%d Section:%d\n\n",student.Id,student.FullName,student.Birth,student.Section);
                                        flag++;
                                        break;
                                    }
                            }
                        }
                        fclose(fpr);
                    if(!flag)
                    printf("NO CONACT'S FOUND");
                    else
                    printf("DONE.");

             }

               printf("\n Enter any key");
               getch();
               system("cls");
               menu();
  }



