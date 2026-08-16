#include <stdbool.h>

/*@
    requires 0 <= a < b < c < d < e <= 123;
    requires k <= 123;
    ensures \result == true <==> e - a <= k;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    bool res;
    
    //@ assert 0 <= a < b < c < d < e <= 123;
    //@ assert k <= 123;
    
    if (e - a <= k) {
        //@ assert ((e) - (a) <= (k));
        res = true;
    } else {
        //@ assert !((e) - (a) <= (k));
        res = false;
    }
    
    //@ assert res == true <==> e - a <= k;
    return res;
}
