#include <stdint.h>

/*@
    predicate is_integer(int64_t x) = x == (int64_t)x;

    logic integer func_result(integer x) = 1 - x;

    lemma func_post_cond:
        \forall integer x; 0 <= x <= 1 ==>
            (x == 0 ==> func_result(x) == 1) &&
            (x == 1 ==> func_result(x) == 0);
*/

/*@
    requires 0 <= x <= 1;
    requires is_integer(x);
    ensures (x == 0 ==> \result == 1);
    ensures (x == 1 ==> \result == 0);
    ensures 0 <= \result <= 1;
*/
int64_t func(int64_t x)
{
    int64_t result;
    
    //@ assert 0 <= x <= 1;
    //@ assert is_integer(x);
    
    if (x == 0) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert 1 - x == 1 - (int64_t)x;
    //@ assert result == 1 - x;
    //@ assert (x == 0 ==> result == 1) && (x == 1 ==> result == 0);
    //@ assert 0 <= result <= 1;
    
    return result;
}

int main()
{
    return 0;
}
