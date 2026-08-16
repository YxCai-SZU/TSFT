#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result <==> ((a) < (b) && (b) < (c));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top
    bool result;

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    
    if (1 <= a && a <= 100 && 1 <= b && b <= 100 && 1 <= c && c <= 100) {
        if (a < b && b < c) {
            result = true;
        } else {
            result = false;
        }
    } else {
        //@ assert !((a) < (b) && (b) < (c));
        result = false;
    }
    
    return result;
}
