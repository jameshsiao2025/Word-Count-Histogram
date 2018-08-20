#include <iostream>
#include <cctype>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
    int count[26] = {0};
    int c = 0;
    int i = 0;
    int max = 0;
    int limit = 0;
    int col = 60;

   c = tolower(cin.get()) ;
	while ( ! cin.eof())
	{
	   if(isalpha(c))
	    {
         count[tolower(c) - 'a']++;
	    }
		c = cin.get() ;
	}

   for(int i = 0; i < 26; ++i)
   {
      printf("count[%c]\t:\t%4d\n", i+'a', count[i]);
   }

   for(i = 0; i < 26; i++)
   {
       if(count[i] > max)
        max = count[i];
   }

   for (i=0; i < 26; ++i)
   {
       printf("%8d : %c", count[i], i+ 'a');
       limit = count[i] * col / max;
       for (int j = 0 ; j < limit; ++j)
            cout << "=";

       cout << "\n" ;
   }

cout << "\n";
cout << "\n";
cout << "\n";

  for(int row = 24; row > 0 ; row--)
    {
        for(int column = 0; column < 26; column++)
        {
            limit = count[column]*24/max;
            if(limit >= row)
                cout << "*   ";
            else(cout << "    ");

        }
        cout << "\n";
    }

   for (i=0; i < 26; ++i)
       printf( "%-2c  ", i+ 'a');
   cout << "\n";


cout << "\n";

//creating array that contains the number of digits for each integer
int digitArray[26] = {0};
for(int i =0; i<26; i++)
{
int number = count[i];
int numDigits = 1;
while(number >= 10)
{
    number = number/10;
    numDigits++;
}
digitArray[i] = numDigits;

}



//veritcal number output
int maxRow = 1;
while(max >= 10)
{
    max = max/10;
    maxRow++;
}


int data[26] = {0};
for(int i=0; i<26; i++)
    data[i] = count[i];


for (int j=0; j< maxRow; ++j)
{
    for(int i=0; i< 26; i++)
    {
    //test for number of digits in current integer.
    int number = data[i];
    int numDigits = 1;
    while(number >=10)
       {
         number = number/10;
         numDigits++;
       }

    if(maxRow - digitArray[i] > j)
        cout << "    " ;
    else{
    //check to see how the total amount of digits compares to the current digits
    if(digitArray[i] <= 0 )
        cout << "    " ;
    else if(digitArray[i] != numDigits )
        {
         printf( "%-4d",0);
        }
    else{
        int baseTen = 10;
        while(data[i]> baseTen)
        {baseTen = baseTen * 10;}
        int remainder = data[i]% (baseTen/10);
        int firstDigit = data[i] - remainder;
        while(firstDigit >= 10)
        firstDigit = firstDigit/10;
        data[i] = remainder;
        printf( "%-4d", firstDigit);
        }
     digitArray[i]--;
     }
    }
    cout << "\n";
}

}
