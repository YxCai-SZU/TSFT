#include <stdbool.h>

/*@
    predicate is_within_width(integer w, integer x, integer r) =
        x >= r && x <= w - r;

    predicate is_within_height(integer h, integer y, integer r) =
        y >= r && y <= h - r;

    predicate circle_in_rect(integer w, integer h, integer x, integer y, integer r) =
        is_within_width(w, x, r) && is_within_height(h, y, r);

    lemma width_implies_bounds:
        \forall integer w, x, r;
            is_within_width(w, x, r) ==> x - r >= 0 && x + r <= w;

    lemma height_implies_bounds:
        \forall integer h, y, r;
            is_within_height(h, y, r) ==> y - r >= 0 && y + r <= h;
*/

/*@
    requires 0 <= w <= 10000;
    requires 0 <= h <= 10000;
    requires 0 <= x <= w;
    requires 0 <= y <= h;
    requires 0 <= r <= 10000;
    requires is_within_width(w, x, r);
    requires is_within_height(h, y, r);
    ensures \result == (x >= r && x <= w - r && y >= r && y <= h - r);
*/
bool func(int w, int h, int x, int y, int r)
{
    int left;
    int right;
    int top;
    int bottom;
    bool result;

    //@ assert is_within_width(w, x, r);
    //@ assert is_within_height(h, y, r);
    //@ assert circle_in_rect(w, h, x, y, r);

    left = (x - r >= 0);
    right = (x + r <= w);
    top = (y - r >= 0);
    bottom = (y + r <= h);

    //@ assert left && right && top && bottom;

    if (left && right && top && bottom)
    {
        //@ assert x >= r && x <= w - r && y >= r && y <= h - r;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
