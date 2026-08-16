#include <stdint.h>

/*@ predicate r_in_range(integer r) = 1 <= r && r <= 100; */

/*@ logic integer func_spec(integer r) = 3 * r * r; */

/*@ lemma no_overflow: 
      \forall integer r; r_in_range(r) ==> func_spec(r) <= 30000; */

/*@
    requires r_in_range(r);
    ensures \result == func_spec(r);
*/
int64_t func(int64_t r)
{
    //@ assert r_in_range(r);
    
    //@ assert func_spec(r) <= 30000;
    
    return 3 * r * r;
}

int main() {
    return 0;
}
