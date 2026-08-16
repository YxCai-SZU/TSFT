#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;

    logic integer func_spec(integer n, integer k) =
        n <= k ? 0 : n - k;

    lemma func_properties:
        \forall integer n, k;
        valid_params(n, k) ==>
            func_spec(n, k) >= 0 &&
            func_spec(n, k) <= n &&
            (func_spec(n, k) == 0 ==> n <= k) &&
            (func_spec(n, k) > 0 ==> n > k);
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == 0 ==> n <= k;
    ensures \result > 0 ==> n > k;
    ensures \result == func_spec(n, k);
*/
int func(int n, int k)
{
    int result;
    //@ assert valid_params(n, k);
    
    if (n <= k)
    {
        result = 0;
        //@ assert result == 0 && n <= k;
    }
    else
    {
        result = n - k;
        //@ assert result > 0 && n > k;
    }
    
    //@ assert result == func_spec(n, k);
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    // Test case 1
    int r1 = func(5, 3);
    //@ assert r1 == 2;
    assert(r1 == 2);
    
    // Test case 2
    int r2 = func(10, 10);
    //@ assert r2 == 0;
    assert(r2 == 0);
    
    return 0;
}
#endif
