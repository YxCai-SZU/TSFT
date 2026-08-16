#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ((a * b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top
    unsigned int c;
    bool is_even;
    unsigned int temp;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    //@ assert (1 <= (a) <= 10000 && 1 <= (b) <= 10000 && (a) * (b) <= 10000 * 10000);
    //@ assert a * b <= 10000 * 10000;
    
    c = a * b;
    
    temp = c;
    /*@
        loop invariant temp <= c;
        loop invariant temp % 2 == c % 2;
        loop invariant temp >= 0;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }
    
    is_even = (temp == 0);
    
    //@ assert is_even == ((a * b) % 2 == 0);
    
    return is_even;
}
