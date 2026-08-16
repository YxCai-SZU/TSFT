#include <stdbool.h>

/*@
  requires (1 <= (x) <= 100) && (1 <= (y) <= 100);
  ensures \result == ( (x * y) % 2 == 0 );
  assigns \nothing;
*/
bool func(int x, int y)
{
    int product;
    bool is_even = false;
    int temp;

    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    //@ assert 1 <= x * y && x * y <= 10000;

    product = x * y;
    temp = product;

    /*@
      loop invariant 0 <= temp <= product;
      loop invariant temp % 2 == product % 2;
      loop assigns temp;
      loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 0)
    {
        is_even = true;
    }

    //@ assert is_even == (product % 2 == 0);
    return is_even;
}
