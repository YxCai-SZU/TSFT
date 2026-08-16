#include <stdbool.h>

/*@
  requires 1 <= n <= 100;
  requires 1 <= k <= 100;
  ensures \result == true <==> ((n) % 3 == 0 ||
      ((n) % 3 == 1 && (k) > 1) ||
      ((n) % 3 == 2 && (k) >= 2));
*/
bool func(unsigned long n, unsigned long k)
{
    bool result;
    //@ ghost unsigned long n_mod_3 = n % 3;
    
    //@ assert n_mod_3 == n % 3;
    
    if (n % 3 == 0 || (n % 3 == 1 && k > 1) || (n % 3 == 2 && k >= 2)) {
        //@ assert ((n) % 3 == 0 ||       ((n) % 3 == 1 && (k) > 1) ||       ((n) % 3 == 2 && (k) >= 2));
        result = true;
    } else {
        //@ assert !((n) % 3 == 0 ||       ((n) % 3 == 1 && (k) > 1) ||       ((n) % 3 == 2 && (k) >= 2));
        result = false;
    }
    
    return result;
}
