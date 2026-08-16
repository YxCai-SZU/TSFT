#include <stdbool.h>

/*@
    requires (1 <= (n) <= 16 && 1 <= (m) <= 16 && (n) + (m) <= 16);
    ensures \result == true <==> ((1 <= (n) <= 8 && 1 <= (m) <= 8) ? 1 : 0) == 1;
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    bool result;

    //@ assert (1 <= (n) <= 16 && 1 <= (m) <= 16 && (n) + (m) <= 16);
    
    if (n <= 8 && m <= 8) {
        //@ assert ((1 <= (n) <= 8 && 1 <= (m) <= 8) ? 1 : 0) == 1;
        result = true;
    } else {
        //@ assert ((1 <= (n) <= 8 && 1 <= (m) <= 8) ? 1 : 0) == 0;
        result = false;
    }
    
    //@ assert result == true <==> ((1 <= (n) <= 8 && 1 <= (m) <= 8) ? 1 : 0) == 1;
    return result;
}
