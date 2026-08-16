#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == true <==> (((a) > (b) ? (a) - (b) : (b) - (a)) <= (d) ||
       ((b) > (c) ? (b) - (c) : (c) - (b)) <= (d) ||
       ((c) > (a) ? (c) - (a) : (a) - (c)) <= (d));
*/
bool can_communicate(int a, int b, int c, int d) {
    int diff1;
    int diff2;
    int diff3;
    bool result;

    diff1 = (a > b) ? (a - b) : (b - a);
    diff2 = (b > c) ? (b - c) : (c - b);
    diff3 = (c > a) ? (c - a) : (a - c);

    //@ assert diff1 == (a > b ? a - b : b - a);
    //@ assert diff2 == (b > c ? b - c : c - b);
    //@ assert diff3 == (c > a ? c - a : a - c);

    result = (diff1 <= d) || (diff2 <= d) || (diff3 <= d);
    return result;
}
