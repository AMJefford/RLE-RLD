/*
* Student ID: 201343599
* Student Name: Ashley Jefford
* Email: a.m.jefford@student.liverpool.ac.uk
*
* User: sgajeffo
*
* Problem ID: 1086
* RunID: 14161
* Result: Accepted
*/

#include <stdio.h>
#include <string.h> //used for memset
#include <ctype.h> //used for isdigit
#include <stdlib.h> //used for atoi

void expand()
    {
      char holdCount[1024]; //hold count value
      char prevChar;
      char nextChar;

      scanf("%c", &nextChar);
      prevChar = nextChar;

      while (scanf("%c", &nextChar) != EOF)
      {
        if (prevChar == nextChar)
        {
          //if 2 consecutive chars followed by digit followed by *
          scanf("%c", &nextChar);
          if (isdigit(nextChar))
          {
            holdCount[0] = nextChar; //holdCount holds first integer
            scanf("%c", &nextChar);
            //while more than one consecutive number, append to holdCount
            while (isdigit(nextChar))
            {
              strncat(holdCount, &nextChar, 1);
              scanf("%c", &nextChar);
            }
            //if 2 consecutive chars, followed by 1 or more digits, followed by *
            if (nextChar == '*')
            {
              int count = atoi(holdCount); //convert holdCount to integer
              for (int i = 0; i < count; i++)
              {
                printf("%c", prevChar);
              }
            }
            //if consecutive chars followed by int, but not *
            else
            {
              printf("%c%s%c", prevChar, &holdCount, nextChar);

            }
            scanf("%c", &prevChar);
            memset(holdCount, 0, sizeof(holdCount)); //reset count
          }
        }
        //if consecutive chars not followed by a number
        else
        {
            //print char and update prev char to next char
            printf("%c", prevChar);
            prevChar = nextChar;
        }
      }
    }

void compress()
{
  char prevChar;
  char nextChar;
  int count = 1;

  scanf("%c", &nextChar);
  prevChar = nextChar; //set prev char to next char, so can enter loop with next char

  //while the next read char is not EOF continue
  while (scanf("%c", &nextChar) != EOF)
  {
    if (prevChar == nextChar) //if same character, continue
    {
      count++;
    }
    else if (count > 1)
    {
      //if more than 1 consecutive char, print char twice, count, and *
      printf("%c%c%d*", prevChar, prevChar, count);
      count = 1;
    }
    else
    {
      //if only one of char, print once
      printf("%c", prevChar);
    }
    //update prev char to next char
    prevChar = nextChar;
  }
}

int main()
{
  char letter; //store input of C or E
  scanf("%c", &letter);

  char throwAway = scanf("%c", &throwAway); //get rid of \n from after E input

  if (letter == 'C')
  {
    compress();
  }
  else if (letter == 'E')
  {
    expand();
  }

  //if neither input, do nothing
  return 0;
}
