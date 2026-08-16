#include <stdbool.h>

/*@
  requires 1 <= x <= 100;
  requires 1 <= y <= 100;
  ensures \result == (x <= y);
  assigns \nothing;
*/
bool func(int x, int y)
{
    //@ assert x >= 1 && x <= 100;
    //@ assert y >= 1 && y <= 100;
    return x <= y;
}

/*@
  requires \valid(a + (0 .. len_a-1));
  requires \valid(b + (0 .. len_b-1));
  requires ((len_a) > 0);
  requires ((len_b) > 0);
  assigns \nothing;
*/
void example_6(int *a, int len_a, int *b, int len_b)
{
    //@ assert ((len_a) > 0);
}

/*@
  requires \valid(a + (0 .. len_a-1));
  requires \valid(b + (0 .. len_b-1));
  requires ((len_a) > 0);
  requires ((len_b) > 0);
  assigns \nothing;
*/
void example_6_2(int *a, int len_a, int *b, int len_b)
{
    //@ assert ((len_a) > 0);
}
