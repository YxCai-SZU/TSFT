#include <stdbool.h>

/*@
  requires 1 <= n <= 100;
  requires 1 <= m <= 100;
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  ensures \result == true <==> ((n) + (m) <= (a) + (b) && (a) + (m) <= (n) + (b));
*/
bool func(unsigned int n, unsigned int m, unsigned int a, unsigned int b)
{
    bool result;
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= m <= 100;
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    if (n + m <= a + b && a + m <= n + b) {
        //@ assert ((n) + (m) <= (a) + (b) && (a) + (m) <= (n) + (b));
        result = true;
    } else {
        //@ assert !((n) + (m) <= (a) + (b) && (a) + (m) <= (n) + (b));
        result = false;
    }
    
    return result;
}
