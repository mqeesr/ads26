#include <iostream>
#include <deque>
using namespace std;

bool func(int c1, int c2){

    if(c1 == 0 && c2 == 9) return true;
    if(c1 == 9 && c2 == 0) return false;

    return c1 > c2;
}

int main(){

    deque<int> boris, nursik; int x;

    for(int i = 0; i < 5; i++){

        cin >> x;
        boris.push_back(x);
    }

    for(int i = 0; i < 5; i++){

        cin >> x;
        nursik.push_back(x);
    }

    int moves = 0;

    while(!boris.empty() && !nursik.empty()){

        int cardb = boris.front();
        boris.pop_front();
        int cardn = nursik.front();
        nursik.pop_front();

        moves++;

        if(func(cardb, cardn)){

            boris.push_back(cardb);
            boris.push_back(cardn);
        } else{
            nursik.push_back(cardb);
            nursik.push_back(cardn);
        }
    }

    if(boris.empty()) cout << "Nursik " << moves << endl;
    else cout << "Boris " << moves << endl;

}