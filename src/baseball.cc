#include <iostream>
#include <cstdlib>

using namespace std;
bool Check(int n) {
    if (n < 100) {
    return false;
    }
    int arr[3];
    arr[0] = n / 100;
    n = n - arr[0] * 100;
    arr[1] = n / 10;
    n = n - arr[1] * 10;
    arr[2] = n;

    if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2]){
        return false;
    }
    return true;
}

int GetValidRandomNumber() {
    int n = 0;
    
    do {
        n = rand() % 1000;
    }
    while (!Check(n));
    return n;
}

bool CheckAnswer(int answer, int guess) {
    //if it is 3 strikes, print "you win" and return true
    //if not print x strikes, y balls" and return false
   int aarr[3], garr[3];
   if(answer == guess) {
    cout << "You win!!" << endl;
    return true;
    }
    else {
        for(int i = 0; i < 3; i = i+1) {
            aarr[i] = answer % 10;
            garr[i] = guess % 10;
            answer = answer / 10;
            guess = guess / 10;
        }
        int strikes = 0;
        int balls = 0;
        for(int i = 0; i < 3; i = i+1) {
            for (int j = 0; j < 3; j= j+1) {
                if (aarr[i] == garr[j]) {
                    strikes = strikes + (i==j);
                    balls = balls + (i!=j);
                    }
                }
            }
            cout << strikes << " strikes: " << balls << " balls" << endl;
            return false;
            }
    }

    

int main() {
    srand(time(NULL));
    int answer = GetValidRandomNumber();
   
    int guess = 0;
    for (int i = 0; i < 10; i =i+1) {
        cin >> guess;
        if(CheckAnswer(answer, guess)) break;
    }

    if(!CheckAnswer(answer, guess))
        cout << "No right guesses" << endl;

    else
        cout << answer << endl;
    
/*    do {
    cin >> guess;
    } while (!CheckAnswer(answer, guess));
*/
/*    
    cout << Check(934) << endl;
    cout << Check(134) << endl;
    cout << Check(001) << endl;
    cout << Check(123) << endl;
    hello test
*/
}
