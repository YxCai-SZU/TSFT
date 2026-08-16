#include <stdbool.h>

/*@
    predicate has_seven(integer n) =
        n / 100 == 7 || (n / 10) % 10 == 7 || n % 10 == 7;
*/

/*@
    requires 100 <= n <= 999;
    ensures \result == 1 <==> has_seven(n);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned long n_100;
    unsigned long n_10;
    unsigned long n_1;
    unsigned long count;

    n_100 = n / 100;
    n_10 = (n / 10) % 10;
    n_1 = n % 10;

    count = 0;

    if (n_100 == 7) {
        count += 1;
    }
    if (n_10 == 7) {
        count += 1;
    }
    if (n_1 == 7) {
        count += 1;
    }

    //@ assert count > 0 <==> has_seven(n);

    return count > 0;
}
