#include <limits.h>

/*@
    requires \valid_read(x + (0..3));
    requires (-100 <= (x[0]) <= 100) && (-100 <= (x[1]) <= 100) &&
             (-100 <= (x[2]) <= 100) && (-100 <= (x[3]) <= 100);
    assigns \nothing;
    ensures ((\result) == (x[0]) * (x[3]) || (\result) == (x[1]) * (x[2]) || (\result) == (x[0]) * (x[2]) || (\result) == (x[1]) * (x[3]));
    ensures (-10000 <= (\result) <= 10000);
*/
int func(const int x[4]) {
    int max_val;
    int temp_val;
    
    //@ assert (-10000 <= (x[0] * x[3]) <= 10000);
    //@ assert (-10000 <= (x[1] * x[2]) <= 10000);
    //@ assert (-10000 <= (x[0] * x[2]) <= 10000);
    //@ assert (-10000 <= (x[1] * x[3]) <= 10000);
    
    max_val = x[0] * x[3];
    
    temp_val = x[1] * x[2];
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    temp_val = x[0] * x[2];
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    temp_val = x[1] * x[3];
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert ((max_val) == (x[0]) * (x[3]) || (max_val) == (x[1]) * (x[2]) || (max_val) == (x[0]) * (x[2]) || (max_val) == (x[1]) * (x[3]));
    //@ assert (-10000 <= (max_val) <= 10000);
    
    return max_val;
}
