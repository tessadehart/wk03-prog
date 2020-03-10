#include <stdio.h>
#define STOPS 4

//floor array
int floor[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 10, 11, 12, 13, 14, 15}; //floors
//strings
char ding[] = "DING"; //"DING" string
char qstn[] = "What floor would you like to go to? "; //asks for input
char crrf[] = "The current floor is "; //tells the user what floor they are on
char topf[] = ", the bottom floor is 0 and the top floor is 15.";
char rsp1[] = "Please enter four valid floors between 0 and 15."; //response 1 - incorrect floor num
//int array for floor input
int stops[4];
//int variables for moving floors
int start = 0;
int next = 0;

//methods
int moveUpFloor(int stops[])
{
    start = 0;
    //orders floor requests numerically - ascending
    for (int i = 0; i < STOPS; i++)         //Loop for ascending ordering
	{
		for (int j = 0; j < STOPS; j++)     //Loop for comparing other values
		{
			if (stops[j] > stops[i])        //Comparing other array elements
			{
				int tmp = stops[i];         //Using temporary variable for storing last value
				stops[i] = stops[j];        //replacing value
				stops[j] = tmp;             //storing last value
			}  
		}
	}

    for (int i = 0; i < STOPS; i++)
    {
        next = stops[i];
        for (int j = start; j < next; j++)
        {
            printf("%d ", floor[j]);
        }
        printf("%s\n", ding);
        start = stops[i];
    }
}

int inputFloor()
{
    printf("%s%s%d%s\n", qstn, crrf, start, topf); //asks for input
    scanf("%d%d%d%d", &stops[0], &stops[1], &stops[2], &stops[3]); //assigns input to stops[] array
    
    //checking input
    int error = 0;
    for (int i = 0; i < STOPS; i++)
    {
        if (stops[i] > 15 || stops[i] < 0)
        {
            error++;
        }
    }
    
    if (error > 0)
    {
        printf("%s\n", rsp1);
        inputFloor();
    }
    else
    {
        moveUpFloor(*stops);
    }
}

//main method
int main() 
{
    inputFloor();
}