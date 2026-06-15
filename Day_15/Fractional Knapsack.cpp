#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for(int i = 0; i < items.size(); i++) {

        if(W == 0) break;

        if(items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        }
        else {
            totalValue += (double)items[i].value * W / items[i].weight;
            W = 0;
        }
    }

    return totalValue;
}

int main() {

    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int W = 50;

    cout << "Max value: " << fractionalKnapsack(W, items) << endl;

    return 0;
}