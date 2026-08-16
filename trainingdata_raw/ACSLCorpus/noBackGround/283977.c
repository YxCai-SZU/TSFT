#include <stdbool.h>

/*@
  requires \valid(v+(0..2));
  requires 1 <= v[0] && v[0] <= 100;
  requires 1 <= v[1] && v[1] <= 100;
  requires 1 <= v[2] && v[2] <= 100;
  requires ((v[1]) - (v[0]) == (v[2]) - (v[1]));
  ensures \result == true;
*/
bool func(long v[3])
{
    long x;
    long y;

    //@ assert v[0] + 2 <= 102;
    x = v[0] + 2;

    //@ assert v[1] - 2 >= -1;
    y = v[1] - 2;

    return true;
}
