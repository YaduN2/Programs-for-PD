#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char sen[10000];
    int i;
    gets(sen);
    for (i = 0; i < strlen(sen); i++)
    {
        if (islower(sen[i]))
        {
            sen[i] = toupper(sen[i]);
        }
        else
        {
            sen[i] = tolower(sen[i]);
        }
    }
    printf("%s", sen);
    return 0;
}