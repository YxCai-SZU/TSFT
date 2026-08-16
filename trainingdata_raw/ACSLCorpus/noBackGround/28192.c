#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> a + b + c >= 22;
*/
bool func(int a, int b, int c)
{
    int sum;
    bool bust;

    sum = a + b + c;
    bust = false;

    if (sum >= 22)
    {
        bust = true;
    }

    //@ assert bust == (sum >= 22);

    return bust;
}
