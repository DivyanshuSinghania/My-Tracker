// This is Ques of Trading Accuracy with time

// example: 

// you have 3 type of items,
// with each quantity {100,60,120}
// with each weighting {20,10,30} overall not per item

// now you have a bag that can handle infinite number of item
// but do have a weight limit, tell the maximum quantity to be fitted in bag
// its a common problem in real world
// where you need to optimize two factors when you dont have one

// So the GREEDY Approach tells us to pick the best option we encounter first
// instead of best possible, this will lead to a good enough solution

#include <iostream>
#include <vector>
using namespace std;

int GreedyFractionalKnapsack(int limit, vector<int> items, vector<int> weights){
    int bag_weight = 0;
    int bag_items = 0;
    for (int i = 0; i < items.size(); i++)
    {
        bag_weight += weights[i];
        bag_items += items[i];
        if (bag_weight>limit)
        {
            int extra = bag_weight-limit;
            float frac = float(extra)/float(weights[i]);
            float extra_items = items[i]*frac;
            return (bag_items-extra_items);
        }
    }
    return limit;
}

int main() {
    vector<int> items;
    vector<int> weights;

    int n = 0;
    cout << "Number of items" << endl;
    cin >> n;

    int limit = 0;
    cout << "Weight limit of bag" << endl;
    cin >> limit;

    for (int i = 0; i < n; i++)
    {
        int q = 0;
        int w = 0;

        cout << "Quantity of item number " << i+1 << endl;
        cin >> q;
        items.push_back(q);    

        cout << "Overall Weight of items :" << endl;
        cin >> w;
        weights.push_back(w);    
    }
    
    cout << GreedyFractionalKnapsack(limit, items, weights) << endl;

    return 0;
}
