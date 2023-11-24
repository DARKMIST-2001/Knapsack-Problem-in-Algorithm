#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct {
    double weight, profit, profitPweight;
} item;

void showVec(string vecName, vector<item> items) {
    cout << vecName << " : " << endl;
    for (int i = 0; i < (int)items.size(); i++) {
        cout << i << " " << items[i].profit << " " << items[i].weight << " " << items[i].profitPweight << endl;
    }
    cout << endl;
}

bool cmp(item A, item B) {
    return A.profitPweight > B.profitPweight;
}

double fractionalKnapsack(vector<item> itemList, double RemSpace) {

    sort(itemList.begin(), itemList.end(), cmp);

    showVec("After Sorting the vec", itemList);

    double totalPriceAchieved = 0.0;
    for (int i = 0; i < (int)itemList.size(); i++) {
        if (itemList[i].weight <= RemSpace) {
            totalPriceAchieved += itemList[i].profit;
            RemSpace -= itemList[i].weight;
        } else {
            totalPriceAchieved += (RemSpace * itemList[i].profitPweight);
            RemSpace = 0.0;
            break;
        }
    }
    return totalPriceAchieved;
}

int main() {
    int TotalItem;
    double TotalSpace;
    item TempItem;

    cout << "Enter the total number of items and the total space: ";
    cin >> TotalItem >> TotalSpace;

    vector<item> itemList;

    cout << "Enter profit and weight for each item:" << endl;
    for (int i = 0; i < TotalItem; i++) {
        cin >> TempItem.profit >> TempItem.weight;
        TempItem.profitPweight = TempItem.profit / TempItem.weight;
        itemList.push_back(TempItem);
    }
    showVec("ItemList after Input", itemList);

    cout << "Total Price Achieved from This Knapsack: " << fractionalKnapsack(itemList, TotalSpace) << endl;

    return 0;
}
