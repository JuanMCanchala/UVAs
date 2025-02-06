#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <set>
#include <string>
#include <sstream>

using namespace std;

string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

void remove(deque<int>& piles, queue<int>& deck) {
    bool flag = true;
    while (piles.size() >= 3 && flag) {
        int n = piles.size();
        if ((piles[0] + piles[1] + piles[n - 1]) % 10 == 0) {
            deck.push(piles[0]);
            deck.push(piles[1]);
            deck.push(piles[n - 1]);
            piles.pop_front();
            piles.pop_front();
            piles.pop_back();
        } else if ((piles[0] + piles[n - 2] + piles[n - 1]) % 10 == 0) {
            deck.push(piles[0]);
            deck.push(piles[n - 2]);
            deck.push(piles[n - 1]);
            piles.pop_front();
            piles.pop_back();
            piles.pop_back();
        } else if ((piles[n - 3] + piles[n - 2] + piles[n - 1]) % 10 == 0) {
            deck.push(piles[n - 3]);
            deck.push(piles[n - 2]);
            deck.push(piles[n - 1]);
            piles.pop_back();
            piles.pop_back();
            piles.pop_back();
        } else {
            flag = false;
        }
    }
}


int main() {
    int card;
    string state;
    while(cin>>card && card != 0){
        queue<int> decks;
        int cardCount = 0;
        list<deque<int> > piles(7, deque<int>());
        decks.push(card);
        for (int i = 0; i < 51; i++) {
            cin >> card;
            decks.push(card);
        }
        set<string> repeat;
        bool flag = true;
        bool flag1 = true;
        for(int i = 0; i < 2; i++){
            for (list<deque<int> >::iterator it = piles.begin(); it != piles.end(); ++it) {
                it->push_back(decks.front());
                decks.pop();
                state = "";
                queue<int> tempDeck = decks;
                for (list<deque<int> >::iterator pile = piles.begin(); pile != piles.end(); ++pile) {
                    for (deque<int>::iterator card = pile->begin(); card != pile->end(); ++card) {
                        state += intToString(*card);
                    }
                }
                state += ",";
                while (!tempDeck.empty()) {
                    state += intToString(tempDeck.front());
                    tempDeck.pop();
                }
                repeat.insert(state);

            }
        }
        cardCount += 14;
        while (!decks.empty() && flag && flag1) {
            for (list<deque<int> >::iterator it = piles.begin(); it != piles.end() && !decks.empty() && flag1; ++it) {
                it->push_back(decks.front());
                decks.pop();
                cardCount++;
                if (it->size() >= 3) {
                    remove(*it, decks);
                }
                if (it->empty()) {
                    it = piles.erase(it);
                    --it;
                }
                state = "";
                queue<int> tempDeck = decks;
                for (list<deque<int> >::iterator pile = piles.begin(); pile != piles.end(); ++pile) {
                    for (deque<int>::iterator card = pile->begin(); card != pile->end(); ++card) {
                        state += intToString(*card);
                    }
                }
                state += ",";
                while (!tempDeck.empty()) {
                    state += intToString(tempDeck.front());
                    tempDeck.pop();
                }

                if (repeat.count(state)) {
                    flag1 = false;
                } else {
                    repeat.insert(state);
                }
            }
            if (piles.empty()) {
                flag = false;
            }
        }
        if (decks.size() == 52) {
            cout << "Win : " << cardCount << endl;
        } else if (decks.size() == 0) {
            cout << "Loss: " << cardCount << endl;
        } else {
            cout << "Draw: " << cardCount << endl;
        }
    }
}