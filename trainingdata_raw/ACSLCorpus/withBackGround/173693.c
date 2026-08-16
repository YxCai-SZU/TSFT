#include <stdbool.h>

/*@ predicate is_within_threshold(integer x, integer y, integer threshold) =
      x < y && y < threshold;
*/

/*@
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    requires 0 <= threshold <= 100;
    ensures \result == (x < y && y < threshold);
    assigns \nothing;
*/
bool is_within_threshold(unsigned int x, unsigned int y, unsigned int threshold) {
    bool res;
    
    res = x < y && y < threshold;
    
    //@ assert res == (x < y && y < threshold);
    
    return res;
}

int main() {
    bool result;
    
    result = is_within_threshold(10, 20, 30);
    
    //@ assert result == true;
    
    return 0;
}
