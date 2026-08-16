#include <stdbool.h>

/*@
  requires \valid(v+(0..2));
  requires \forall integer i; 0 <= i < 3 ==> ((v[i]) == 0 || (v[i]) == 1);
  ensures \result == (v[0] == v[1] || v[1] == v[2] || v[0] == v[2]);
  assigns \nothing;
*/
bool func(long v[3])
{
    long a;
    long b;
    long c;
    bool is_all_zero;
    bool is_all_one;
    bool ans;

    a = v[0];
    b = v[1];
    c = v[2];
    is_all_zero = false;
    is_all_one = false;

    if (a == 0 && b == 0 && c == 0) {
        is_all_zero = true;
    } else if (a == 1 && b == 1 && c == 1) {
        is_all_one = true;
    }

    if (is_all_zero || is_all_one) {
        ans = true;
    } else {
        if (a == b || b == c || a == c) {
            ans = true;
        } else {
            ans = false;
        }
    }

    //@ assert ans == (v[0] == v[1] || v[1] == v[2] || v[0] == v[2]);
    return ans;
}
