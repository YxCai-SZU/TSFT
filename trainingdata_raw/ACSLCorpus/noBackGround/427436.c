#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == (x * 4 + y * 2 >= 200 || x * 4 + (100 - y) * 2 >= 200 || (100 - x) * 4 + y * 2 >= 200 || (100 - x) * 4 + (100 - y) * 2 >= 200);
*/
bool func(int x, int y) {
    bool result;
    int p1;
    int p2;
    int p3;
    int p4;
    int p;
    
    result = false;
    p1 = x * 4 + y * 2;
    p2 = x * 4 + (100 - y) * 2;
    p3 = (100 - x) * 4 + y * 2;
    p4 = (100 - x) * 4 + (100 - y) * 2;
    
    if (p1 >= p2) {
        if (p1 >= p3) {
            if (p1 >= p4) {
                p = p1;
            } else {
                p = p4;
            }
        } else {
            if (p3 >= p4) {
                p = p3;
            } else {
                p = p4;
            }
        }
    } else {
        if (p2 >= p3) {
            if (p2 >= p4) {
                p = p2;
            } else {
                p = p4;
            }
        } else {
            if (p3 >= p4) {
                p = p3;
            } else {
                p = p4;
            }
        }
    }
    
    if (p >= 200) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (p1 >= 200 || p2 >= 200 || p3 >= 200 || p4 >= 200);
    
    return result;
}
