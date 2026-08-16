#include <stdint.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> A * B > C * D;
    ensures \result == 0 ==> A * B <= C * D;
*/
int32_t func(int32_t A, int32_t B, int32_t C, int32_t D)
{
    //@ assert A * B <= 10000 * 10000;
    //@ assert C * D <= 10000 * 10000;
    
    if (A * B > C * D) {
        //@ assert A * B > C * D;
        return 1;
    } else {
        //@ assert A * B <= C * D;
        return 0;
    }
}

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> A * B > C * D;
    ensures \result == 0 ==> A * B <= C * D;
*/
int32_t func2(int32_t A, int32_t B, int32_t C, int32_t D)
{
    //@ assert A * B <= 10000 * 10000;
    //@ assert C * D <= 10000 * 10000;
    
    if (A * B > C * D) {
        //@ assert A * B > C * D;
        return 1;
    } else {
        //@ assert A * B <= C * D;
        return 0;
    }
}

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> A * B > C * D;
    ensures \result == 0 ==> A * B <= C * D;
*/
int32_t func3(int32_t A, int32_t B, int32_t C, int32_t D)
{
    //@ assert A * B <= 10000 * 10000;
    //@ assert C * D <= 10000 * 10000;
    
    if (A * B > C * D) {
        //@ assert A * B > C * D;
        return 1;
    } else {
        //@ assert A * B <= C * D;
        return 0;
    }
}
