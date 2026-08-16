#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint16_t v;
} MyKey;

/*@ predicate valid_range(integer n, integer m) =
        1 <= n && n <= 16 &&
        1 <= m && m <= 16 &&
        n + m <= 16;

    predicate both_small(integer n, integer m) =
        n <= 8 && m <= 8;
*/

bool func(unsigned int n, unsigned int m)
{
    bool result;

    if (n > 8 || m > 8) {
        //@ assert n > 8 || m > 8;
        result = false;
    } else {
        //@ assert n <= 8 && m <= 8;
        result = true;
    }

    return result;
}

/*@ predicate key_model(MyKey k1, MyKey k2) = 
      k1.v == k2.v;
*/

/*@ lemma hash_axioms: 
      \forall MyKey k1, MyKey k2; 
      key_model(k1, k2) ==> (k1.v == k2.v ==> k1.v == k2.v);
*/

bool test_key(MyKey k1, MyKey k2) {
    return (k1.v == k2.v);
}

/*@
    predicate valid_key_range(MyKey k1, MyKey k2, integer n, integer m) =
        valid_range(n, m) &&
        key_model(k1, k2);
*/

bool process_key_and_range(MyKey k1, MyKey k2, unsigned int n, unsigned int m) {
    bool range_check = func(n, m);
    bool key_check;
    
    if (range_check) {
        //@ assert both_small(n, m);
        key_check = test_key(k1, k2);
        //@ assert key_check == (k1.v == k2.v);
    } else {
        //@ assert !both_small(n, m);
        key_check = false;
    }
    
    //@ assert (range_check == true) ==> (both_small(n, m) && (k1.v == k2.v));
    //@ assert (range_check == false) ==> (!both_small(n, m));
    
    return range_check && key_check;
}
