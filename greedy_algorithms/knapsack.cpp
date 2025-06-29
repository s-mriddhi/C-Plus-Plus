#include <iostream>
using namespace std;

struct Item { 
    int weight;
    int profit;
};

//function to calculate input data for algo which is profit/wt of each item 
float profitPerUnit(Item x) { return (float)x.profit / (float)x.weight; } 

int partition(Item arr[], int low, int high) {
    Item pivot = arr[high];  // pivot
	@@ -39,32 +40,38 @@ void quickSort(Item arr[], int low, int high) {

int main() {
    cout << "\nEnter the capacity of the knapsack : ";
    float capacity; //constraint 
    cin >> capacity;
    cout << "\n Enter the number of Items : ";
    int n;
    cin >> n;
    //create item data structure, array here of size n
    Item *itemArray = new Item[n];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter the weight and profit of item " << i + 1 << " : ";
        cin >> itemArray[i].weight;
        cin >> itemArray[i].profit;
    }

    quickSort(itemArray, 0, n - 1); // sorts by profitperunit parameter in the partition function

    // show(itemArray, n);
    //Apply algorithm ->
    float maxProfit = 0;
    int i = n;
    while (capacity > 0 && --i >= 0) {
        //start from item with largest profitperunit
        if (capacity >= itemArray[i].weight) {
            //Add to the profit and reduce the capacity
            maxProfit += itemArray[i].profit;
            capacity -= itemArray[i].weight;
            //Print the respective wt taken and profit of that item
            cout << "\n\t" << itemArray[i].weight << "\t"
                 << itemArray[i].profit;
        } else {
            // take the fraction of item wt such that capacity is exhausted but not overloaded
            maxProfit += profitPerUnit(itemArray[i]) * capacity;
            //print the fractional wt taken and profit obtained on this wt of item
            cout << "\n\t" << capacity << "\t"
                 << profitPerUnit(itemArray[i]) * capacity;
            capacity = 0;
	
