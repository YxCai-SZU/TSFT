#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == ((((x) >= 2000) ? 1 : (((x) % 200 == 0) ? 1 : 0)) == 1);
    assigns \nothing;
*/
bool func(int x)
{
    // Variable declarations at top of scope
    bool result;
    int rem;

    if (x >= 2000) {
        result = true;
    } else {
        rem = x;
        
        /*@
            loop invariant 0 <= rem <= x;
            loop invariant rem % 200 == x % 200;
            loop assigns rem;
            loop variant rem;
        */
        while (rem >= 200) {
            rem -= 200;
        }
        
        //@ assert rem == x % 200;
        result = (rem == 0);
    }
    
    //@ assert result == ((((x) >= 2000) ? 1 : (((x) % 200 == 0) ? 1 : 0)) == 1);
    return result;
}
