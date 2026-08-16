#include <stdbool.h>

/*@ predicate is_in_range(integer v) = 1 <= v && v <= 100; */

/*@
  requires \valid_read(ss + (0..2));
  requires is_in_range(ss[0]) && is_in_range(ss[1]) && is_in_range(ss[2]);
  ensures \result == (ss[0] < ss[1] && ss[1] < ss[2]);
  assigns \nothing;
*/
bool is_increasing(int ss[3]) {
    int a, b, c;
    bool ret;

    a = ss[0];
    b = ss[1];
    c = ss[2];

    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= c && c <= 100;
    //@ assert (a < b && b < c) ==> (a < b && b < c);

    ret = (a < b && b < c);
    return ret;
}
