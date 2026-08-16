#include <stdbool.h>

/*@
    predicate is_seven_digit(integer n) =
        100 <= n && n <= 999 &&
        (n / 100 == 7 || (n / 10) % 10 == 7 || n % 10 == 7);
*/

/*@
    requires 100 <= n && n <= 999;
    ensures \result == (n / 100 == 7 || (n / 10) % 10 == 7 || n % 10 == 7);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int num;
    unsigned int a0;
    unsigned int a1;
    unsigned int a2;
    bool result;

    num = n;
    a0 = num / 100;
    a1 = (num / 10) % 10;
    a2 = num % 10;

    //@ assert a0 == num / 100;
    //@ assert a1 == (num / 10) % 10;
    //@ assert a2 == num % 10;

    result = (a0 == 7) || (a1 == 7) || (a2 == 7);
    return result;
}
