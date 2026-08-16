#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 1000 &&
        1 <= (B) && (B) <= 1000 &&
        (A) + (B) <= (X) && (X) <= 10000);
    ensures 0 <= \result && \result <= B;
    ensures \result == X - A || \result == B;
    assigns \nothing;
*/
int64_t func(int64_t X, int64_t A, int64_t B)
{
    int64_t result;
    //@ assert (1 <= (A) && (A) <= 1000 &&         1 <= (B) && (B) <= 1000 &&         (A) + (B) <= (X) && (X) <= 10000);
    
    if (X - A > B) {
        result = B;
        //@ assert result == B;
    } else {
        result = X - A;
        //@ assert result == X - A;
    }
    
    //@ assert result == (((X) - (A) > (B)) ? (B) : ((X) - (A)));
    return result;
}
