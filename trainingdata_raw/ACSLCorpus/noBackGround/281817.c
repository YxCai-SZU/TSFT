#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000 && 0 <= (a) <= 360);
    ensures \result == (a >= (180 * ((n) - 1) / ((n) + 1)));
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    unsigned int n1;
    unsigned int numerator;
    unsigned int denominator;
    unsigned int x;

    // Variable declarations at top
    n1 = n + 1;
    
    //@ assert 180 * (n - 1) <= 180 * 9999;
    
    //@ assert 180 * (n - 1) / (n + 1) <= 180 * 9999 / 2;
    
    numerator = 180 * (n - 1);
    denominator = n1;
    x = numerator / denominator;
    
    return a >= x;
}
