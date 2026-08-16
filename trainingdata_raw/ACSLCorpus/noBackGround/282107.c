#include <stdbool.h>

/*@ requires (2 <= (n) && (n) <= 100 &&
      1 <= (a) && (a) < (b) && (b) <= (n));
    ensures \result == (((b) - (a)) == 1 || 
                       (((b) - (a)) != 1 && ((b) - (a)) % 2 == 0));
    assigns \nothing;
*/
bool func(int n, int a, int b) {
    int d;
    bool ret;
    
    d = b - a;
    
    //@ assert d == ((b) - (a));
    
    if (d == 1) {
        //@ assert d == 1;
        ret = true;
    } else if (d > 1) {
        //@ assert d > 1 && d <= n - 1;
        ret = (d % 2 == 0);
    } else {
        //@ assert \false;
        ret = false;
    }
    
    return ret;
}
