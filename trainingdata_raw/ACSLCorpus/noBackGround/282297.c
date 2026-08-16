#include <stdint.h>

/*@
    requires (0 <= (input) <= 1000000000);
    ensures \result >= 1 && \result <= 50;
    assigns \nothing;
*/
int32_t func(uint64_t input)
{
    uint64_t x = 1;
    int32_t count = 0;
    
    /*@
        loop invariant (0 <= (count) <= 50);
        loop invariant (1 <= (x) <= 1000000000);
        loop invariant (0 <= (input) <= 1000000000);
        loop assigns x, count;
        loop variant 50 - count;
    */
    while (count < 50)
    {
        //@ assert (1 <= (x) <= 1000000000);
        x *= 2;
        if (x > input)
        {
            //@ assert (0 <= (count + 1) <= 50);
            return count + 1;
        }
        count += 1;
        //@ assert (0 <= (count) <= 50);
    }
    //@ assert (0 <= (50) <= 50);
    return 50;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
