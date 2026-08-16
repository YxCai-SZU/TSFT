#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((l) * (l) * (l)) / 27;
    assigns \nothing;
*/
int32_t func(uint32_t l)
{
    // Variable declarations
    uint32_t l_3;
    int32_t result;
    uint32_t count;
    uint32_t temp;

    // Precondition check
    //@ assert (1 <= (l) <= 1000);

    // Calculate cube with overflow check
    //@ assert l * l <= 1000000;
    l_3 = l * l * l;
    //@ assert l_3 == ((l) * (l) * (l));
    
    result = 0;
    count = 0;
    temp = l_3;

    /*@
        loop invariant 0 <= count;
        loop invariant temp == l_3 - 27 * count;
        loop invariant temp >= 0;
        loop invariant count <= ((l) * (l) * (l)) / 27;
        loop invariant result == 0;
        loop assigns temp, count, result;
        loop variant temp;
    */
    while (temp >= 27)
    {
        //@ assert temp >= 27;
        temp -= 27;
        count += 1;
        //@ assert temp == l_3 - 27 * count;
    }

    result = (int32_t)count;
    //@ assert result == ((l) * (l) * (l)) / 27;
    return result;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
