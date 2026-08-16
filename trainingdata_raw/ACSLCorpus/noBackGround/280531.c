#include <stdbool.h>

/*@ requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    @ ensures \result >= 0;
    @ ensures \result <= ((a) + (b) + (c));
    @ ensures (\result == ((a) + (b))) || (\result == ((b) + (c))) || (\result == ((c) + (a)));
    @*/
int func(int a, int b, int c)
{
    int max_val;
    
    max_val = a + b;
    //@ assert max_val == ((a) + (b));
    
    if (b + c > max_val) {
        max_val = b + c;
        //@ assert max_val == ((b) + (c));
    }
    //@ assert max_val == ((a) + (b)) || max_val == ((b) + (c));
    
    if (c + a > max_val) {
        max_val = c + a;
        //@ assert max_val == ((c) + (a));
    }
    //@ assert max_val == ((a) + (b)) || max_val == ((b) + (c)) || max_val == ((c) + (a));
    
    //@ assert max_val >= 0;
    //@ assert max_val <= ((a) + (b) + (c));
    
    return max_val;
}
