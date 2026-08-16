#include <limits.h>

/*@
    requires (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == ((c) - ((a) - (b))) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int result;
    int ret;

    //@ assert (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    
    result = c - (a - b);
    
    //@ assert ((c) - ((a) - (b))) == result;
    
    if (result < 0) {
        ret = 0;
    } else {
        ret = result;
    }
    
    //@ assert ((((c)) - (((a)) - ((b)))) < 0 ? 0 : (((c)) - (((a)) - ((b))))) == ret;
    //@ assert ret >= 0;
    //@ assert ret <= c;
    //@ assert ret == result || ret == 0;
    
    return ret;
}
