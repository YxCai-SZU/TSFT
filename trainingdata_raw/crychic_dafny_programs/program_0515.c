// Generated C + ACSL

/*@
    requires prices != \null;
    requires 1 <= prices_len <= 100000;
    requires \valid_read(prices + (0 .. prices_len-1));
    requires \forall integer i; 0 <= i < prices_len ==> 0 <= prices[i] <= 10000;
    assigns \nothing;
    ensures \forall integer i, j; 0 <= i < j < prices_len ==> \result >= prices[j] - prices[i];
    ensures \result >= 0;
*/
int best_time_to_buy_and_sell_stock(int* prices, int prices_len)
{
  int min_price = 10001;
  int max_profit = 0;
  /*@ assert max_profit >= 0 && max_profit <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= prices_len;
  loop invariant \forall integer j; 0 <= j < i ==> min_price <= prices[j];
  loop invariant \forall integer j, k; 0 <= j < k < i ==> max_profit >= prices[k] - prices[j];
  loop invariant min_price <= \at(min_price, LoopEntry);
  loop invariant max_profit >= \at(max_profit, LoopEntry);
  loop invariant max_profit >= 0;
  loop assigns i, min_price, max_profit;
  loop variant prices_len - i;
*/
  while ((i < prices_len))
    {
      int price = prices[i];
      if ((price < min_price))
      {
        min_price = price;
      }
      if (((price - min_price) > max_profit))
      {
        max_profit = (price - min_price);
      }
      i = (i + 1);
    }
  return max_profit;  // Dafny implicit return
}
