#include<iostream>
using namespace std;

int main() {
    do {
        cout<<"1 .Addition \n2. Substraction \n3. Multiplication \n4. Division \n5. Remainder \n6. Exit\n\n";

        int choice, a, b;

        cout<<"Enter your choice"<<endl;
        cin>>choice;

        if(choice == 6) {
            cout<<"Exiting Calculator"<<endl;
            return 0;
        }

        cout<<"Enter two numbers"<<endl;
        cin>>a>>b;

        switch(choice) {
            case 1: cout<<"Sum of two numbers : "<<a + b<<endl;
                break;

            case 2: cout<<"Difference of two numbers : "<<a - b<<endl;
                break;
                    
            case 3: cout<<"Product of two numbers : "<<a * b<<endl;
                break;

            case 4: cout<<"Quotient after division is : "<<a / b<<endl;
                break;

            case 5: cout<<"Remainder after division is : "<<a % b<<endl;
                break;

        }
    } while(1 > 0);
}