#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && 
             (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == true <==> ((b) >= (c) || ((a) >= (c) && (a) <= (d)) || (b) >= (d));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    bool result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    
    if (!(b >= c || (a >= c && a <= d) || (b >= d))) {
        //@ assert !((b) >= (c) || ((a) >= (c) && (a) <= (d)) || (b) >= (d));
        result = false;
    } else {
        //@ assert ((b) >= (c) || ((a) >= (c) && (a) <= (d)) || (b) >= (d));
        result = true;
    }
    
    return result;
}
