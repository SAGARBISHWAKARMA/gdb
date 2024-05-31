/*
Write the program expr, which evaluates a reverse Polish expression from the 
command line, where each operator or operand is a separate argument.
Author: Sagar
Create: 18 April 2024
*/

/*Required header Files*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*global variable*/
unsigned char stack_pointer = 0;
float stack[15];

/*function Prototypes*/
float pop(void);
void push(float element);

/*Main Function*/
int main(int argc, char **argv)
{
  char Error = 0;
  for (int i = 1; i < argc; ++i)
  {
    float number = atof(argv[i]);

    if (number || strcmp(argv[i], "0") == 0)
    {
      push(number);
    }
    else if (strlen(argv[i]) == 1)
    {
      if (stack_pointer >= 2 && stack_pointer < 15)
      {
        float number2 = pop();
        float number1 = pop();

        char op = *argv[i];
        switch (op)
        {
        case '+':
          push(number1 + number2);
          break;

         case '-':
          push(number1 - number2);
          break;

        case '*': /*this format should to given in a character form*/
          push(number1 * number2);
          break;

        case '/':
          if (number2 == 0)
          {
            Error = 4;
          }
          else
          {
            push(number1 / number2);
          }
          break;

        default:
          Error = 3;
          break;
        }
      }
      else
      {
        Error = 2;
      }
    }
    else
    {
      Error = 1;
    }
  }

  if (Error)
  {
    switch (Error)
    {
    case 1:
      printf("Error: arguments should be numbers or one of the following mathematical operations: '+', '-', '*', '/'.\n");
      break;

    case 2:
      printf("Error: too many or too few arguments.\n");
      break;

    case 3:
      printf("Error: invalid operation. use one of the following mathematical operations: '+', '-', '*', '/'.\n");
      break;

    case 4:
      printf("Error: division by zero (NaN).\n");
      break;

    default:
      break;
    }

    return EXIT_FAILURE;
  }

  printf("result: %f", pop());

  return EXIT_SUCCESS;
}/*Main Function end*/

/*pop function is to get data from stack*/
float pop(void)
{
  if (stack_pointer > 0)
  {
    return stack[stack_pointer--];
  }

  printf("Error: the stack is empty.\n");
  return 0;
}/*pop fuction end*/

/*push function is to store element in as stack*/
void push(float element)
{
  if (stack_pointer < 15)
  {
    stack[++stack_pointer] = element;
  }
  else
  {
    printf("Error: the stack is full.\n");
  }
}/*push function*/
