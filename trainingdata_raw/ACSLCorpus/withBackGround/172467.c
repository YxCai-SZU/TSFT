#include <stdbool.h>

/*@ predicate in_range_i32(integer x) = -0x80000000 <= x <= 0x7FFFFFFF; */

/*@
    requires a <= b;
    requires in_range_i32(a);
    requires in_range_i32(b);
    requires in_range_i32(c);
    ensures \result == (a <= c && c <= b);
*/
bool func(int a, int b, int c)
{
    //@ assert a <= b;
    //@ assert in_range_i32(a);
    //@ assert in_range_i32(b);
    //@ assert in_range_i32(c);
    //@ assert a <= c && c <= b ==> (a <= c && c <= b);
    return a <= c && c <= b;
}
