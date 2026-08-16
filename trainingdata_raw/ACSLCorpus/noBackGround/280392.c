#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b)
{
    // Variable declarations at top of scope
    unsigned long product;
    bool is_odd = false;
    unsigned long temp;
    
    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    
    //@ assert 1 <= a * b && a * b <= 9;
    product = a * b;
    temp = product;
    
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop invariant temp <= a * b;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }
    
    if (temp == 1)
    {
        is_odd = true;
    }
    
    //@ assert is_odd == ((a * b) % 2 != 0);
    return is_odd;
}

int main()
{
    return 0;
}
