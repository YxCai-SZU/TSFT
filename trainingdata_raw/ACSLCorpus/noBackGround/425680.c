#include <stdbool.h>

/*@ requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
      1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == ((c) - ((a) - (b))) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int max_val;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&       1 <= (c) && (c) <= 20);
    result = c - (a - b);
    
    //@ assert result == ((c) - ((a) - (b)));
    
    if (result > 0) {
        max_val = result;
        //@ assert max_val == ((c) - ((a) - (b)));
    } else {
        max_val = 0;
        //@ assert max_val == 0;
    }
    
    //@ assert max_val >= 0;
    //@ assert max_val <= c;
    //@ assert max_val == ((c) - ((a) - (b))) || max_val == 0;
    
    return max_val;
}
