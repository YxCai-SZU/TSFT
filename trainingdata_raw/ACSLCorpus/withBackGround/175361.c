#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 100; */

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == true <==> a + b + c >= 22;
*/
bool func(int a, int b, int c)
{
    bool result;
    int sum;
    bool bust;

    result = false;
    sum = a + b + c;
    bust = false;

    // Implementing the bust condition without using modulo
    if (sum > 21) {
        bust = true;
    } else {
        bust = false;
    }

    if (bust) {
        result = true;
    } else {
        result = false;
    }

    //@ assert bust == true <==> sum >= 22;
    //@ assert result == true <==> bust;
    //@ assert result == true <==> sum >= 22;

    return result;
}
