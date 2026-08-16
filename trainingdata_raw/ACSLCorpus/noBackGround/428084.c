#include <stdbool.h>

/*@
  requires ((1) <= (a) && (a) <= (500));
  requires ((1) <= (b) && (b) <= (500));
  requires ((1) <= (c) && (c) <= (1000));
  ensures \result == (a + b >= c);
*/
bool func(int a, int b, int c)
{
    int state;
    int i;

    state = 0;
    i = 0;

    /*@
      loop invariant 0 <= i <= a;
      loop invariant state == i;
      loop invariant ((1) <= (a) && (a) <= (500));
      loop invariant ((1) <= (b) && (b) <= (500));
      loop invariant ((1) <= (c) && (c) <= (1000));
      loop assigns i, state;
      loop variant a - i;
    */
    while (i < a)
    {
        state += 1;
        i += 1;
    }

    i = 0;

    /*@
      loop invariant 0 <= i <= b;
      loop invariant state == a + i;
      loop invariant ((1) <= (a) && (a) <= (500));
      loop invariant ((1) <= (b) && (b) <= (500));
      loop invariant ((1) <= (c) && (c) <= (1000));
      loop assigns i, state;
      loop variant b - i;
    */
    while (i < b)
    {
        state += 1;
        i += 1;
    }

    //@ assert state == a + b;

    return state >= c;
}
