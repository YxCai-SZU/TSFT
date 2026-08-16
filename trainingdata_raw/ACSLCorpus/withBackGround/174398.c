#include <stdbool.h>

/*@ predicate is_valid_range(integer a) = 0 <= a < 100; */

/*@ lemma comparison_lemma: 
      \forall integer a, b; 
      is_valid_range(a) && is_valid_range(b) ==> (a < b || a >= b); */

/*@ requires \valid(v+(0..1));
    requires is_valid_range(v[0]) && is_valid_range(v[1]);
    ensures \result == (v[0] < v[1]);
    assigns \nothing;
 */
bool func(int v[2]) {
    int a;
    int b;
    
    a = v[0];
    b = v[1];
    
    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert a < b || a >= b;
    
    if (a < b) {
        //@ assert a < b;
        return true;
    } else {
        //@ assert a >= b;
        return false;
    }
}
