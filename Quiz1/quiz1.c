/*
    Programming Assignment 1
    Due 2020.02.17

    In this programming assignment you will implement one or more 
    of the integer multiplication algorithms described in lecture.

    So: what's the product of the following two 64-digit numbers?

    3141592653589793238462643383279502884197169399375105820974944592 

    2718281828459045235360287471352662497757247093699959574966967627

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void divideToPara(char* a, char* b, int size)
{
    if (size > 2)
    {
        //divideToPara();
    }
    
    char* temp1, temp2, temp3, temp4;
    store(a, temp1, temp2, size);
    store(b, temp3, temp4, size);
    size = size / 2;
    karatsuba(temp1, temp2, temp3, temp4, size);
}

void store(char* origin, char* c2, char* c3, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        c2[i] = origin[i];
    }
    for (int i = size / 2; i < size; i++)
    {
        c3[i] = origin[i];
    }
    
}

int karatsuba(char* arg1, char* arg2, char* arg3, char* arg4, int size)
{

    int num1 = atoi(arg1);
    int num2 = atoi(arg2);
    int num3 = atoi(arg3);
    int num4 = atoi(arg4);
    int step1 = num1 * num3;
    int step2 = num2 * num4;
    int step3 = (num1 + num2) * (num3 + num4);
    int step4 = step3 - step2 - step1;
    int ans1 = num1 * num3 * (int)pow(10, strlen(arg2)*2);
    int ans2 = step4 * (int)pow(10, strlen(arg2));
    int result = ans1 + step2 + ans2;
    return result;
}



int main()
{
    char* num1 = malloc(sizeof(char) * 65);
    char* num2 = malloc(sizeof(char) * 65);
    
    sprintf(num1, "3141592653589793238462643383279502884197169399375105820974944592");
    sprintf(num2, "2718281828459045235360287471352662497757247093699959574966967627");

    
    return 0;
}