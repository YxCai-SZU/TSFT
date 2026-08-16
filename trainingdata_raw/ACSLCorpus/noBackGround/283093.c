#include <stdbool.h>

/*@
    requires (1 <= (a) <= 500) && (1 <= (b) <= 500) && (1 <= (c) <= 1000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int ab;
    int cc;
    bool ans;

    //@ assert (1 <= (a) <= 500);
    //@ assert (1 <= (b) <= 500);
    //@ assert (1 <= (c) <= 1000);
    //@ assert ((a) + (b) <= 1000);

    ab = a + b;
    cc = c;
    ans = (ab >= cc);
    
    return ans;
}
