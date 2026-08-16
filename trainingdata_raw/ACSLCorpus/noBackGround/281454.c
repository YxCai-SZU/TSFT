#include <stdbool.h>

/*@
  requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100) && (1 <= (e) && (e) <= 100);
  ensures \result == true <==> a + b + c + d >= e;
*/
bool func(int a, int b, int c, int d, int e)
{
    int total;
    int i;

    total = a + b + c + d;
    i = 0;

    /*@
      loop invariant 0 <= i <= e;
      loop invariant total == a + b + c + d;
      loop invariant (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100) && (1 <= (e) && (e) <= 100);
      loop invariant 0 <= total <= 400;
      loop invariant i <= total;
      loop assigns i;
      loop variant e - i;
    */
    while (i < e)
    {
        //@ assert total == a + b + c + d;
        if (total < e)
        {
            return false;
        }
        i = i + 1;
    }
    return true;
}
