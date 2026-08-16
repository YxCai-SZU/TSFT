/*@
    predicate valid_range(integer n) = 1 <= n <= 1000000000;
    
    logic integer half_minus_one(integer n) = (n - 1) / 2;
    
    lemma loop_maintains_invariant:
        \forall integer n, result, count;
        valid_range(n) &&
        0 <= result <= n - 1 &&
        0 <= count <= half_minus_one(n) &&
        result == n - 1 - 2 * count &&
        result >= 2
        ==>
        0 <= result - 2 <= n - 1 &&
        0 <= count + 1 <= half_minus_one(n) &&
        result - 2 == n - 1 - 2 * (count + 1);
*/

#include <stdint.h>

/*@
    requires valid_range(n);
    ensures \result == half_minus_one(n);
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t count;
    
    result = n - 1;
    count = 0;
    
    //@ ghost int64_t original_n = n;
    
    /*@
        loop invariant 0 <= result <= original_n - 1;
        loop invariant 0 <= count <= half_minus_one(original_n);
        loop invariant result == original_n - 1 - 2 * count;
        loop assigns result, count;
        loop variant result;
    */
    while (result >= 2)
    {
        //@ assert result >= 2;
        result = result - 2;
        count = count + 1;
    }
    
    //@ assert count == half_minus_one(original_n);
    return count;
}
