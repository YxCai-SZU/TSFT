#include <stdbool.h>

/*@
  requires (1 <= (n) <= 10000 &&
      1 <= (a) <= 10000 &&
      1 <= (b) <= 10000 &&
      (a) + (b) <= (n));
  ensures \result == (n - a - b >= 0);
*/
bool func(int n, int a, int b) {
    int max_val;
    int min_val;
    int abs_val;
    bool result;
    
    // Calculate max
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }
    
    // Calculate min
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    
    // Calculate abs
    if (n - max_val - min_val < 0) {
        abs_val = -(n - max_val - min_val);
    } else {
        abs_val = n - max_val - min_val;
    }
    
    //@ assert abs_val == ((n) - (((a)) > ((b)) ? ((a)) : ((b))) - (((a)) < ((b)) ? ((a)) : ((b))) < 0 ?       -((n) - (((a)) > ((b)) ? ((a)) : ((b))) - (((a)) < ((b)) ? ((a)) : ((b)))) :       (n) - (((a)) > ((b)) ? ((a)) : ((b))) - (((a)) < ((b)) ? ((a)) : ((b))));
    
    result = (n - a - b >= 0);
    return result;
}
