#include <limits.h>

/*@
    requires ((a) >= 0 && (a) <= 100) && ((b) >= 0 && (b) <= 100) && ((c) >= 0 && (c) <= 100) && ((d) >= 0 && (d) <= 100);
    ensures \result == a * b * c || \result == a * c * d || \result == a * d * b || \result == b * c * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at the top
    int max1;
    int max2;
    int result;

    //@ assert ((a * b) >= 0 && (a * b) <= 10000);
    //@ assert ((a * c) >= 0 && (a * c) <= 10000);
    //@ assert ((a * d) >= 0 && (a * d) <= 10000);
    //@ assert ((b * c) >= 0 && (b * c) <= 10000);
    //@ assert ((b * d) >= 0 && (b * d) <= 10000);
    //@ assert ((c * d) >= 0 && (c * d) <= 10000);

    //@ assert ((a * b * c) >= 0 && (a * b * c) <= 1000000);
    //@ assert ((a * c * d) >= 0 && (a * c * d) <= 1000000);
    //@ assert ((a * d * b) >= 0 && (a * d * b) <= 1000000);
    //@ assert ((b * c * d) >= 0 && (b * c * d) <= 1000000);

    max1 = (a * b * c > a * c * d) ? a * b * c : a * c * d;
    max2 = (a * d * b > b * c * d) ? a * d * b : b * c * d;
    result = (max1 > max2) ? max1 : max2;

    //@ assert result == a * b * c || result == a * c * d || result == a * d * b || result == b * c * d;
    return result;
}
