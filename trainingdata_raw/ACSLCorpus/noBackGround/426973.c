#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures ((\result) == ((((a)) * ((a))) == (a) || (((a)) * ((b))) == (a) || (((b)) * ((b))) == (b) || (((a)) * ((b))) == (b)));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    unsigned long long a_square;
    unsigned long long a_times_b;
    unsigned long long b_square;
    bool result;

    //@ assert a * a <= 10000;
    a_square = a * a;

    //@ assert a * b <= 10000;
    a_times_b = a * b;

    //@ assert b * b <= 10000;
    b_square = b * b;

    result = (a_square == a) || (a_times_b == a) || (b_square == b) || (a_times_b == b);
    //@ assert ((result) == ((((a)) * ((a))) == (a) || (((a)) * ((b))) == (a) || (((b)) * ((b))) == (b) || (((a)) * ((b))) == (b)));
    return result;
}
