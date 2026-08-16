#include <stdbool.h>

/*@ predicate is_even(integer v) = v % 2 == 0; */

/*@
  requires 1 <= x <= 100;
  requires 1 <= y <= 100;
  ensures \result == true <==> (x + y) % 2 == 0 && y % 2 == 0 && x <= y;
*/
bool func(unsigned int x, unsigned int y)
{
    unsigned int sum;
    unsigned int x_div_2;
    unsigned int y_div_2;
    unsigned int sum_div_2;
    bool sum_is_even;
    bool y_is_even;
    bool x_leq_y;
    bool result;

    sum = x + y;
    x_div_2 = x / 2;
    y_div_2 = y / 2;
    sum_div_2 = sum / 2;

    sum_is_even = (sum % 2) == 0;
    y_is_even = (y % 2) == 0;
    x_leq_y = x <= y;

    //@ assert sum_div_2 >= 0;
    //@ assert sum_div_2 <= 100;
    //@ assert sum_is_even && y_is_even && x_leq_y <==> (x + y) % 2 == 0 && y % 2 == 0 && x <= y;

    result = sum_is_even && y_is_even && x_leq_y;
    return result;
}
