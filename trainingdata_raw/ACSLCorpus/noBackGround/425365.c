#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == true <==> (((a) < (c) && (b) > (c)) || ((a) > (c) && (b) < (c)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    //@ assert (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    
    if ((a < c && b > c) || (a > c && b < c)) {
        result = true;
    } else {
        //@ assert !(a < c && b > c) && !(a > c && b < c);
        result = false;
    }
    
    //@ assert result == true <==> (((a) < (c) && (b) > (c)) || ((a) > (c) && (b) < (c)));
    return result;
}
