#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
    ensures \result == (a < c && c < b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool is_valid = false;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
    
    if (a < c && c < b) {
        is_valid = true;
    }
    
    //@ assert is_valid == (a < c && c < b);
    
    return is_valid;
}
