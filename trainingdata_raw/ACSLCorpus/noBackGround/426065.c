#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((a == b && a != c) || (a == c && a != b) || (b == c && b != a));
*/
bool func(int a, int b, int c) {
    int cnt = 0;
    
    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    
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
    //@ assert (cnt == 1) == ((a == b && a != c) || (a == c && a != b) || (b == c && b != a));
    
    return cnt == 1;
}
