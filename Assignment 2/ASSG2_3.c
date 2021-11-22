#include <stdio.h>
#include <string.h>

void main()
{
    char str[100], sub_str[100], new_str[100];
    int i, j, k = 0, temp, flag = 0;

    gets(str);
    gets(sub_str);

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != sub_str[0])
        {
            new_str[k] = str[i];
            k++;
        }
        else
        {
            temp = i;
            for (j = 0; j < strlen(sub_str); j++)
            {
                if (str[i] != sub_str[j])
                {
                    flag = 1;
                    break;
                }
                else if (str[i] == sub_str[j])
                {
                    i++;
                    temp++;
                }
            }
            i = temp - 1;
            if (flag == 1)
            {
                new_str[k] = str[i];
                k++;
                flag = 0;
            }
        }
    }
    printf("%s", new_str);
}