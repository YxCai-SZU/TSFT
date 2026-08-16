#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    logic integer core_op(integer n, integer m) = n - 2 * m;

    lemma result_property:
        \forall integer n, m;
        valid_range(n) && valid_range(m) ==>
        (core_op(n, m) > 0 ==> core_op(n, m) > 0) && 
        (core_op(n, m) <= 0 ==> 0 == 0);
*/


int func(int n, int m) {
    int result;
    
    //@ assert valid_range(n);
    //@ assert valid_range(m);
    
    result = n - 2 * m;
    
    if (result > 0) {
        //@ assert result == core_op(n, m);
        return result;
    } else {
        //@ assert result <= 0;
        //@ assert 0 >= 0;
        return 0;
    }
}
