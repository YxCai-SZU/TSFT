#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == true <==> ((a) * (b)) > ((c) * (d));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b,
          unsigned long long c, unsigned long long d)
{
    //@ assert a > 0 && b > 0 && c > 0 && d > 0;
    //@ assert a <= 10000 && b <= 10000 && c <= 10000 && d <= 10000;
    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;
    
    return a * b > c * d;
}
