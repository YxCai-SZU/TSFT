#include <stdbool.h>

/*@
    requires x > 0;
    ensures \result == ((x) - 1);
    assigns \nothing;
*/
int decrement_func(int x) {
    int result;
    result = x - 1;
    //@ assert result == ((x) - 1);
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    int x;
    int y;
    
    x = 10;
    y = decrement_func(x);
    //@ assert y == 9;
    
    return 0;
}
