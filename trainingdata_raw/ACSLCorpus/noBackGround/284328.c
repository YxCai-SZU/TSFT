#include <limits.h>

/*@
    requires (1 <= (x) && (x) <= 100) && (1 <= (y) && (y) <= 100) && (1 <= (z) && (z) <= 100);
    ensures 1 <= \result && \result <= 50000;
    ensures \result == ((x) * (y)) || 
            \result == ((y) * (z)) || 
            \result == ((z) * (x));
    assigns \nothing;
*/
int func(int x, int y, int z) {
    int max1;
    int max2;
    
    //@ assert 1 <= ((x) * (y)) && ((x) * (y)) <= 10000;
    //@ assert 1 <= ((y) * (z)) && ((y) * (z)) <= 10000;
    //@ assert 1 <= ((z) * (x)) && ((z) * (x)) <= 10000;
    
    if (x * y > y * z) {
        max1 = x * y;
    } else {
        max1 = y * z;
    }
    
    //@ assert max1 == ((x) * (y)) || max1 == ((y) * (z));
    
    if (max1 > z * x) {
        max2 = max1;
    } else {
        max2 = z * x;
    }
    
    //@ assert max2 == ((x) * (y)) || max2 == ((y) * (z)) || max2 == ((z) * (x));
    
    return max2;
}

int main() {
    return 0;
}
