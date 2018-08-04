
#include <wiringPi.h>
#include <stdio.h>
//#include <stdlib>
//#include "conio.h"

void forward(int x);
void reverse(int x);
void left(int x);
void right(int x);// 0,1  3,4
void stop();

int leftFwd = 0;
int leftBwd = 1; 22,26   24,27
int rightFwd = 3;
int rightBwd = 4;
int duration;


int main (void)
{
    char function;
    char function1;


    wiringPiSetup ();
    pinMode(leftFwd, OUTPUT);
    pinMode(leftBwd, OUTPUT);
    pinMode(rightFwd, OUTPUT);
    pinMode(rightBwd, OUTPUT);
    digitalWrite (leftFwd, LOW); digitalWrite(rightFwd, LOW);
    digitalWrite (leftBwd,LOW); digitalWrite(rightBwd, LOW);

    while(1)
    {
     
      //function1 = getch();
  
      printf("Enter the function: ");
      scanf("%c %c",&function, &function1);
      //function = getch();
      //function = getchar();
      fflush(stdin);
      printf("Entered character is %c \n", function);
      printf("Entered character is %c \n", function1);
      printf("Enter the Duration in ms: ");
      scanf("%d",&duration);
      fflush(stdin);

      if(function == 'f')
      {
        forward(duration);
      }
      else if(function == 'b')
      {
        reverse(duration);
      }
      else if(function == 'l')
      {
        left(duration);
      }
      else if(function == 'r')
      {
        right(duration);
      }
      else
	{
	   stop();	
	}


    

    }

  }

  void forward(int x)
  {
    digitalWrite (leftFwd, HIGH); digitalWrite(rightFwd, HIGH);
    delay(x);
    digitalWrite (leftFwd, LOW); digitalWrite(rightFwd, LOW);

  }

  void reverse(int x)
  {
    digitalWrite (leftBwd, HIGH); digitalWrite(rightBwd, HIGH);
    delay(x);
    digitalWrite (leftBwd, LOW); digitalWrite(rightBwd, LOW);

  }

  void left(int x)
  {
    digitalWrite (leftFwd, LOW); digitalWrite(rightFwd, HIGH);
    delay(x);
    digitalWrite (leftFwd, LOW); digitalWrite(rightFwd, LOW);

  }

  void right(int x)
  {
    digitalWrite (leftFwd, HIGH); digitalWrite(rightFwd, LOW);
    delay(x);
    digitalWrite (leftFwd, LOW); digitalWrite(rightFwd, LOW);

  }
  void stop()
{
digitalWrite (leftFwd, LOW); digitalWrite(rightFwd, LOW);
}


