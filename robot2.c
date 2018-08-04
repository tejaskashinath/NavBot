#include<wiringPi.h>
#include<stdio.h>
//#include<softPwm.h> Enable If PWM is required
void forward(int x);
void reverse(int x);
void left(int x);
void right(int x);

int leftFwd1 = 0;
int leftBwd1 = 1;
int rightFwd1 = 3;
int rightBwd1 = 4;

int leftFwd2 = 5;
int leftBwd2 = 6;
int rightFwd2 = 25;
int rightBwd2 = 27;

int duration;

//wiringPiSetup (); //Uncomment this if using PWM. Comment same line in int main()
/*int softPwmCreate (0,100,100);
int softPwmCreate (1,100,100);
int softPwmCreate (3,100,100);   //Defines Software PWM on all motor pins
int softPwmCreate (4,100,100);
int softPwmCreate (5,100,100);
int softPwmCreate (6,100,100);
int softPwmCreate (25,100,100);
int softPwmCreate (27,100,100);*/
int main(void)
{
  char function;
  //wiringPiSetup ();
  pinMode(leftFwd1, OUTPUT);
  pinMode(leftBwd1, OUTPUT);
  pinMode(rightFwd1, OUTPUT);
  pinMode(rightBwd1, OUTPUT);
  pinMode(leftFwd2, OUTPUT);
  pinMode(leftBwd2, OUTPUT);
  pinMode(rightFwd2, OUTPUT);
  pinMode(rightBwd2, OUTPUT);

  digitalWrite (5, LOW);//RightFWD ->
  digitalWrite (6, LOW);//RightFWD <-
  digitalWrite (25, LOW);//RigthREAR ->
  digitalWrite (27, LOW);//RightREAR <-
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
  digitalWrite (5, HIGH);digitalWrite(25, HIGH);
  digitalWrite (1, HIGH);digitalWrite(4, HIGH);
  delay(x);
  digitalWrite (5, LOW);digitalWrite(25 LOW);
  digitalWrite (1, LOW);digitalWrite(4, LOW);

}
void reverse(int x)
{
  digitalWrite (6, HIGH);digitalWrite(27, HIGH);
  digitalWrite (0, HIGH);digitalWrite(3, HIGH);
  delay(x);
  digitalWrite (6, LOW);digitalWrite(27, LOW);
  digitalWrite (0, LOW);digitalWrite(3, LOW);
}
void left(int x)
{
  digitalWrite (5, HIGH);digitalWrite(25, HIGH);
  digitalWrite (1, LOW);digitalWrite(4, LOW);
  delay(x);
  digitalWrite (5, LOW);digitalWrite(25, LOW);

}
void right(int x)
{
    digitalWrite (1, HIGH);digitalWrite(4, HIGH);
    digitalWrite (6, LOW);digitalWrite(27, LOW);
    delay(x);
    digitalWrite (1, LOW);digitalWrite(4, LOW);

}
/*void softPwmWrite (0,50);
void softPwmWrite (1,50);    // Code Block to Reduce Duty cycle to 50%
void softPwmWrite (3,50);   // Change second value in bracket to change duty cycle.
void softPwmWrite (4,50);
void softPwmWrite (5,50);
void softPwmWrite (6,50);
void softPwmWrite (25,50);
void softPwmWrite (27,50);
*/
