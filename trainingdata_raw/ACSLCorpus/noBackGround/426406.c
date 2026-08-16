#include <stdbool.h>

/*@
    requires (0 <= (a) < 10) && (0 <= (b) < 10);
    ensures \result == (((a) * (a) + (b) * (b)) > 20);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int a_sq;
    unsigned int b_sq;
    unsigned int sum;

    //@ assert 0 <= a < 10 && 0 <= b < 10;

    a_sq = a * a;
    b_sq = b * b;
    sum = a_sq + b_sq;

    //@ assert sum == ((a) * (a) + (b) * (b));
    //@ assert 0 <= sum <= 200;

    result = (sum > 20);
    return result;
}
