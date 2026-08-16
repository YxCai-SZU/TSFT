#include <stdint.h>

/*@ requires 0 <= A <= 100 && 0 <= P <= 100;
    ensures \result >= 0;
    ensures \result == (A * 3 + P) / 2;
*/
int32_t func(uint32_t A, uint32_t P)
{
    uint32_t ans;
    int32_t result;
    uint32_t count;
    uint32_t temp_ans;

    ans = A * 3 + P;
    result = 0;
    count = 0;
    temp_ans = ans;

    /*@ loop invariant 0 <= temp_ans <= A * 3 + P;
        loop invariant 0 <= count <= (A * 3 + P) / 2;
        loop invariant temp_ans == ans - 2 * count;
        loop invariant 0 <= A <= 100;
        loop invariant 0 <= P <= 100;
        loop invariant ans == A * 3 + P;
        loop assigns temp_ans, count;
        loop variant temp_ans;
    */
    while (temp_ans >= 2)
    {
        temp_ans -= 2;
        count += 1;
    }

    result = (int32_t)count;

    //@ assert 0 <= A * 3 + P <= 100 * 3 + 100;

    return result;
}
