#include<iostream>
using namespace std;

int main() 
 {
    int num1,num2;
    char operation;
    cout<<"******!!!WELCOME TO SIMPLE CALCULATOR!!!*******\n\n";
  while(1)
  {
    //Input from user
    cout<<"Enter First Number:";
    cin>>num1;

    cout<<"Enter Second Number:";
    cin>>num2;

    cout<<"Chose Operation any one(+,-,*,/):";
    cin>>operation;

    // Perform calculation based on chosen operation
    switch (operation) 
     {
		case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
            
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
            
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
            
        case '/':
            if (num2 != 0) 
			       {
                      cout << "Result: " << num1 / num2 << endl;
                   } 
			else   {
                      cout << "Error: Cannot divide by zero." <<endl;
                   }
            break;
            
        default:
                 cout << "Invalid operation." << endl;
    }
  
  }
    return 0;
}
