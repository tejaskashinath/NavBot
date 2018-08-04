#include<wiringPi.h>
#include<stdio.h>
void forward(int x);
void reverse(int x);
void left(int x);
void right(int x);

int leftFwd1 = 0;
int leftBwd1 = 1;
int rightFwd1 = 3;
int rightBwd1 = 4;

int leftFwd2 = 9;
int leftBwd2 = 26;
int rightFwd2 = 24;
int rightBwd2 = 97;

int duration;

int main(void)
{
  char function;
  wiringPiSetup ();
  pinMode(leftFwd1, OUTPUT);
  pinMode(leftBwd1, OUTPUT);
  pinMode(rightFwd1, OUTPUT);
  pinMode(rightBwd1, OUTPUT);
  pinMode(leftFwd2, OUTPUT);
  pinMode(leftBwd2, OUTPUT);
  pinMode(rightFwd2, OUTPUT);
  pinMode(rightBwd2, OUTPUT);

  digitalWrite (9, LOW);//RightFWD ->
  digitalWrite (26, LOW);//RightFWD <-
  digitalWrite (24, LOW);//RigthREAR ->
  digitalWrite (29, LOW);//RightREAR <-
  digitalWrite (0, LOW);//LeftREAR <-
  digitalWrite (1, LOW);//LeftREAR ->
  digitalWrite(3, LOW);//LeftFWD <-
  digitalWrite(4, LOW);//LeftFWD ->

  while(1)
  {
    printf("%s\n","enter the function" );
    scanf(" %c", &function);
    printf("%s\n", "enter duration in ms");
    scanf("%d", &duration);
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
  }

}

void forward(int x)
{
  digitalWrite (9, HIGH);digitalWrite(24, HIGH);
  digitalWrite (1, HIGH);digitalWrite(4, HIGH);
  delay(x);
  digitalWrite (9, LOW);digitalWrite(24, LOW);
  digitalWrite (1, LOW);digitalWrite(4, LOW);

}
void reverse(int x)
{
  digitalWrite (26, HIGH);digitalWrite(29, HIGH);
  digitalWrite (0, HIGH);digitalWrite(3, HIGH);
  delay(x);
  digitalWrite (26, LOW);digitalWrite(29, LOW);
  digitalWrite (0, LOW);digitalWrite(3, LOW);
}
void left(int x)
{
  digitalWrite (9, HIGH);digitalWrite(24, HIGH);
  digitalWrite (1, LOW);digitalWrite(4, LOW);
  delay(x);
  digitalWrite (9, LOW);digitalWrite(24, LOW);

}
void right(int x)
{
    digitalWrite (1, HIGH);digitalWrite(4, HIGH);
    digitalWrite (9, LOW);digitalWrite(24, LOW);
    delay(x);
    digitalWrite (1, LOW);digitalWrite(4, LOW);

}
