#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (h) && (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int h)
{
    // Variable declarations at scope top
    unsigned int sum;
    unsigned int product;
    unsigned int result = 0;
    unsigned int count = 0;
    unsigned int temp;

    // Precondition verification
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= h && h <= 100;
    //@ assert h % 2 == 0;

    sum = a + b;
    
    //@ assert 2 <= sum && sum <= 200;
    
    product = sum * h;
    
    //@ assert 2 <= product && product <= 20000;
    
    temp = product;

    /*@
        loop invariant 0 <= count && count <= product / 2;
        loop invariant temp == product - 2 * count;
        loop invariant 0 <= result && result <= product / 2;
        loop invariant count == result;
        loop assigns temp, result, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
        result += 1;
        count += 1;
    }

    //@ assert result == product / 2;
    //@ assert result == (((a) + (b)) * (h) / 2);
    
    return result;
}
