#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t half_sum;
    uint32_t result;

    sum = a + b;
    //@ assert sum == a + b;

    half_sum = sum / 2;
    //@ assert half_sum == sum / 2;

    if (sum % 2 == 0)
    {
        result = half_sum;
        //@ assert result == half_sum;
    }
    else
    {
        result = half_sum + 1;
        //@ assert result == half_sum + 1;
    }

    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}

int main(void)
{
    return 0;
}
