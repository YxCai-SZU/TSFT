#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures ((a) == (b) && (a) != (c)) ==> \result == c;
    ensures ((a) == (c) && (a) != (b)) ==> \result == b;
    ensures ((b) == (c) && (a) != (b)) ==> \result == a;
*/
long func(long a, long b, long c) {
    long result;
    long first;
    long second;
    long third;

    if (a == b && a == c) {
        result = 0;
        return result;
    } else if (a == b) {
        result = c;
        return result;
    } else if (a == c) {
        result = b;
        return result;
    } else if (b == c) {
        result = a;
        return result;
    }

    if (a >= b && a >= c) {
        first = a;
        if (b >= c) {
            second = b;
            third = c;
        } else {
            second = c;
            third = b;
        }
    } else if (b >= a && b >= c) {
        first = b;
        if (a >= c) {
            second = a;
            third = c;
        } else {
            second = c;
            third = a;
        }
    } else {
        first = c;
        if (a >= b) {
            second = a;
            third = b;
        } else {
            second = b;
            third = a;
        }
    }

    //@ assert ((a) == (b) && (a) != (c)) ==> third == c;
    //@ assert ((a) == (c) && (a) != (b)) ==> third == b;
    //@ assert ((b) == (c) && (a) != (b)) ==> third == a;

    result = third;
    return result;
}
