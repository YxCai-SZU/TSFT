#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result <= b * c;
    ensures \result == b * c || \result == a;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    
    //@ assert (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    //@ assert 1 <= b * c && b * c <= 10000;
    
    if (b * c < a) {
        ans = b * c;
        //@ assert ans == b * c;
    } else {
        ans = a;
        //@ assert ans == a;
    }
    
    //@ assert ans <= b * c;
    //@ assert ans == b * c || ans == a;
    
    return ans;
}
