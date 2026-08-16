#include <stdbool.h>

/*@
    requires (\valid((a)) &&
        (a)[0] >= 1 && (a)[0] <= 100 &&
        (a)[1] >= 1 && (a)[1] <= 100 &&
        (a)[2] >= 1 && (a)[2] <= 100);
    ensures \result == (a[0] + a[1] == a[2] ||
                       a[1] + a[2] == a[0] ||
                       a[0] + a[2] == a[1]);
    assigns \nothing;
*/
bool check_triplets(int *a)
{
    int sum1;
    int sum2;
    int sum3;
    bool result;

    //@ assert ((a[0]) + (a[1])) == a[0] + a[1];
    sum1 = a[0] + a[1];

    //@ assert ((a[1]) + (a[2])) == a[1] + a[2];
    sum2 = a[1] + a[2];

    //@ assert ((a[0]) + (a[2])) == a[0] + a[2];
    sum3 = a[0] + a[2];

    result = (sum1 == a[2]) || (sum2 == a[0]) || (sum3 == a[1]);
    return result;
}
