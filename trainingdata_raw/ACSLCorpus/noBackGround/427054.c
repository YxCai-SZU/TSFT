#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || (n / 10) % 10 == 9);
*/
bool func(int n)
{
    int n_abs;
    int div;
    int temp;
    int reminder;
    bool result;

    n_abs = (n < 0) ? -n : n;
    div = 0;
    temp = n_abs;

    /*@
        loop invariant 10 <= n_abs <= 99;
        loop invariant 0 <= temp <= n_abs;
        loop invariant div <= n_abs / 10;
        loop invariant temp == n_abs - 10 * div;
        loop assigns temp, div;
    */
    while (temp >= 10)
    {
        //@ assert temp >= 10;
        temp -= 10;
        div += 1;
    }

    reminder = temp;
    result = (div == 9 || reminder == 9);
    //@ assert result == (n % 10 == 9 || (n / 10) % 10 == 9);
    return result;
}
