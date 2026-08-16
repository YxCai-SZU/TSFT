#include <stdbool.h>

/*@
    requires a <= b;
    ensures \result == (a <= c && c <= b);
*/
bool is_between(int a, int b, int c) {
    bool result;
    //@ assert a <= b;
    result = (a <= c && c <= b);
    //@ assert result == (a <= c && c <= b);
    return result;
}

int main() {
    //@ assert ((10) % 2 == 0);
    //@ assert ((15) % 3 == 0 || (15) % 5 == 0);
    //@ assert ((0) <= (50) && (50) < (100));
    
    bool res;
    res = is_between(0, 100, 50);
    //@ assert res == (0 <= 50 && 50 <= 100);
    
    return 0;
}
