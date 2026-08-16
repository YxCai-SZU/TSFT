#include <stdbool.h>

/*@
    logic integer abs_diff(integer x, integer y) = (x > y) ? (x - y) : (y - x);
    
    lemma diff1_def: \forall integer a, b, diff1;
        diff1 == abs_diff(a, b) ==> diff1 == ((a > b) ? (a - b) : (b - a));
    lemma diff2_def: \forall integer b, c, diff2;
        diff2 == abs_diff(b, c) ==> diff2 == ((b > c) ? (b - c) : (c - b));
    lemma diff3_def: \forall integer c, d, diff3;
        diff3 == abs_diff(c, d) ==> diff3 == ((c > d) ? (c - d) : (d - c));
    lemma diff4_def: \forall integer d, a, diff4;
        diff4 == abs_diff(d, a) ==> diff4 == ((d > a) ? (d - a) : (a - d));
    lemma diff5_def: \forall integer a, c, diff5;
        diff5 == abs_diff(a, c) ==> diff5 == ((a > c) ? (a - c) : (c - a));
    lemma diff6_def: \forall integer b, d, diff6;
        diff6 == abs_diff(b, d) ==> diff6 == ((b > d) ? (b - d) : (d - b));
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == (
        abs_diff(a, b) <= d ||
        abs_diff(b, c) <= d ||
        abs_diff(c, d) <= d ||
        abs_diff(d, a) <= d ||
        abs_diff(a, c) <= d ||
        abs_diff(b, d) <= d
    );
*/
bool func(int a, int b, int c, int d)
{
    int diff1;
    int diff2;
    int diff3;
    int diff4;
    int diff5;
    int diff6;
    bool result;
    
    diff1 = (a > b) ? (a - b) : (b - a);
    diff2 = (b > c) ? (b - c) : (c - b);
    diff3 = (c > d) ? (c - d) : (d - c);
    diff4 = (d > a) ? (d - a) : (a - d);
    diff5 = (a > c) ? (a - c) : (c - a);
    diff6 = (b > d) ? (b - d) : (d - b);
    
    //@ assert diff1 == abs_diff(a, b);
    //@ assert diff2 == abs_diff(b, c);
    //@ assert diff3 == abs_diff(c, d);
    //@ assert diff4 == abs_diff(d, a);
    //@ assert diff5 == abs_diff(a, c);
    //@ assert diff6 == abs_diff(b, d);
    
    result = (diff1 <= d) || (diff2 <= d) || (diff3 <= d) || 
             (diff4 <= d) || (diff5 <= d) || (diff6 <= d);
    
    return result;
}
