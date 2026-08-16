#include <limits.h>

/*@
    predicate is_in_range(integer v) = -100 <= v <= 100;
    logic integer product(integer x, integer y) = x * y;
    logic integer max_of_two(integer x, integer y) = (x > y) ? x : y;
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d);
    ensures \result == product(a,c) || \result == product(a,d) || 
            \result == product(b,c) || \result == product(b,d) ||
            \result == product(c,a) || \result == product(c,b) ||
            \result == product(d,a) || \result == product(d,b);
    ensures \result >= product(a,c) && \result >= product(a,d) &&
            \result >= product(b,c) && \result >= product(b,d) &&
            \result >= product(c,a) && \result >= product(c,b) &&
            \result >= product(d,a) && \result >= product(d,b);
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int max3;
    int max4;
    int max5;
    int max6;
    int result;

    //@ assert -10000 <= a * c <= 10000;
    //@ assert -10000 <= a * d <= 10000;
    //@ assert -10000 <= b * c <= 10000;
    //@ assert -10000 <= b * d <= 10000;

    if (a * c > a * d) {
        max1 = a * c;
    } else {
        max1 = a * d;
    }

    if (b * c > b * d) {
        max2 = b * c;
    } else {
        max2 = b * d;
    }

    if (c * a > c * b) {
        max3 = c * a;
    } else {
        max3 = c * b;
    }

    if (d * a > d * b) {
        max4 = d * a;
    } else {
        max4 = d * b;
    }

    if (max1 > max2) {
        max5 = max1;
    } else {
        max5 = max2;
    }

    if (max3 > max4) {
        max6 = max3;
    } else {
        max6 = max4;
    }

    //@ assert max5 >= a * c;
    //@ assert max5 >= a * d;
    //@ assert max5 >= b * c;
    //@ assert max5 >= b * d;
    //@ assert max6 >= c * a;
    //@ assert max6 >= c * b;
    //@ assert max6 >= d * a;
    //@ assert max6 >= d * b;

    if (max5 > max6) {
        result = max5;
    } else {
        result = max6;
    }

    return result;
}
