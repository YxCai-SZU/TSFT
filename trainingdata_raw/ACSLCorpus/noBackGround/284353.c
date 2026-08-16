#include <stdbool.h>

/*@
  requires a <= 100 && b <= 100 && c <= 100;
  ensures \result == true <==> (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
  assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    //@ assert a <= 100 && b <= 100 && c <= 100;
    
    if ((a < c && c < b) || (a > c && c > b)) {
        //@ assert (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
        result = true;
    } else {
        //@ assert !(((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
        result = false;
    }
    
    return result;
}
