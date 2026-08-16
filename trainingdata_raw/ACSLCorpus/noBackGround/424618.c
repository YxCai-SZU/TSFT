#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result == ((((a)) * ((b))) / 2);
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t product;
    int32_t result;
    uint32_t count;
    uint32_t temp_product;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    product = a * b;
    //@ assert 1 <= product <= 10000;

    result = 0;
    count = 0;
    temp_product = product;

    /*@
        loop invariant 0 <= temp_product <= product;
        loop invariant 0 <= count <= product / 2;
        loop invariant temp_product == product - 2 * count;
        loop assigns temp_product, count;
        loop variant temp_product;
    */
    while (temp_product >= 2)
    {
        //@ assert temp_product >= 2;
        temp_product -= 2;
        count += 1;
    }

    if (temp_product == 1)
    {
        //@ assert product % 2 == 1;
        return -1;
    }

    //@ assert temp_product == 0;
    //@ assert count == product / 2;
    result = (int32_t)count;
    //@ assert result == ((((a)) * ((b))) / 2);
    return result;
}
