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

    if (arr[0] == arr[1] || arr[0] == arr[1] || arr[1] == arr[2]){
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
   cout << "You win!" << endl;
   return true;
}    

int main() {
    srand(time(NULL));
    int answer = GetValidRandomNumber();
    cout << answer << endl;
   
   int guess = 0;
   do {
    cin >> guess;
    } while (!CheckAnswer(answer, guess));
/*    
    cout << Check(934) << endl;
    cout << Check(134) << endl;
    cout << Check(001) << endl;
    cout << Check(123) << endl;
*/
}
