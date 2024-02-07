#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAXW 20
#define ITEMS 5

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
int KnapSack(int weights[], int values[],int selected_bool[]){
   int profitT[ITEMS+1][MAXW+1] = {0};
   MaxProfit(weights,values,profitT);
      ChooseItems(weights,values, profitT,selected_bool);
    return profitT[ITEMS][MAXW];
}
void ScanArrays(char items[], int values[], int weights[]) {
    for (int i = 0; i < ITEMS; ++i) {
        scanf(" %c", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);

    }
}


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

