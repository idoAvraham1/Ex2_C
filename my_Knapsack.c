#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAXW 20
#define ITEMS 5

/**
 * @brief Determine the selected items in the knapsack based on the dynamic programming solution.
 *
 * Given the weights, values, and the profit table calculated using the dynamic programming
 * approach, this function sets the selected_bool array to indicate which items are selected.
 *
 * @param weights The array of item weights.
 * @param values The array of item values.
 * @param profitT The profit table obtained from the dynamic programming approach.
 * @param selected_bool The array indicating whether an item is selected or not.
 */
void ChooseItems(int weights[], int values[], int profitT[][MAXW+1], int selected_bool[]){
    int i=ITEMS;
    int j= MAXW;
     for( int x=0; x<ITEMS;x++){
         selected_bool[x]=0;
     }

   while (i > 0 && j > 0) {
        int w_i=weights[i-1];


        if(profitT[i][j]>profitT[i-1][j]){
            selected_bool[i-1]=1;
            i=i-1;
            j=j-w_i;
        }
        else{
            i=i-1;
        }
    }
}

/**
 * @brief Calculate the maximum profit for the 0/1 knapsack problem using dynamic programming.
 *
 * This function populates the profit table for each subproblem.
 *
 * @param weights The array of item weights.
 * @param values The array of item values.
 * @param profitT The profit table to be populated.
 * @return The maximum profit for the given knapsack capacity.
 */
void MaxProfit(int weights[ITEMS], int values[], int profitT[][MAXW+1]) {
   for (int i = 0; i <= ITEMS; ++i) {
       for (int j = 0; j <= MAXW; j++) {
           if (j == 0 || i == 0) {
               profitT[i][j] = 0;
           }
       }
   }
   for (int i = 1; i <= ITEMS; i++) {
       for (int j = 1; j <= MAXW; j++) {
           if (weights[i - 1] <= j) {
               profitT[i][j] = MAX(profitT[i - 1][j],
                                   values[i - 1] + profitT[i - 1][j - weights[i - 1]]);
           } else {
               profitT[i][j] = profitT[i - 1][j];
           }
       }
   }
}

/**
 * @brief Solve the 0/1 knapsack problem and return the maximum profit.
 *
 * This function orchestrates the solution to the 0/1 knapsack problem by calling MaxProfit
 * and ChooseItems functions.
 *
 * @param weights The array of item weights.
 * @param values The array of item values.
 * @param selected_bool The array indicating whether an item is selected or not.
 * @return The maximum profit for the given knapsack capacity.
 */
int KnapSack(int weights[], int values[],int selected_bool[]){
   int profitT[ITEMS+1][MAXW+1] = {0};
   MaxProfit(weights,values,profitT);
      ChooseItems(weights,values, profitT,selected_bool);
    return profitT[ITEMS][MAXW];
}

// scan inpuy from the user
void ScanArrays(char items[], int values[], int weights[]) {
    for (int i = 0; i < ITEMS; ++i) {
        scanf(" %c", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);

    }
}

/**
 * @brief Print the names of selected items.
 *
 * This function prints the names of the items that are selected based on the solution to the
 * 0/1 knapsack problem.
 *
 * @param selected_bool The array indicating whether an item is selected or not.
 * @param items The array of item names.
 */
void PrintItems(int selected_bool[], char items[]) {
   printf("Selected items:");
   for (int i = 0; i < ITEMS; ++i) {

       if (selected_bool[i] == 1) {
           printf(" %c", items[i]);
       }
   }
    
}



int main() {
   char items[ITEMS];
   int values[ITEMS];
   int weights[ITEMS];
   int selected_bool[ITEMS];


   // Scan arrays from the user
   ScanArrays(items, values, weights);

   // Call KnapSack to calculate maximum profit and selected items
   int maxProfit = KnapSack(weights, values, selected_bool);

   // Print the maximum profit
   printf("Maximum profit: %d\n", maxProfit);
   //print selected items
   PrintItems(selected_bool,items);


   return 0;
}

