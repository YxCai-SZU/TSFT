#include <stdbool.h>

/*@ predicate has_profit_condition(integer actual_cost, integer sale_amount) =
      actual_cost >= 0 && sale_amount >= 0;
*/

/*@ predicate profit_result(integer actual_cost, integer sale_amount, bool result) =
      result == (sale_amount > actual_cost);
*/

bool has_profit(long actual_cost, long sale_amount)
{
    bool result;
    
    //@ assert actual_cost >= 0;
    //@ assert sale_amount >= 0;
    
    result = sale_amount > actual_cost;
    
    //@ assert result == (sale_amount > actual_cost);
    return result;
}

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate x_in_range(integer x) = 1 <= x && x <= 200;
    predicate i_in_range(integer i, integer x) = 0 <= i && i <= x + 1;
*/

_Bool func(unsigned int a, unsigned int b, unsigned int x)
{
    unsigned int i;
    
    i = 0;
    while (i < x + 1)
    {
        i = i + 1;
    }
    
    //@ assert i > x;
    
    return (a <= x) && (x <= a + b);
}

/*@
  predicate valid_price_range(integer price) = 1 <= price && price <= 200;
  predicate valid_cost_range(integer cost) = 1 <= cost && cost <= 100;
  predicate valid_markup_range(integer markup) = 1 <= markup && markup <= 100;
  
  predicate profitable_item(integer cost, integer markup, integer price, bool profit) =
      profit == (price > cost);
*/

bool check_item_profit(unsigned int cost, unsigned int markup, unsigned int price)
{
    bool is_profitable;
    
    int in_range = func(cost, markup, price);
    
    //@ assert has_profit_condition((long)cost, (long)price);
    is_profitable = has_profit((long)cost, (long)price);
    
    //@ assert is_profitable == (price > cost);
    //@ assert in_range == (cost <= price && price <= cost + markup);
    
    //@ assert (in_range && is_profitable) ==> (price > cost && price <= cost + markup);
    
    return is_profitable;
}
