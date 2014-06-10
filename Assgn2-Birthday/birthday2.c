/*
Program to verify The Birthday Paradox.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int people;

    printf("Enter the number of people of whose you want to see the probability :: ");
    scanf("%d",&people);

    calculate(people);
    generate(people);

    return 0;
}

int calculate(int people)
{
    int i;
    double p = 1;

    for(i = 1; i < people; i++)
     {
         p = p*((365.0-i)/365.0);  //calculating the probability of n number of people with the probability formula.
     }

     printf("\nThe probablity for the birthday is :: %f",1-p);

     return 0;
}

int generate(int people)
{
    int birthdays[365] = {0};  //birthdays will have 365 elements, each corresponding to 1 day. (all initialized to 0)
    double p;
    int i,j,k,flag;
    double count=0;

    for(j = 0; j < 1000; j++)
    {
        flag=0;

        for(i = 0; i < 365; i++)
            birthdays[i] = 0;          //initializing birthdays to 0 for each test case

        for(i = 0; i < people; i++)
            birthdays[rand()%365] += 1;  //for each birth date generated by rand, (out of 365),
                                        //its corresponding element in birthdays will be incremented by 1 (birthdays array is initialized to 0).
        for(i = 0; i < 365; i++)        //changed.
            if(birthdays[i] >= 2)       //two or more people have same birthdays
                    flag=1;             //i.e. mapped to the same element in birthdays array.

        if(flag==1)
            count++;
    }
    p=count/1000;
    printf("\nThe number of sets out of 1000 which have clashing birthdays :: %f",count);
    printf("\nThe probability of people with matching birthday out of 1000 are :: %f",p);

    return 0;
}