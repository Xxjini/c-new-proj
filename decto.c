#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int main()
{   int i,f=0,k;
    char wordlist[60];
    FILE *fpr;

    fpr=fopen("list.txt","r");

    while(!feof(fpr))
    {
        i=0,k=0;

           while((wordlist[k]=fgetc(fpr))!='\n')
            {
            if(wordlist[k]==EOF)
            break;
            printf("%c",wordlist[k]);
            k++;
            }
        printf("\n");

        while(i<k)
        {
        if(getch()==wordlist[i])
            {
            printf("%c",wordlist[i]);
            i++;
            }
        else
        f++;
        }

     system("cls");
    }

    printf("\nnombre de fautes est: %d",f);
    fclose(fpr);
    getch();

return 0;
}
