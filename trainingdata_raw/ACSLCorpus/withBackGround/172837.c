#include <stdint.h>

/*@
    predicate is_valid_N(integer N) = 1 <= N && N <= 100000;

    logic integer mod_condition(integer N) = (N * 21) % 100;

    lemma mod_range: \forall integer N; is_valid_N(N) ==> 0 <= mod_condition(N) && mod_condition(N) < 100;
*/

/*@
    requires is_valid_N(N);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> mod_condition(N) < 105;
    ensures \result == 0 ==> mod_condition(N) >= 105;
*/
int32_t func(uint32_t N)
{
    uint32_t x;
    int32_t remainder;
    int32_t temp;

    x = N * 21;
    remainder = (int32_t)x;

    /*@
        loop invariant 1 <= N && N <= 100000;
        loop invariant remainder <= (int32_t)x;
        loop invariant remainder >= 0;
        loop invariant remainder == (int32_t)x - 100 * (((int32_t)x - remainder) / 100);
        loop assigns remainder;
    */
    while (remainder >= 100)
    {
        //@ assert remainder >= 100;
        remainder -= 100;
    }

    /*@
        loop invariant 1 <= N && N <= 100000;
        loop invariant remainder < 100;
        loop invariant remainder == (int32_t)x - 100 * (((int32_t)x - remainder) / 100);
        loop assigns remainder;
    */
    while (remainder < 0)
    {
        //@ assert remainder < 0;
        remainder += 100;
    }

    //@ assert remainder == mod_condition(N);
    
    if (remainder < 105)
    {
        //@ assert remainder < 105;
        return 1;
    }
    else
    {
        //@ assert remainder >= 105;
        return 0;
    }
}
