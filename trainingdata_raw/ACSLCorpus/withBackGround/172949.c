#include <stdbool.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer func_result(integer r) = 3 * r * r;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int ans;
    int i;

    // Upper bound check
    //@ assert 1 <= r && r <= 100;
    //@ assert r <= 100;
    
    // Adding explicit bounds to avoid overflow/underflow
    //@ assert 3 * 1 <= 3 * r;
    //@ assert 3 * r <= 3 * 100;
    
    // Ensuring no overflow/underflow for the expression 3 * r * r
    //@ assert 3 * 1 * 1 <= 3 * r * r <= 3 * 100 * 100;

    ans = 3 * r * r;
    
    // Example loop to demonstrate the invariants
    i = 0;
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= i <= 10;
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10)
    {
        i += 1;
    }

    return ans;
}

int main()
{
    return 0;
}
