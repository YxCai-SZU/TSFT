#include <stdbool.h>

/*@ predicate even(integer k) = k % 2 == 0; */

/*@ logic integer adder(integer x, integer y) = x + y; */

/*@ predicate is_greater_than(integer x, integer k) = k > x; */

/*@ lemma test_even: 
      even(4) && !even(7); */

/*@ lemma test_adder: 
      adder(10, 20) == 30 && adder(10, 60) == 70; */

/*@ lemma test_is_greater_than: 
      is_greater_than(10, 20) && 
      !is_greater_than(10, 5); */

/*@ requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    bool r = true;
    
    //@ assert r == true;
    
    if (n != m)
    {
        r = false;
        //@ assert r == false;
    }
    
    //@ assert r == (n == m);
    
    return r;
}
