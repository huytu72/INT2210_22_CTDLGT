#include <bits/stdc++.h>

using namespace std;

struct Item {
    int weight;
    int value;
    int index;
};

bool compare(Item a, Item b) {
    double ratio_a = static_cast<double>(a.value) / a.weight;
    double ratio_b = static_cast<double>(b.value) / b.weight;
    return ratio_a > ratio_b;
}

pair<vector<int>, int> knapsackGreedy(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<Item> items;

    for (int i = 0; i < n; ++i) {
        items.push_back(Item(weights[i], values[i], i));
    }

    sort(items.begin(), items.end(), compare);

    vector<int> knapsack(n, 0);
    int totalValue = 0;

    for (const Item& item : items) {
        if (capacity >= item.weight) {
            knapsack[item.index] = 1;
            totalValue += item.value;
            capacity -= item.weight;
        }
    }

    return make_pair(knapsack, totalValue);
}

int main() {
    vector<int> weights = {2, 3, 5, 7, 1, 4, 1};
    vector<int> values = {10, 5, 15, 7, 8, 9, 2};
    int capacity = 10;

    pair<vector<int>, int> result = knapsackGreedy(weights, values, capacity);

    cout << "Selected items: ";
    for (int i : result.first) {
        cout << i << " ";
    }

    cout << "\nTotal value: " << result.second << endl;

    return 0;
}

