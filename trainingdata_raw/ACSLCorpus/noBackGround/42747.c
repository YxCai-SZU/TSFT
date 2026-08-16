#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    ensures 0 <= \result <= 10000;
*/
int func(int n, int a)
{
    // Variable declarations at scope top
    int i = 0;
    int sum = 0;
    int result = 0;

    //@ assert (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant sum == i;
        loop invariant (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
        loop assigns i, sum;
    */
    while (i < n)
    {
        sum += 1;
        i += 1;
    }
    
    //@ assert i == n;
    //@ assert sum == n;
    
    // Apply the lemma
    //@ assert 0 <= n * n - a <= 10000;
    
    result = n * n - a;
    //@ assert result == ((n) * (n) - (a));
    
    return result;
}
