#include <stdint.h>

/*@
    requires (1 <= (a) <= (b) <= 20);
    ensures \result == a + b || \result == b - a;
    ensures \result >= 0;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t result;
    int64_t temp_a;
    int64_t temp_b;
    int64_t max_val;
    int64_t min_val;
    
    result = 0;
    temp_a = a;
    temp_b = b;
    
    //@ assert (1 <= (a) <= (b) <= 20);
    
    if (temp_a < 0) {
        temp_a = temp_a * -1;
    }
    if (temp_b < 0) {
        temp_b = temp_b * -1;
    }
    
    //@ assert temp_a == ((a) >= 0 ? (a) : -(a));
    //@ assert temp_b == ((b) >= 0 ? (b) : -(b));
    
    if (temp_a > temp_b) {
        max_val = temp_a;
    } else {
        max_val = temp_b;
    }
    
    if (temp_a < temp_b) {
        min_val = temp_a;
    } else {
        min_val = temp_b;
    }
    
    //@ assert max_val == ((((a) >= 0 ? (a) : -(a))) >= (((b) >= 0 ? (b) : -(b))) ? (((a) >= 0 ? (a) : -(a))) : (((b) >= 0 ? (b) : -(b))));
    //@ assert min_val == ((((a) >= 0 ? (a) : -(a))) <= (((b) >= 0 ? (b) : -(b))) ? (((a) >= 0 ? (a) : -(a))) : (((b) >= 0 ? (b) : -(b))));
    //@ assert max_val >= min_val;
    
    //@ assert 0 <= max_val - min_val <= 20;
    //@ assert 0 <= (max_val - min_val) * 2 <= 40;
    
    if ((max_val - min_val) * 2 <= 1) {
        result = a + b;
    } else {
        result = b - a;
    }
    
    //@ assert result == a + b || result == b - a;
    //@ assert result >= 0;
    
    return result;
}
