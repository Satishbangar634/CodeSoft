#include<iostream>
#include<cstdlib>
#include<ctime>
// #include<bits/stdc++.h>
using namespace std;

int main() 
 {
    srand(time(0));  // Seed the random number generator with the current time
    int secNumber = rand() % 100 + 1;  // Generate a random number between 1 and 100
    int a;
    int attempts = 0;

    cout << "!!!Welcome to the Number Guessing Game!!!\n\n";
    cout << " picked a number between 1 to 100 and Try to guess it.\n\n";

    do {
          cout << "Enter your guess: ";
          cin >> a;
          attempts++;

        if (a < secNumber)
		       {
                 cout << "To low Try again.\n";
               }
	    else if (a > secNumber)
		       {
                 cout << "To high Try again.\n";
               }
	    else   {
                 cout << "Congratulations!! You guessed the number in " << attempts << " attempts.\n";
               }
       } 
	while (a != secNumber);
	cout<<"\n****!!!thank you!!!****";

    return 0;
}
