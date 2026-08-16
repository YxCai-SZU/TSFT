#include <stdbool.h>

/*@ predicate in_range(integer v) = 1 <= v <= 9; */

/*@
  requires in_range(r) && in_range(g) && in_range(b);
  ensures \result == ((100 * r + 10 * g + b) % 4 == 0);
*/
bool func(long r, long g, long b)
{
    long sum;
    bool is_divisible;
    long abs_sum;
    long remainder;
    
    sum = 100 * r + 10 * g + b;
    is_divisible = false;
    abs_sum = sum;
    
    if (sum < 0) {
        abs_sum = -sum;
    }
    
    remainder = abs_sum;
    /*@
      loop invariant 0 <= remainder <= abs_sum;
      loop invariant remainder % 4 == abs_sum % 4;
      loop assigns remainder;
    */
    while (remainder >= 4) {
        remainder -= 4;
    }
    
    if (remainder == 0) {
        is_divisible = true;
    }
    
    return is_divisible;
}
