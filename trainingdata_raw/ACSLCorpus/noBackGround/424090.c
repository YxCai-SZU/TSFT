#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000);
    ensures \result == ((((a) * (b)) % 2) == 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    unsigned long long product;
    bool is_even;
    unsigned long long remainder;
    
    //@ assert a <= 10000 && b <= 10000;
    //@ assert a * b <= 10000 * 10000;
    
    product = a * b;
    is_even = true;
    remainder = product;
    
    /*@
        loop invariant 1 <= a && a <= 10000;
        loop invariant 1 <= b && b <= 10000;
        loop invariant remainder <= product;
        loop invariant remainder % 2 == product % 2;
        loop invariant (product % 2 == 0) ==> is_even;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder > 1)
    {
        remainder -= 2;
    }
    
    if (remainder == 1)
    {
        is_even = false;
    }
    
    //@ assert is_even == ((a * b) % 2 == 0);
    return is_even;
}

int main(void)
{
    return 0;
}
