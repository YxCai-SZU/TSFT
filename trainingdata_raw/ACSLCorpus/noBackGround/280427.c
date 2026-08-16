#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        0 <= (d) && (d) <= 100);
    ensures \result == true <==> a * d <= b * c;
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b,
          unsigned long long c, unsigned long long d)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (d) && (d) <= 100 ==> (a) * (d) <= 10000);
    //@ assert (0 <= ((c)) && ((c)) <= 100 && 0 <= (c) && (c) <= 100 ==> ((c)) * (c) <= 10000);
    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (d) && (d) <= 100 ==> (a) * (d) <= 10000);
    //@ assert (0 <= ((c)) && ((c)) <= 100 && 0 <= (c) && (c) <= 100 ==> ((c)) * (c) <= 10000);

    result = (a * d <= b * c);
    return result;
}
