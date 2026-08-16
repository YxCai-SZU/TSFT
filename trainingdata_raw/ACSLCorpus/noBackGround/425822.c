#include <stdbool.h>

/*@
  requires \valid(result);
  requires (0 <= (n) && (n) <= 100 &&
      0 <= (m) && (m) <= 100 &&
      (m) != (n));
  assigns *result;
  ensures *result == 0 || *result == 1;
  ensures ((*result) == 1 ==> ((m) - (n) == 1 || (n) - (m) == 1));
  ensures ((*result) == 0 ==> ((m) - (n) != 1 && (n) - (m) != 1));
*/
void func(long n, long m, long *result)
{
    long diff;
    //@ assert (0 <= (n) && (n) <= 100 &&       0 <= (m) && (m) <= 100 &&       (m) != (n));
    
    if (n > m) {
        diff = n - m;
    } else {
        diff = m - n;
    }
    
    if (diff == 1) {
        //@ assert m - n == 1 || n - m == 1;
        *result = 1;
    } else {
        //@ assert m - n != 1 && n - m != 1;
        *result = 0;
    }
}
