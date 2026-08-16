#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000);
    ensures \result == (((a) * (b)) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at scope top
    unsigned long long product;
    bool is_even;
    unsigned long long temp;
    
    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert ((a) * (b)) <= 100000000;
    
    product = a * b;
    is_even = false;
    temp = product;
    
    /*@
        loop invariant 0 <= temp <= ((a) * (b));
        loop invariant temp % 2 == ((a) * (b)) % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }
    
    if (temp == 0)
    {
        is_even = true;
    }
    
    //@ assert is_even == (((a) * (b)) % 2 == 0);
    return is_even;
}

int main(void)
{
    return 0;
}
