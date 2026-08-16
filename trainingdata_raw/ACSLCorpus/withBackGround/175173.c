#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 1000;

    logic integer max_of_two(integer x, integer y) = x > y ? x : y;

    lemma max_is_either:
        \forall integer a, b;
            is_valid_range(a) && is_valid_range(b) ==>
            max_of_two(a, b) == a || max_of_two(a, b) == b;

    lemma sum_bounds:
        \forall integer x, y;
            is_valid_range(x) && is_valid_range(y) ==> x + y <= 2000;
*/

/*@
    requires is_valid_range(a);
    requires is_valid_range(b);
    requires is_valid_range(c);
    requires is_valid_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int result;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    //@ assert is_valid_range(d);

    max1 = a > b ? a : b;
    max2 = c > d ? c : d;

    //@ assert max1 == a || max1 == b;
    //@ assert max2 == c || max2 == d;

    result = max1 + max2;
    return result;
}

/*@
    requires is_valid_range(a);
    requires is_valid_range(b);
    requires is_valid_range(c);
    requires is_valid_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
*/
int func2(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int result;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    //@ assert is_valid_range(d);

    max1 = a > b ? a : b;
    max2 = c > d ? c : d;

    //@ assert 1 <= max1 && max1 <= 1000;
    //@ assert 1 <= max2 && max2 <= 1000;
    //@ assert max1 + max2 <= 2000;

    //@ assert max1 == a || max1 == b;
    //@ assert max2 == c || max2 == d;

    result = max1 + max2;
    return result;
}
