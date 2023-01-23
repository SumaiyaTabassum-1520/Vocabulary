#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct Vocabulary
{
    char word[1000];
    char meaning[1000];

};
struct Vocabulary wordMeaning[1000];
int numberOfWord;

void addWordMeaning()
{
    FILE *fp = fopen("WordMeaning.dat","a");
    int i;
    printf("Enter word\n");
    scanf("%s",wordMeaning[numberOfWord].word);
    fprintf(fp,"%s\n",wordMeaning[numberOfWord].word);
    printf("Enter meaning\n");
    fflush(stdin);
    scanf("%[^\n]*c",wordMeaning[numberOfWord].meaning);
    fprintf(fp,"%s\n",wordMeaning[numberOfWord].meaning);
    numberOfWord=numberOfWord+1;
    fclose(fp);
}
void printAllWordsMeaning()
{
    int i;
    for(i=0; i<numberOfWord; i++)
    {
        printf("Word    : %s\nMeaning : %s\n",wordMeaning[i].word,wordMeaning[i].meaning);

    }
}
void learnRandom()
{
    int i,random;

    for(i=1 ; i<=10 ; i++)
    {
        int random=rand()%numberOfWord;
        printf("Word    : %s\nMeaning : %s\n", wordMeaning[random].word,wordMeaning[random].meaning);
    }
}

void printErrorMessage()
{
    printf("\a\a\aPlease press the correct key\n");
}
void printExitMessage()
{
    printf("\a\a\aThank you for using the app\n");
}
void loadDataFromFile()
{
    FILE *fp = fopen("WordMeaning.dat","r");

    int i=0;
    while(fgets(wordMeaning[i].word,1000,fp)!=NULL)
    {
        fflush(stdin);
        fgets(wordMeaning[i].meaning,1000,fp);
        i++;
    }
    numberOfWord=i;
    fclose(fp);
}


int printmenu()
{
    printf("\n\n");
    printf("\t\t enter 1 to add new word and meaning\n");
    printf("\t\t enter 2 to print all word with meaning\n");
    printf("\t\t enter 3 to learn random ten words\n");
    printf("\t\t enter 4 to exit the vocabulary program\n");
    return 1;
}
int main()
{
    int option,breakLoop=0;
    loadDataFromFile();
    while (printmenu()==1 && scanf("%d",&option)==1)
    {
        switch(option)
        {
        case 1:
            addWordMeaning();
            break;
        case 2:
            printAllWordsMeaning();
            break;
        case 3:
            learnRandom();
            break;
        case 4:
            breakLoop=1;
            break;
        default:
            printErrorMessage();
            break;
        }
        if(breakLoop==1)
        {
            break;
        }
        system("PAUSE");
        system("CLS");
    }
    printExitMessage();
    return 0;
}

