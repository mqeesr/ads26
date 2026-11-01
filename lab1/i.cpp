#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){

    int t; cin >> t;

    while(t--){

        int n; cin >> n;

        deque<int> dq;
        for(int i = 1; i <= n; i++) dq.push_back(i);

        vector<int> card(n + 1);

        for(int i = 1; i <= n; i++){

            int size = dq.size(), moves = i % size;

            for(int i = 0; i < moves; i++){

                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
            }

            int pos = dq.front();
            dq.pop_front();
            card[pos] = i;
        }

        for(int i = 1; i <= n; i++){

            cout << card[i];
            if(i != n) cout << " ";
        }
        cout << "\n";
    }
}