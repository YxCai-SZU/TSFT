#include <stdbool.h>

/*@
  requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
  ensures \result == (a + b + c >= 22);
*/
bool func(long a, long b, long c) {
    long ret = 0;
    long sum = a + b + c;
    
    if (sum >= 22) {
        ret = 1;
    }
    
    //@ assert ret == 1 ==> sum >= 22;
    //@ assert ret == 0 ==> sum < 22;
    
    return ret == 1;
}
