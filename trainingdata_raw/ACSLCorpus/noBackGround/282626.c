#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((((n)) / 15) * 200));
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int result;
    int count;
    int temp_n;
    
    // Precondition check
    //@ assert (1 <= (n) && (n) <= 100);
    
    // Overflow safety proof
    //@ assert n * 800 <= 100 * 800;
    
    result = n * 800;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= count <= n / 15;
        loop invariant temp_n >= 0;
        loop invariant temp_n == n - count * 15;
        loop invariant result == n * 800;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
        //@ assert temp_n == n - count * 15;
    }
    
    //@ assert count == n / 15;
    result = result - count * 200;
    
    // Final correctness proof
    //@ assert result == ((n) * 800 - ((((n)) / 15) * 200));
    
    return result;
}
