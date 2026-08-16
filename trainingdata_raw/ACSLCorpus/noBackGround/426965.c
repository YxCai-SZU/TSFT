#include <stdbool.h>

/*@
  requires (1 <= (a) && (a) <= 5000 &&
      1 <= (b) && (b) <= 5000 &&
      1 <= (c) && (c) <= 5000);
  ensures \result == (a + b >= c);
  assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ab;
    unsigned int min_val;
    unsigned int max_val;
    
    ab = a + b;
    
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }
    
    if (max_val >= c) {
        //@ assert max_val >= c;
        return true;
    }
    
    if (min_val >= c) {
        //@ assert min_val >= c;
        return true;
    }
    
    //@ assert ab >= c ==> ab >= c;
    return ab >= c;
}
