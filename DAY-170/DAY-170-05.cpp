#include <bits/stdc++.h>
using namespace std;
//122. Best Time to Buy and Sell Stock II (Space optimization)
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:

    int solveSO(vector<int> &prices){
        int n = prices.size();
       vector<int> curr (2,0);
       vector<int> next (2,0);

        for(int index= n-1;index>=0;index--){
            for(int buy = 0 ;buy<=1;buy++ ){
                int profit =0;
                if(buy){
                    int buyit =  -prices[index]  +  next[0];
                    int buynot = 0 + next[1];
                    profit  = max(buyit,buynot); 
                }
                else{
                    int sellit =  prices[index]  + next[1];
                    int sellnot = 0 + next[0];
                    profit  = max(sellit,sellnot); 

                }
                curr[buy] = profit;

            }
            next  =curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        
        return solveSO(prices);
    }
};