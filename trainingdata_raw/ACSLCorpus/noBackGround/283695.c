#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((((a)) * ((b))) + 1) / 2);
    assigns \nothing;
 */
int32_t func(uint64_t a, uint64_t b)
{
    // Variable declarations at scope top
    uint64_t product;
    int32_t result;
    uint64_t remainder;
    uint64_t two;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    product = a * b;
    //@ assert product == ((a) * (b));
    
    //@ assert product <= 10000;
    
    result = 0;
    remainder = product + 1;
    two = 2;

    /*@
        loop invariant 0 <= result <= (((((a)) * ((b))) + 1) / 2);
        loop invariant remainder == product + 1 - 2 * result;
        loop invariant remainder >= 0;
        loop assigns result, remainder;
        loop variant remainder;
     */
    while (remainder >= two)
    {
        //@ assert remainder >= 2;
        remainder -= two;
        result += 1;
    }

    //@ assert result == (((((a)) * ((b))) + 1) / 2);
    return result;
}

int main()
{
    return 0;
}
