#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int value;
};

bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;

    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);

    double totalValue = 0;

    for (auto &i : items)
    {
        if (W == 0)
            break;

        if (i.weight <= W)
        {
            W = W - i.weight;
            totalValue = totalValue + i.value;
        }
        else
        {
            totalValue = totalValue +
                         i.value * ((double)W / i.weight);
            W = 0;
        }
    }

    return totalValue;
}

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    double maxValue = fractionalKnapsack(W, items);

    cout << "Maximum value in knapsack = "
         << maxValue << endl;

    return 0;
}

/*Enter number of items: 3
Enter value and weight of each item:
60 10
100 20
120 30
Enter capacity of knapsack: 50*/