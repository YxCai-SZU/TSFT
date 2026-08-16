#include <stdbool.h>

/*@ requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
      1 <= (c) && (c) <= 20);
    ensures \result >= 0 && \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c) {
    int result = c - a + b;
    
    //@ assert result == c - a + b;
    
    if (a < c + b) {
        //@ assert result >= 0;
        //@ assert result <= c;
        return result;
    } else {
        return 0;
    }
}
