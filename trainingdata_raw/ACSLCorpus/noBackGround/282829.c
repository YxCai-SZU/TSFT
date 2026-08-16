#include <stdbool.h>

/*@
    requires \valid_read(v + (0 .. 2));
    requires ((3) >= 3 &&
    1 <= (v)[0] <= 100 &&
    1 <= (v)[1] <= 100 &&
    1 <= (v)[2] <= 100);
    ensures \result == (v[0] + v[1] == v[2] || 
                       v[1] + v[2] == v[0] || 
                       v[0] + v[2] == v[1]);
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    bool is_equal;
    
    a = v[0];
    b = v[1];
    c = v[2];
    is_equal = false;
    
    //@ assert a + b == ((a) + (b));
    if (a + b == c) {
        is_equal = true;
    } else if (b + c == a) {
        is_equal = true;
    } else if (a + c == b) {
        is_equal = true;
    }
    
    //@ assert is_equal == (a + b == c || b + c == a || a + c == b);
    return is_equal;
}
