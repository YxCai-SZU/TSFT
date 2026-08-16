#include <stdint.h>

/*@
    requires (1 <= (A) <= 20 && 1 <= (B) <= 20);
    ensures ((1 <= (A) <= 9 && 1 <= (B) <= 9) ==> \result == ((A) * (B))) &&
            ((((A) <= 9 && (B) >= 10) || ((A) >= 10 && (B) <= 9) || ((A) >= 10 && (B) >= 10)) ==> \result == -1);
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    // Variable declarations at scope top
    int64_t result;

    //@ assert (1 <= (A) <= 20 && 1 <= (B) <= 20);
    
    if (1 <= A && A <= 9 && 1 <= B && B <= 9) {
        //@ assert (1 <= (A) <= 9 && 1 <= (B) <= 9);
        //@ assert ((A) * (B)) <= 81;
        result = A * B;
    } else {
        //@ assert (((A) <= 9 && (B) >= 10) || ((A) >= 10 && (B) <= 9) || ((A) >= 10 && (B) >= 10));
        result = -1;
    }
    
    return result;
}
