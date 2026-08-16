#include <stdbool.h>

/*@
    predicate x_bound(integer a, integer x) =
        x * 100 <= a * 8;

    predicate y_bound(integer b, integer y) =
        y * 100 <= b * 10 + b * 5;

    logic integer compute_x(integer a) = (a * 8) / 100;
    logic integer compute_y(integer b) = (b * 10) / 100 + (b * 5) / 100;

    lemma x_bound_lemma:
        \forall integer a, x; 1 <= a <= 100 && x == compute_x(a) ==> x_bound(a, x);

    lemma y_bound_lemma:
        \forall integer b, y; 1 <= b <= 100 && y == compute_y(b) ==> y_bound(b, y);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> ((a * 8) / 100 >= (b * 10) / 100 + (b * 5) / 100);
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int x;
    unsigned int y;
    bool result;

    x = (a * 8) / 100;
    y = (b * 10) / 100 + (b * 5) / 100;

    //@ assert x_bound(a, x);
    //@ assert y_bound(b, y);

    if (x >= y)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
