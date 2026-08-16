#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 100) && (1 <= (B) && (B) <= 100) && (1 <= (C) && (C) <= 100);
    ensures \result == (A < B && B < C);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (A) && (A) <= 100);
    //@ assert (1 <= (B) && (B) <= 100);
    //@ assert (1 <= (C) && (C) <= 100);
    
    result = (A < B) && (B < C);
    return result;
}
