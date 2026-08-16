#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100) && (0 <= (a) && (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int func(int n, int a) {
    // Variable declarations at top
    int result;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert n * n <= 10000;
    //@ assert a <= n * n;

    result = n * n - a;
    return result;
}

/*@
    requires ((side) >= 0 && (side) * (side) * (side) <= INT_MAX);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int volume_cube(int side) {
    // Variable declarations at top
    int ret;

    //@ assert ((side) * (side) <= INT_MAX);
    //@ assert side * side * side <= INT_MAX;

    ret = side * side * side;
    return ret;
}

/*@
    requires ((side) >= 0 && (side) * (side) <= INT_MAX);
    ensures \result == ((side) * (side));
    assigns \nothing;
*/
int area_square(int side) {
    // Variable declarations at top
    int ret;

    //@ assert side * side <= INT_MAX;

    ret = side * side;
    return ret;
}

/*@
    requires ((side) >= 0 && 4 * (side) <= INT_MAX);
    ensures \result == (4 * (side));
    assigns \nothing;
*/
int perimeter_square(int side) {
    // Variable declarations at top
    int ret;

    //@ assert 4 * side <= INT_MAX;

    ret = 4 * side;
    return ret;
}
