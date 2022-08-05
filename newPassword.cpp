#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int flag1,flag2,flag3,flag4,flag5;
    flag1 = flag2 = flag3 = flag4 = flag5 = 0;
    int testCase;
    int length;
    int k=1;
    char *oldPass = new char();
    char *newPass = new char();
    scanf("%d",&testCase);
    for(int i=0;i<testCase;i++)
    {
        scanf("%d", &length);
        scanf("%s", oldPass);
        strcpy(newPass,oldPass);
        for(int i=0;i<strlen(oldPass);i++)
        {
            if(isupper(oldPass[i]))
            {
                flag1 = 1;
            }
            if(islower(oldPass[i]))
            {
                flag2 = 1;
            }
            if(isdigit(oldPass[i]))
            {
                flag3 = 1;
            }
            if((strcmp(&oldPass[i],"#") == 0) || (strcmp(&oldPass[i],"&") == 0) || (strcmp(&oldPass[i],"*") == 0) || (strcmp(&newPass[i],"@") == 0))
            {
                flag4 = 1;
            }
        }

        if(flag1==0)
        {
            strcat(newPass,"A");
        }
        if(flag2 == 0)
        {
            strcat(newPass,"a");
        }
        if(flag3 == 0)
        {
            strcat(newPass,"1");
        }
        if(flag4 == 0)
        {
            strcat(newPass,"@");
            while(strlen(newPass) < 7)
            {
                strcat(newPass,"*");
            }
        }

        while(strlen(newPass) < 7)
        {
            strcat(newPass,"#");
        }

        printf("Case #%d: %s\n", k, newPass);
        k++;
        flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    }
    
    return 0;
}