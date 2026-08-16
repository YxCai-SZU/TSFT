#include <stdbool.h>

/*@ predicate test_bool(integer a) = a == 0; */

/*@ lemma calc_example_8: \forall integer a; test_bool(a) <==> (a == 0); */

/*@
  requires 1 <= a <= 10;
  requires 1 <= b <= 10;
  ensures \result == (a * 2 <= b);
  assigns \nothing;
*/
bool func(int a, int b)
{
    //@ assert 1 <= a && a <= 10;
    return a * 2 <= b;
}

/*@
  requires 1 <= a <= 10;
  requires 1 <= b <= 10;
  ensures \result == (b <= a * 2);
  assigns \nothing;
*/
bool func2(int a, int b)
{
    //@ assert 1 <= b && b <= 10;
    return b <= a * 2;
}

/*@
  requires 1 <= a <= 10;
  requires 1 <= b <= 10;
  ensures \result == (a * 2 < b);
  assigns \nothing;
*/
bool func3(int a, int b)
{
    //@ assert 2 <= a * 2 && a * 2 <= 20;
    return a * 2 < b;
}

/*@
  requires 1 <= a <= 10;
  requires 1 <= b <= 10;
  ensures \result == (b < a * 2);
  assigns \nothing;
*/
bool func4(int a, int b)
{
    //@ assert 2 <= a * 2 && a * 2 <= 20;
    return b < a * 2;
}

int main()
{
    return 0;
}
