#include <stdbool.h>

/*@
    requires (1 <= (A) <= 20 && 1 <= (B) <= 20);
    ensures \result >= 0;
    ensures \result == A - 2 * B || \result == 0;
    assigns \nothing;
*/
int func(int A, int B)
{
    int result;
    
    //@ assert (1 <= (A) <= 20 && 1 <= (B) <= 20);
    
    if (A <= B * 2) {
        result = 0;
    } else {
        //@ assert A > B * 2;
        //@ assert A - 2 * B >= 0;
        result = A - 2 * B;
    }
    
    //@ assert result >= 0;
    //@ assert result == A - 2 * B || result == 0;
    
    return result;
}
