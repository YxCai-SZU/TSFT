#include <stdbool.h>

/*@
    requires (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000) && (1 <= (d) <= 5000);
    ensures \result == ((c <= b && b <= d && d <= a + c) || (c <= a && a <= d && d <= b + c));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert (1 <= (a) <= 5000);
    //@ assert (1 <= (b) <= 5000);
    //@ assert (1 <= (c) <= 5000);
    //@ assert (1 <= (d) <= 5000);
    
    //@ assert b + c <= 10000;
    
    if ((c <= b && b <= d && d <= a + c) || (c <= a && a <= d && d <= b + c)) {
        //@ assert (c <= b && b <= d && d <= a + c) || (c <= a && a <= d && d <= b + c);
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == ((c <= b && b <= d && d <= a + c) || (c <= a && a <= d && d <= b + c));
    return result;
}
