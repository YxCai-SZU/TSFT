#include <stdbool.h>

/*@
  requires (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9) && (1 <= (c) && (c) <= 9);
  ensures \result == ((a == b && a != c) || (a == c && a != b) || (b == c && a != b));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int cnt = 0;
    
    //@ assert cnt == 0;
    
    if (a == b) {
        cnt += 1;
    }
    if (a == c) {
        cnt += 1;
    }
    if (b == c) {
        cnt += 1;
    }
    
    //@ assert cnt == 0 || cnt == 1 || cnt == 2 || cnt == 3;
    
    return cnt == 1;
}
