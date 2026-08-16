#include <limits.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;

    logic integer three_r_squared(integer r) = 3 * r * r;

    lemma monotonic_3_r_squared:
        \forall integer r; r_in_range(r) ==> three_r_squared(r) <= three_r_squared(r + 1);
*/

/*@
    requires r_in_range(r);
    ensures \result == three_r_squared(r);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int res;

    //@ assert r_in_range(r);
    //@ assert three_r_squared(r) <= three_r_squared(100);
    
    res = 3 * r * r;
    
    //@ assert res == three_r_squared(r);
    return res;
}

/*@
    lemma lemma_3_r_squared_is_monotonic:
        \forall integer r; r_in_range(r) ==> three_r_squared(r) <= three_r_squared(r + 1);
*/

#ifdef TESTING
#include <assert.h>

int main()
{
    // Variable declarations at top of scope
    int result1, result2, result3, result4, result5;
    int result6, result7, result8, result9, result10;
    
    result1 = func(1);
    result2 = func(2);
    result3 = func(3);
    result4 = func(4);
    result5 = func(5);
    result6 = func(6);
    result7 = func(7);
    result8 = func(8);
    result9 = func(9);
    result10 = func(10);
    
    assert(result1 == 3);
    assert(result2 == 12);
    assert(result3 == 27);
    assert(result4 == 48);
    assert(result5 == 75);
    assert(result6 == 108);
    assert(result7 == 147);
    assert(result8 == 192);
    assert(result9 == 243);
    assert(result10 == 300);
    
    return 0;
}
#endif
