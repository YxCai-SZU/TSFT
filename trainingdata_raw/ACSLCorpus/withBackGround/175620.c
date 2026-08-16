#include <stdbool.h>

/*@ predicate is_valid_pair(integer a, integer b) =
       1 <= a && a <= 16 &&
       1 <= b && b <= 16 &&
       a + b <= 16;
*/

/*@ logic integer max_val(integer a, integer b) =
       a > b ? a : b;
*/

/*@ lemma max_val_property:
       \forall integer a, b;
       max_val(a, b) == a || max_val(a, b) == b;
*/

/*@ requires is_valid_pair(v[0], v[1]);
    @ ensures \result == true <==> (v[0] <= 8 && v[1] <= 8);
    @*/
bool func(unsigned long long v[2])
{
    unsigned long long a;
    unsigned long long b;
    unsigned long long max;
    
    a = v[0];
    b = v[1];
    
    //@ assert is_valid_pair(a, b);
    
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    
    //@ assert max == max_val(a, b);
    //@ assert max == a || max == b;
    
    return max <= 8;
}
