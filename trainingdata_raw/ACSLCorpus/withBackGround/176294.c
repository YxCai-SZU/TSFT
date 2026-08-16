#include <stdbool.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
*/

/*@
    logic integer func_spec(integer r) = 3 * r * r;
*/

/*@
    lemma func_bound:
        \forall integer r;
            r_in_range(r) ==> func_spec(r) <= 3 * 100 * 100;
*/

/*@
    requires r_in_range(r);
    ensures \result == func_spec(r);
    assigns \nothing;
*/
int func(int r)
{
    int result;
    
    //@ assert r_in_range(r);
    //@ assert func_spec(r) <= 3 * 100 * 100;
    
    result = 3 * r * r;
    
    //@ assert result == func_spec(r);
    return result;
}

int main()
{
    return 0;
}
