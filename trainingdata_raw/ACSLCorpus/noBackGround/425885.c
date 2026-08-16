#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == true <==> ((a) < (b) && (c) < (d) && (c) > (b) && (a) < (d));
*/
bool func(int a, int b, int c, int d)
{
    bool result;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    if (a >= b || c >= d) {
        //@ assert !((a) < (b) && (c) < (d) && (c) > (b) && (a) < (d));
        return false;
    }
    
    if (c <= b || a >= d) {
        //@ assert !((a) < (b) && (c) < (d) && (c) > (b) && (a) < (d));
        return false;
    }
    
    //@ assert a < b && c < d && c > b && a < d;
    //@ assert ((a) < (b) && (c) < (d) && (c) > (b) && (a) < (d));
    return true;
}
