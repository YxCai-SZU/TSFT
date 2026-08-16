#include <limits.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    ensures 1 <= \result <= 10000;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int ans;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) == a * b;
    //@ assert 1 <= ((a) * (b)) <= 10000;

    ans = a * b;
    
    //@ assert ans == ((a) * (b));
    return ans;
}
