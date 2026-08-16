#include <stdbool.h>
/*@
    predicate valid_range(integer a) = 1 <= a <= 100;
    predicate valid_range_add(integer a) = 0 <= a <= 10000;
    logic integer square(integer a) = a * a;
    logic integer add(integer x, integer y) = x + y;
    logic integer subtract(integer x, integer y) = x - y;
    lemma square_bounds: \forall integer a; valid_range(a) ==> 1 <= square(a) <= 10000;
*/

/*@
    requires valid_range(a);
    ensures \result == square(a);
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations
    int result;

    //@ assert valid_range(a);
    //@ assert 1 <= square(a);
    //@ assert square(a) <= 10000;

    result = a * a;
    //@ assert result == square(a);
    return result;
}

/*@
    requires valid_range_add(x) && valid_range_add(y);
    ensures \result == add(x, y);
    assigns \nothing;
*/
int my_add(int x, int y)
{
    // Variable declarations
    int ret;

    //@ assert 0 <= add(x, y) <= 20000;
    ret = x + y;
    //@ assert ret == add(x, y);
    return ret;
}

/*@
    requires valid_range_add(x) && valid_range_add(y) && x >= y;
    ensures \result == subtract(x, y);
    assigns \nothing;
*/
int my_sub(int x, int y)
{
    // Variable declarations
    int ret;

    //@ assert 0 <= subtract(x, y) <= 10000;
    ret = x - y;
    //@ assert ret == subtract(x, y);
    return ret;
}
