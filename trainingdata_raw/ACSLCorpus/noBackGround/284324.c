#include <stdbool.h>

/*@
  requires (1 <= (a) <= 5000 &&
      1 <= (b) <= 5000 &&
      1 <= (c) <= 10000);
  ensures \result == (a + b >= c);
  assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int ab;
    bool result;

    //@ assert a <= 5000;
    //@ assert b <= 5000;
    //@ assert c <= 10000;
    //@ assert a + b <= 10000;

    ab = a + b;
    
    if (ab < c) {
        //@ assert ab < c;
        result = false;
    } else {
        //@ assert ab >= c;
        result = true;
    }
    
    return result;
}
