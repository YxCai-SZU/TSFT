#include <limits.h>

/*@
    requires ((a) >= 1 && (a) <= 123) && ((b) >= 1 && (b) <= 123) && ((c) >= 1 && (c) <= 123) &&
             ((d) >= 1 && (d) <= 123) && ((e) >= 1 && (e) <= 123);
    ensures \result >= 0;
    ensures \result <= (((a) + (b) + (c) + (d) + (e)) + ((b) + (c) + (d)) + ((c) + (d)) + (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e)
{
    int result;
    int min_a;
    int min_b;
    int min_c;
    int min_d;

    result = 0;

    //@ assert ((a) >= 1 && (a) <= 123) && ((b) >= 1 && (b) <= 123);
    min_a = a < b ? a : b;
    result += min_a;

    //@ assert ((b) >= 1 && (b) <= 123) && ((c) >= 1 && (c) <= 123);
    min_b = b < c ? b : c;
    result += min_b;

    //@ assert ((c) >= 1 && (c) <= 123) && ((d) >= 1 && (d) <= 123);
    min_c = c < d ? c : d;
    result += min_c;

    //@ assert ((d) >= 1 && (d) <= 123) && ((e) >= 1 && (e) <= 123);
    min_d = d < e ? d : e;
    result += min_d;

    /*@ assert
        min_a == (a < b ? a : b) &&
        min_b == (b < c ? b : c) &&
        min_c == (c < d ? c : d) &&
        min_d == (d < e ? d : e);
    */
    //@ assert min_a <= a && min_a <= b;
    //@ assert min_b <= b && min_b <= c;
    //@ assert min_c <= c && min_c <= d;
    //@ assert min_d <= d && min_d <= e;
    //@ assert result == min_a + min_b + min_c + min_d;
    //@ assert result <= (((a) + (b) + (c) + (d) + (e)) + ((b) + (c) + (d)) + ((c) + (d)) + (d));

    return result;
}
