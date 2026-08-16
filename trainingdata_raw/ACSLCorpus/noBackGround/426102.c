#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20) && (1 <= (a) <= 20) && (1 <= (b) <= 20);
    requires ((a) < (b));
    ensures \result == true <==> (((b) - (a)) * ((n) - 1)) >= m;
*/
bool func(int n, int m, int a, int b)
{
    int ans;
    
    //@ assert 1 <= b - a <= 19;
    //@ assert 0 <= n - 1 <= 19;
    
    ans = (b - a) * (n - 1);
    
    //@ assert 0 <= ans <= 361;
    
    if (ans >= m) {
        //@ assert ((ans) >= (m));
        return true;
    } else {
        //@ assert !((ans) >= (m));
        return false;
    }
}
