#include <stdbool.h>

/*@
  requires \valid_read(xs + (0..2));
  requires (1 <= (xs[0]) <= 100 &&
      1 <= (xs[1]) <= 100 &&
      1 <= (xs[2]) <= 100);
  ensures \result == (xs[0] + xs[1] == xs[2] ||
                      xs[1] + xs[2] == xs[0] ||
                      xs[2] + xs[0] == xs[1]);
*/
bool func(unsigned int xs[3])
{
    bool result = false;
    unsigned int sum1 = 0;
    unsigned int sum2 = 0;
    unsigned int sum3 = 0;

    //@ assert (1 <= (xs[0]) <= 100 &&       1 <= (xs[1]) <= 100 &&       1 <= (xs[2]) <= 100);
    sum1 = xs[0] + xs[1];
    sum2 = xs[1] + xs[2];
    sum3 = xs[2] + xs[0];

    //@ assert sum1 == ((xs[0]) + (xs[1]));
    //@ assert sum2 == ((xs[1]) + (xs[2]));
    //@ assert sum3 == ((xs[2]) + (xs[0]));

    if (sum1 == xs[2] || sum2 == xs[0] || sum3 == xs[1])
    {
        result = true;
    }

    return result;
}
