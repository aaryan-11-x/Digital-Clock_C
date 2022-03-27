#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>

int main()
{
    int h, m, s;
    char zone[10];

Enter:
    printf("Enter The Current Time (Hrs/Mins/Sec/(AM Or PM)) : ");
    scanf("%d %d %d %s", &h, &m, &s, &zone);
    strupr(zone);


    if(h>13 || m>60 || s>60 || h==0)
    {
        printf("\nPlease Enter Valid Time\n\n\a");
        goto Enter;
    }
    if(strcmp("AM",zone)!=0 && strcmp("PM",zone)!=0)
    {
        printf("\nPlease Enter Valid Time\n\n\a");
        goto Enter;
    }

    while(1)
    {
        s++;
        if(s>59){
            m++, s=0;
        }
        if(m>59){
            h++, m = 0;
        }
        if(h>12)
        {
            if(strcmp("AM",zone)==0){
                strcpy(zone,"PM");
                h=1, m=0, s=0;
            }
            else if(strcmp("PM",zone)==0){
                strcpy(zone,"AM");
                h=1, m=0, s=0;
            }
        }
        system("cls");      //This Clears The Screen
        printf("Time : %02d:%02d:%02d", h, m, s);
        if(h<=12 && strcmp("AM",zone)==0)
            printf(" AM");
        else if(h<=12 && strcmp("PM",zone)==0){
            printf(" PM");
        }
        Sleep(1000);        //Time Delay Function
    }
    return 0;
}
