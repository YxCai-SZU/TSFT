#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 13 &&
        1 <= (b) && (b) <= 13 &&
        1 <= (c) && (c) <= 13);
    ensures \result == true <==> (a + b + c) < 22;
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    // Variable declarations at scope top
    unsigned long long sum;
    bool result;

    //@ assert 1 <= a && a <= 13;
    //@ assert 1 <= b && b <= 13;
    //@ assert 1 <= c && c <= 13;

    //@ assert a + b <= 26;
    //@ assert a + b + c <= 39;

    sum = a + b + c;

    if (sum >= 22) {
        result = false;
    } else {
        result = true;
    }

    //@ assert result == true <==> (a + b + c) < 22;
    return result;
}
