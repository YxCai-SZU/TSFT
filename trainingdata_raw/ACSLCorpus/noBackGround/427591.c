#include <stdbool.h>

/*@
  requires (1 <= (X) && (X) <= 100 &&
      1 <= (Y) && (Y) <= 100);
  ensures \result == ((X) * (Y) / 2);
  assigns \nothing;
*/
int func(int X, int Y)
{
    // Variable declarations at top of scope
    int product;
    int result;
    int count;

    //@ assert ((1 <= ((X)) && ((X)) <= 100 &&       1 <= ((Y)) && ((Y)) <= 100) && 1 <= (X) * (Y) && (X) * (Y) <= 10000);

    product = X * Y;
    result = 0;
    count = 0;

    /*@
      loop invariant (1 <= (X) && (X) <= 100 &&
      1 <= (Y) && (Y) <= 100);
      loop invariant 0 <= product <= X * Y;
      loop invariant 0 <= result <= ((X) * (Y) / 2);
      loop invariant product + 2 * result == X * Y;
      loop invariant ((1 <= ((X)) && ((X)) <= 100 &&
      1 <= ((Y)) && ((Y)) <= 100) && 1 <= (X) * (Y) && (X) * (Y) <= 10000);
      loop assigns product, result, count;
      loop variant product;
    */
    while (product >= 2)
    {
        product -= 2;
        result += 1;
        //@ assert product + 2 * result == X * Y;
    }

    return result;
}
