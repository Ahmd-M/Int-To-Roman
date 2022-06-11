#include <stdio.h>
#include <string.h>


int singleton_values[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
char characters[][13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

char * intToRoman(int num);
void analyse(int num);



void main()
{
    int number;
    printf("Enter a number less than 4000: ");
    scanf("%d", &number);

    analyse(number);
    //printf("%s", intToRoman(number));
}



char * intToRoman(int num)
{   
    char * roman;
    int thousands = num / 1000;

    if(thousands>=4)
        {printf("%d >= 4000", num);}
    else{

        analyse(num);
        return roman;
    }
}





// 3999 ===> 3000 + 900 + 90 + 9 ===> 3000 + (500+400) + (50+40) + (5+4)
// 3*(1000) + 1*(500) + 4*(100) + 1*(50) + 4*(10) + 1*(5) + 4*(1) ===> 3/1/4/1/4/1/4


void analyse(int num)
{
    int _900s, _90s, _9s;
    int _400s, _40s, _4s;
    int _1000s, _500s, _100s, _50s, _10s, _5s, _1s;

    _1000s = num / 1000;
    _900s = (num%1000) / 900;
    _500s = (num%1000-_900s*900) / 500;
    _400s = (num%1000-_900s*900-_500s*500) / 400;
    _100s = (num%1000-_900s*900-_500s*500-_400s*400) / 100;
    _90s = (num%100) / 90;
    _50s = (num%100-_90s*90) / 50;
    _40s = (num%100-_90s*90-_50s*50) / 40;
    _10s = (num%100-_90s*90-_50s*50-_40s*40) / 10;
    _9s = (num%10) / 9;
    _5s = (num%10-_9s*9) / 5;
    _4s = (num%10-_9s*9-_5s*5) / 4;
    _1s = (num%10-_9s*9-_5s*5-_4s*4) / 1;

    int orders[13] = {_1000s, _900s, _500s, _400s, _100s, _90s, _50s, _40s, _10s, _9s, _5s, _4s, _1s};

    for(int n=0; n<13; n++)
        {
            for(int i=0; i<orders[n]; i++)
                {
                    printf("%s",characters[n]);
                }
        }
}


