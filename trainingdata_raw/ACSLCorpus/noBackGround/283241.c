#include <stdbool.h>

/*@
  requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
  assigns \nothing;
  ensures \result == true <==> (500 * (k) >= (x));
*/
bool func(int k, int x)
{
    int en;
    bool result;
    
    en = 500;
    
    //@ assert en == 500;
    
    if (en * k >= x)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}
