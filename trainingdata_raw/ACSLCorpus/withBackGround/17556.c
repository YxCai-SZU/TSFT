#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    logic integer div_3(integer x) = x / 3;
    logic integer mod_3(integer x) = x % 3;

    lemma division_property:
        \forall integer x; is_valid_range(x) ==> 
            div_3(x) * 3 + mod_3(x) == x;
*/

/*@
    requires is_valid_range(x);
    ensures \result == (x / 3 >= (x / 3 + (x % 3)));
*/
bool func(unsigned int x) {
    unsigned int a;
    unsigned int b;
    bool result;

    //@ assert is_valid_range(x);
    
    a = x / 3;
    b = x % 3;
    
    //@ assert a == div_3(x);
    //@ assert b == mod_3(x);
    
    result = (a >= (a + b));
    return result;
}
