/*
Algorithm: Fractional Knapsack
Paradigm: Greedy
Time Complexity: O(n log n)
Space Complexity: O(1)

Description:
Selects items (including fractions) to maximize profit
within given capacity using value/weight ratio.
*/

#include <iostream>
#include <vector>
#include <algorithm>

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

int main() {

    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int W = 50;
    double profit = 0.0;

    sort(items.begin(), items.end(), compare);

    for(int i = 0; i < items.size(); i++) {

        if(W >= items[i].weight) {
            W -= items[i].weight;
            profit += items[i].value;
        }
        else {
            double ratio = (double)items[i].value / items[i].weight;
            profit += ratio * W;
            break;
        }
    }

    cout << "Maximum Profit: " << profit << endl;

    return 0;
}
