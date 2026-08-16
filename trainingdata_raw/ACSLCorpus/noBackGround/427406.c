#include <stdbool.h>
/*@
    requires (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    ensures (((m) == (n) ==> (\result) == 1) && ((m) != (n) ==> (\result) == 0));
*/
int func(int n, int m) {
    int result;
    result = 1;
    
    if (n != m) {
        result = 0;
    }
    
    //@ assert (m == n ==> result == 1) && (m != n ==> result == 0);
    return result;
}
