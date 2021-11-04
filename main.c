#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mainPrompt();
void caseOne();
void caseTwo();
void caseThree();

int main()
{
    char option;

    do
    {

        option = mainPrompt();

        switch(option)
        {
        case '0':
            printf("EXITING PROGRAM...");
            break;
        case '1':
        {
            caseOne();
            break;
        }
        case '2':
        {
            caseTwo();
            break;
        }
        case '3':
        {
            caseThree();
            break;
        }
        default:
            printf("*****INVALID INPUT: MUST INPUT OPTIONS EITHER 1, 2, 3, OR 0 TO TERMINATE PROGRAM*****\n\n");
            continue;
        }

    }
    while(option != '0');


    return 0;
}





int mainPrompt()
{
    int option;
    printf("\t\t\t*****PLEASE SELECT AN OPTION*****\n");
    printf("1: Ascertain the average for integer and double values\n");
    printf("2: Ascertain whether a number is prime\n");
    printf("3: Ascertain whether a certain coordinate point is inside of a circle\n");
    scanf(" %c", &option);
    while ((getchar()) != '\n');
    printf("\n");
    return option;
}





void caseOne()
{
    int numOfValidInputs;
    int validIntCount = 0;
    int validDoubCount = 0;
    int myInt;
    double myDoub;
    int intSum = 0;
    double doubSum = 0;
    double averInt = 0;
    double averDoub = 0;


    while(1)
    {
        printf("Enter a double value, then an integer value and separate them with a coma ',' in between with no spaces.\n");
        numOfValidInputs = scanf(" %lf, %d", &myDoub, &myInt);
        while ((getchar()) != '\n');
        if(numOfValidInputs == 0 )
        {
            printf("No Valid Inputs\n\n");
            break;
        }
        else if(numOfValidInputs == 1)
        {
            printf("One Valid Input\n\n");
            doubSum += myDoub;
            validDoubCount++;
            break;
        }
        else
        {
            printf("All Valid Inputs\n\n");
            doubSum += myDoub;
            intSum += myInt;
            validDoubCount++;
            validIntCount++;
        }
    }

    averDoub = doubSum/validDoubCount;
    averInt = (double)intSum/validIntCount;
    printf("The average of all %d doubles is %.4lf\n", validDoubCount, averDoub);
    printf("The average of all %d integers is %.4lf\n\n\n", validIntCount, averInt);
}




void caseTwo()
{
    _Bool isPrime;
    int numOfValidInputs;
    long unsigned myInt;
    int unsigned primeCount = 2;
    int primes[100000];
    primes[0] = 2;
    primes[1] = 3;
    int h = 1;
    int i = 1;
    int j = 0;
    int k = 0;

    while(1)
    {
        isPrime = 1;
        myInt = 0;
        int ch;

        printf("Enter a positive integer value and find out whether it is a prime number or not.\n");
        numOfValidInputs = scanf(" %u", &myInt);
        printf("\n");

        while ((getchar()) != '\n');

        if(numOfValidInputs == 0)
        {
            printf("*****INVALID INPUT: MUST INPUT A POSITIVE INTEGER*****\n\n");
            printf("If you want to exit the prime number program enter the letter x into the keyboard and press enter with no leading spaces, otherwise, enter any other key to proceed.\n\n");


            if((ch = getchar())== 'x')
            {
                while ((getchar()) != '\n');
                return;
            }

            else continue;
        }
        else
        {

            while(k < (int)sqrt(myInt))
            {

                j = 6*i-1;
                k = 6*i+1;

                for(h = 1; h < primeCount; h++)
                {
                    if(j%primes[h] == 0)    break;
                }
                if(h == primeCount)
                {
                    primes[primeCount] = j;
                    primeCount++;
                }


                for(h = 1; h < primeCount; h++)
                {
                    if(k%primes[h] == 0)    break;
                }
                if(h == primeCount)
                {
                    primes[primeCount] = k;
                    primeCount++;
                }

                i++;
            }

            for(int x = 0; x < primeCount; x++)
            {

                if((myInt%primes[x]) == 0 && myInt != primes[x])
                {
                    printf("The number you have entered is a composite number rather than a prime.\n");
                    printf("%d is a prime factor of %u\n\n", primes[x], myInt);
                    isPrime = 0;
                    break;
                }
            }

            if(isPrime)
            {
                printf("%u is a prime.\n", myInt);
                printf("Its only factors are 1 and itself.\n\n");
            }

        }

        printf("If you want to exit the prime number program enter the letter x into the keyboard and press enter with no leading spaces, otherwise, enter any other key to proceed.\n\n");
        if((ch = getchar())== 'x')
        {
            while ((getchar()) != '\n');
            return;
        }
        else continue;
    }

}




void caseThree()
{
    while(1)
    {
        int ch;
        double circleX;
        double circleY;
        double radius;
        double pointX;
        double pointY;
        double answer;
        double margin;

        printf("\nEnter an x and y coordinate pair for the center of your circle.\n");
        printf("When you input the coordinate, enter it in this format \"(x,y)\" where you include the parentheses and coma with no spaces in between.\n");
        scanf("( %lf, %lf)",&circleX,&circleY);
        while ((getchar()) != '\n');
        printf("\n\nEnter the radius for your circle. Input a numeric value with no spaces please.\n");
        scanf(" %lf", &radius);
        while ((getchar()) != '\n');
        printf("\n\nEnter a coordinate point and we will determine whether that point is outside, within, or on the perimeter of your circle.\n");
        printf("When you you input the coordinate put it this format \"(x,y)\" where you include the parentheses and coma with no spaces in between.\n");
        scanf("( %lf, %lf)",&pointX,&pointY);
        while ((getchar()) != '\n');
        answer = sqrt(pow(pointX-circleX,2) + pow(pointY-circleY,2));
        margin = fabs(answer - radius);
        if(margin < .001)
        {
            printf("\n\nThe coordinate point you entered is on the perimeter of the circle!\n\n");
        }
        else if(answer > radius)
        {
            printf("\n\nThe coordinate point you entered is outside of the circle!\n\n");
        }
        else
        {
            printf("\n\nThe coordinate point you entered is inside of the circle!\n\n");
        }

        printf("If you want to exit the circle program enter the letter x into the keyboard and press enter with no leading spaces, otherwise, enter any other key to proceed.\n\n");
        if((ch = getchar())== 'x')
        {
            while ((getchar()) != '\n');
            return;
        }
        else continue;
    }
}
