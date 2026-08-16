#include <stdbool.h>

/*@
    requires 1 <= n && n <= 100;
    ensures \result == ((n * n * 3) / 5 <= 3 * n);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    // Variable declarations at scope top
    bool result;
    unsigned int square;
    unsigned int triple_square;
    unsigned int div_result;
    unsigned int triple_n;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert n * n <= 10000;
    square = n * n;

    //@ assert square * 3 <= 30000;
    triple_square = square * 3;

    //@ assert triple_square / 5 <= 6000;
    div_result = triple_square / 5;

    //@ assert 0 <= div_result && div_result <= 6000;
    triple_n = 3 * n;

    //@ assert 0 <= triple_n && triple_n <= 300;
    result = (div_result <= triple_n);

    return result;
}
