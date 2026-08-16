#include <stdbool.h>

/*@
    requires ((1) >= 0 && (1) >= 0);
    ensures \result == 0;
*/
int main() {
    int r = 1;
    int h = 1;
    
    //@ assert ((r) >= 0 && (h) >= 0);
    //@ assert (0) == 0;
    
    return 0;
}
