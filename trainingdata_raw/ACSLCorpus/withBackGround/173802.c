#include <stddef.h>

/*@ predicate is_valid_range(integer n) = 1 <= n <= 10000; */

/*@ logic integer compute_change(integer n) =
      (n % 1000 != 0) ? (1000 - (n % 1000)) : 0; */

/*@ lemma change_bound: 
      \forall integer n; is_valid_range(n) ==> compute_change(n) <= 1000; */

/*@ requires is_valid_range(n);
    ensures \result <= 1000;
    ensures \result == compute_change(n); */
size_t func(size_t n)
{
    size_t r;
    size_t change;
    
    //@ assert is_valid_range(n);
    r = n % 1000;
    
    if (r != 0) {
        change = 1000 - r;
    } else {
        change = 0;
    }
    
    //@ assert change == compute_change(n);
    //@ assert change <= 1000;
    
    return change;
}
