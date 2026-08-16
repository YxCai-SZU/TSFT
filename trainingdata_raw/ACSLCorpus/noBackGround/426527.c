#include <stdint.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && 
             (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B)) && \result >= ((C) * (D));
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C, uint32_t D) {
    uint32_t S1;
    uint32_t S2;
    uint32_t result;

    //@ assert (1 <= (A) <= 10000) && (1 <= (B) <= 10000);
    //@ assert ((A) * (B)) <= 100000000;
    S1 = A * B;

    //@ assert (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    //@ assert ((C) * (D)) <= 100000000;
    S2 = C * D;

    //@ assert S1 == ((A) * (B));
    //@ assert S2 == ((C) * (D));

    if (S1 > S2) {
        result = S1;
        //@ assert result == ((A) * (B));
        //@ assert result >= ((C) * (D));
    } else {
        result = S2;
        //@ assert result == ((C) * (D));
        //@ assert result >= ((A) * (B));
    }

    //@ assert result >= ((A) * (B)) && result >= ((C) * (D));
    //@ assert result == ((A) * (B)) || result == ((C) * (D));
    return result;
}
