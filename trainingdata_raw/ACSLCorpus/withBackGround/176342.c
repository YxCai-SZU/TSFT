#include <limits.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;

    logic integer func_spec(integer r) = 3 * r * r;

    lemma no_overflow_lemma:
        \forall integer r; r_in_range(r) ==> 
        (1 * r <= 100 * r) && (1 * r * r <= 100 * 100 * r);
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
    
    result = 3 * r;
    
    //@ assert result <= 3 * 100;
    
    //@ assert result * r <= 3 * 100 * 100;
    
    result = result * r;
    
    return result;
}

#ifdef TEST
#include <assert.h>

int main()
{
    int r = 5;
    int result = func(r);
    assert(result == 3 * r * r);
    return 0;
}
#endif
