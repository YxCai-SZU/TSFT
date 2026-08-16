#include <stdbool.h>

/*@
    predicate is_even_area(integer a, integer b, integer area) =
        (area % 2) == 0;

    logic integer rectangle_area(integer a, integer b) = a * b;

    lemma area_mod_preserved:
        \forall integer a, b, area;
        1 <= a <= 10000 && 1 <= b <= 10000 && area == a * b ==>
        (area % 2) == ((a * b) % 2);
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires a * b <= 1000000000;
    ensures \result == ((a * b) % 2 == 0);
*/
bool func(int a, int b)
{
    int area;
    bool is_even;
    int abs_area;

    area = a * b;
    is_even = false;

    if (area < 0)
    {
        abs_area = -area;
    }
    else
    {
        abs_area = area;
    }

    /*@
        loop invariant 0 <= abs_area <= a * b;
        loop invariant abs_area <= 1000000000;
        loop invariant (abs_area % 2) == (area % 2);
        loop assigns abs_area;
        loop variant abs_area;
    */
    while (abs_area >= 2)
    {
        abs_area -= 2;
    }

    if (abs_area == 0)
    {
        is_even = true;
    }

    //@ assert is_even == ((a * b) % 2 == 0);
    return is_even;
}
