#include <stdint.h>

/*@
    requires (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
    ensures \result >= 0 && \result <= (((A) * 3 + (P)) / 2);
*/
int32_t func(uint32_t A, uint32_t P)
{
    int32_t K;
    int32_t ret;
    int32_t temp;
    int32_t count;

    //@ assert (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
    K = (int32_t)(A * 3 + P);
    ret = 0;
    temp = K;
    count = 0;

    /*@
        loop invariant 0 <= temp && temp <= K;
        loop invariant 0 <= count && count <= K/2;
        loop invariant temp == K - 2 * count;
        loop assigns temp, count;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
        //@ assert temp == K - 2 * count;
    }

    ret = count;
    //@ assert ret >= 0;
    //@ assert ret <= (((A) * 3 + (P)) / 2);
    return ret;
}
