#include <stdbool.h>

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  requires 0 <= x <= 100;
  ensures \result == (x - a >= 0 && x - a <= b);
*/
bool func(int a, int b, int x)
{
    int left;
    int right;
    bool is_within_range;

    left = x - a;
    right = b;
    is_within_range = false;

    if (left >= 0 && left <= right)
    {
        is_within_range = true;
    }

    //@ assert is_within_range == (x - a >= 0 && x - a <= b);

    return is_within_range;
}
