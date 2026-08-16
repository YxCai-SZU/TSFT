#include <stdbool.h>

/*@
    predicate has_seven(integer n) =
        (n / 100) == 7 ||
        ((n / 10) % 10) == 7 ||
        (n % 10) == 7;
*/

/*@
    requires 100 <= N <= 999;
    ensures \result == 1 <==> has_seven(N);
*/
bool func(unsigned int N)
{
    unsigned int n1;
    unsigned int n2;
    unsigned int n3;
    unsigned int count;

    n1 = N / 100;
    n2 = (N / 10) % 10;
    n3 = N % 10;
    count = 0;

    if (n1 == 7) {
        count += 1;
    }
    if (n2 == 7) {
        count += 1;
    }
    if (n3 == 7) {
        count += 1;
    }

    //@ assert count > 0 ==> (n1 == 7 || n2 == 7 || n3 == 7);

    return count > 0;
}
