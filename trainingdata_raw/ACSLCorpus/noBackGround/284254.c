#include <stdbool.h>

/*@
  requires 1 <= a <= 9;
  requires 1 <= b <= 9;
  requires 1 <= c <= 9;
  ensures \result == ((a < b && b < c) || (a > b && b > c));
  assigns \nothing;
*/
bool is_range(int a, int b, int c)
{
    bool result;
    //@ ghost int original_a = a;
    //@ ghost int original_b = b;
    //@ ghost int original_c = c;
    
    if ((a < b && b < c) || (a > b && b > c)) {
        //@ assert (original_a < original_b && original_b < original_c) || (original_a > original_b && original_b > original_c);
        result = true;
    } else {
        //@ assert !((original_a < original_b && original_b < original_c) || (original_a > original_b && original_b > original_c));
        result = false;
    }
    
    return result;
}
