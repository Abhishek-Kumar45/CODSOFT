#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int randomNumber = rand() % 100 + 1;
    int userGuess = -1;

    cout<<"Guess a number between 1 and 100"<<endl;

    while(userGuess != randomNumber) {
        cin>>userGuess;

        if(userGuess == randomNumber) {
            cout<<"Congratulations! You guessed the correct number: "<<randomNumber<<endl;
            
        }
        else if(userGuess > randomNumber) {
            cout<<"Too High, Guess Again :)"<<endl;
        }
        else {
            cout<<"Too Low, Guess Again :)"<<endl;
        }
    }
    return 0;
}