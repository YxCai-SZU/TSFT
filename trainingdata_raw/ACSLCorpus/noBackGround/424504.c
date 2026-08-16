#include <stdbool.h>

/*@
  requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
  ensures \result == (A < B && B < C);
  assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool result;
    
    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert (1 <= (C) <= 100);
    
    if (A < B) {
        if (B < C) {
            result = true;
        } else {
            result = false;
        }
    } else {
        result = false;
    }
    
    //@ assert result == (A < B && B < C);
    return result;
}

