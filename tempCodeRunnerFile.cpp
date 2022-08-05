#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int flag1,flag2,flag3,flag4;
    flag1 = flag2 = flag3 = flag4 = 0;
    double testCase;
    int minLength = 7;
    char *oldPass = new char();
    char *newPass = new char();
    scanf("%lf",&testCase);
    for(int i=0;i<testCase;i++)
    {
        scanf("%s", oldPass);
        strcpy(newPass,oldPass);
        for(int i=0;i<strlen(oldPass);i++)
        {
            if(isupper(oldPass[i]))
            {
                flag1 = 1;
            }
            else if(islower(oldPass[i]))
            {
                flag2 = 1;
            }
            else if(isdigit(oldPass[i]))
            {
                flag3 = 1;
            }
            else if(oldPass[i] == '#' || oldPass[i] == '@' || oldPass[i] == '*' || oldPass[i] == '&' )
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
                strcat(newPass,"#");
            }
        }

        while(strlen(newPass) < 7)
        {
            strcat(newPass,"*");
        }

        printf("%s",newPass);
    }
    
    return 0;
}