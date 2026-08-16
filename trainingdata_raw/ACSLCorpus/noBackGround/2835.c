#include <stddef.h>

/*@
  requires (1 <= (n) && (n) <= 100 && 0 <= (r) && (r) <= 4111);
  ensures \result == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
  ensures n >= 10 ==> \result == r;
  ensures n < 10 ==> \result == r + 100 * (10 - n);
*/
size_t func(size_t n, size_t r)
{
    size_t res;

    if (n >= 10) {
        //@ assert n >= 10;
        res = r;
    } else {
        //@ assert n < 10;
        res = r + 100 * (10 - n);
    }

    //@ assert res == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    return res;
}
