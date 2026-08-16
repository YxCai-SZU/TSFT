#include <stdint.h>

/*@
    predicate is_valid_range(integer x) = 0 <= x <= 100;
    
    logic integer func_spec(integer x) = x * x * x + x * 100 + 3;
    
    lemma x_square_bound: \forall integer x; 0 <= x <= 100 ==> x * x <= 10000;
    lemma x_cube_bound: \forall integer x; 0 <= x <= 100 ==> x * x * x <= 1000000;
*/

/*@
    requires is_valid_range(x);
    ensures \result == func_spec(x);
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    //@ assert 0 <= x && x <= 100;
    //@ assert x * x <= 10000;
    //@ assert x * x * x <= 1000000;
    return x * x * x + x * 100 + 3;
}

int main()
{
    return 0;
}
