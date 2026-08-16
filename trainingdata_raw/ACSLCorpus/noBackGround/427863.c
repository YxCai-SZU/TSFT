#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a + c || \result == b + c || \result == b + d || \result == a + d;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int min_sum1;
    int min_sum2;
    int result;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);

    // Find the minimum value between a and b
    //@ assert a >= 1 && b >= 1;
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    //@ assert min_ab == (((a) < (b)) ? (a) : (b));

    // Find the minimum value between c and d
    //@ assert c >= 1 && d >= 1;
    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    //@ assert min_cd == (((c) < (d)) ? (c) : (d));

    // Find the minimum value between a + c and b + d
    //@ assert a + c >= 2 && b + d >= 2;
    if (a + c < b + d) {
        min_sum1 = a + c;
    } else {
        min_sum1 = b + d;
    }
    //@ assert min_sum1 == (((a + c) < (b + d)) ? (a + c) : (b + d));

    // Find the minimum value between a + d and b + c
    //@ assert a + d >= 2 && b + c >= 2;
    if (a + d < b + c) {
        min_sum2 = a + d;
    } else {
        min_sum2 = b + c;
    }
    //@ assert min_sum2 == (((a + d) < (b + c)) ? (a + d) : (b + c));

    // Find the minimum value between min_sum1 and min_sum2
    //@ assert min_sum1 >= 2 && min_sum2 >= 2;
    if (min_sum1 < min_sum2) {
        result = min_sum1;
    } else {
        result = min_sum2;
    }
    //@ assert result == (((min_sum1) < (min_sum2)) ? (min_sum1) : (min_sum2));
    //@ assert result == ((((((((a) + (c)) < ((b) + (d))) ? ((a) + (c)) : ((b) + (d)))) < (((((a) + (d)) < ((b) + (c))) ? ((a) + (d)) : ((b) + (c))))) ? (((((a) + (c)) < ((b) + (d))) ? ((a) + (c)) : ((b) + (d)))) : (((((a) + (d)) < ((b) + (c))) ? ((a) + (d)) : ((b) + (c))))));

    // Final verification property
    //@ assert result == a + c || result == b + c || result == b + d || result == a + d;

    return result;
}
