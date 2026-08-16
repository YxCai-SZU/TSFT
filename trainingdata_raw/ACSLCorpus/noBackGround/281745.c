#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000 &&
        1 <= (m) && (m) <= 1000 &&
        0 <= (k) && (k) <= (n) * (m));
    ensures \result == true <==> (n * m - k) % 2 == 0;
    assigns \nothing;
*/
bool func(int n, int m, int k)
{
    // Variable declarations at scope top
    bool is_even = false;
    int count = 0;
    
    // Precondition verification
    //@ assert (1 <= (n) && (n) <= 1000 &&         1 <= (m) && (m) <= 1000 &&         0 <= (k) && (k) <= (n) * (m));
    
    // Proof of product bound
    //@ assert n * m <= 1000000;
    
    count = n * m - k;
    
    /*@
        loop invariant 0 <= count <= n * m;
        loop invariant count <= n * m - k;
        loop invariant count % 2 == (n * m - k) % 2;
        loop assigns count;
        loop variant count;
    */
    while (count >= 2)
    {
        count -= 2;
    }
    
    if (count == 0)
    {
        is_even = true;
    }
    
    // Postcondition verification
    //@ assert is_even == true <==> (n * m - k) % 2 == 0;
    
    return is_even;
}
