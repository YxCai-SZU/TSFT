#include <stdbool.h>

/*@
    requires (2 <= (n) && (n) <= 100);
    requires (2 <= (m) && (m) <= 100);
    ensures \result == true;
*/
bool func(int n, int m) {
    // Variable declarations at top of scope
    bool result = false;
    
    //@ assert (2 <= (n) && (n) <= 100);
    //@ assert (2 <= (m) && (m) <= 100);
    
    //@ assert n + m <= 200;
    //@ assert n + m <= 202;
    
    result = true;
    return result;
}

int main() {
    return 0;
}
