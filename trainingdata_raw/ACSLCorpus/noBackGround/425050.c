#include <stdbool.h>

/*@
    requires 1 <= a <= 500;
    requires 1 <= b <= 500;
    requires 1 <= c <= 1000;
    ensures \result == true <==> ((c) - (a) >= 0 && (c) - (a) <= (b));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int diff;
    
    //@ assert c - a >= -999 && c - a <= 999;
    
    diff = c - a;
    
    if (diff >= 0 && diff <= b) {
        return true;
    } else {
        return false;
    }
}
