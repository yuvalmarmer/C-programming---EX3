#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30
#define MAXLINES 250
int getline2(char *);
int getword(char *);
int substring(char *, char *);
int similar(char *, char *, int);
int main(int argc, char **argv)
{


    char string[LINE];
    char **pointer = NULL;
    pointer = (char **)malloc(MAXLINES * sizeof(char *));
    if (!pointer)
    {
   	 printf("Failed to read david!!");	
        puts("There is not enough memory for the program. Sorry.\n");
        exit(1);
    }
    


    


    int p;
    fgets(string, WORD, stdin);
    int numOfCharInTHEWORD = getword(string);
    pointer[0] = malloc(numOfCharInTHEWORD * sizeof(char));
    pointer[0] = strdup(string);
    pointer[0] = realloc(pointer[0],numOfCharInTHEWORD);
    char theChar = string[numOfCharInTHEWORD+1];
    fgets(string, LINE, stdin);
    int i = 2;
    while (fgets(string, LINE, stdin))
    {
        int numOfCharInLine = getline2(string);
        pointer[i] = (char *)malloc((numOfCharInLine+1) * sizeof(char));
        pointer[i] = strdup(string);
        i++;
    }

    int numOfRows = i;
    char *pch;

    if (theChar == 'a')
    {
        printf("Option a! \n");
        for (int j = 2; j < numOfRows; j++)
        {
            if (substring(pointer[j], pointer[0]) == 1)
            {
                printf("%s", pointer[j]);
            }
        }
    }
    else
    {
    printf("Option b! \n");
        for (int j = 2; j < numOfRows; j++)
        {
            
            pch = strtok(pointer[j], " \n\t");
            while (pch != NULL)
            {
                if (similar(pch, pointer[0], 1) == 1)
                {
                    printf("%s \n", pch);
                }
                pch = strtok(NULL, " \n\t");
            }
        }
    }

    // for(int j=0;j<i;j++){
    //     printf("%s", pointer[j]);
    // }

    free(pointer);

    return 0;
}

int getline2(char *s)
{
    int i = 0;
    int counter = 0;
    while (s[i] != '\n')
    {
        counter++;
        i++;
    }
    return counter;
}
int getword(char *w)
{
    int i = 0;
    int counter = 0;
    while (w[i] != '\n' && w[i] != '\t' && w[i] != ' ' && w[i] != '\0' && (int)w[i]!=-85)
    {
        counter++;
        i++;
    }
    return counter;
}

int substring(char *str1, char *str2)
{ // str2 ⊆ str1 ???
    int sizeStr1 = getline2(str1);
    int sizeStr2 = getword(str2);
    if (sizeStr2 > sizeStr1)
    {
        return 0;
    }
    for (int i = 0; i < sizeStr1; i++)
    {
        //when we hit the first
        if (str1[i] == str2[0])
        {
            for (int j = 0; j < sizeStr2; j++)
            {
                if (str1[i + j] != str2[j])
                {
                    break;
                }
                if (j == sizeStr2 - 1)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int similar(char *s, char *t, int n)
{ // wanna reach t from s in n moves
    if (n == 0 && strcmp(s, t) == 0)
    {
        return 1;
    }
    int sizeOfS = getword(s);
    int sizeOfT = getword(t);
    if (sizeOfT > sizeOfS)
    {
        return 0;
    }
    int Scount = 0;
    int Tcount = 0;
    int diff = 0;
    for (int i = 0; i < sizeOfS; i++)
    {
        if (s[Scount] != t[Tcount])
        {
            Scount++;
        }
        else
        {
            Scount++;
            Tcount++;
        }
    }
    diff = Scount - Tcount;
    int answer = diff == n ? 1 : 0;
    return answer;
}

