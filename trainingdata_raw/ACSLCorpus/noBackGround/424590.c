#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3);
    requires (1 <= (b) <= 3);
    ensures \result == (((((a)) * ((b))) * 2) % 2 != 0);
*/
bool func(unsigned int a, unsigned int b) {
    unsigned int c;
    bool is_odd;
    unsigned int abs_c;
    unsigned int remainder;
    
    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    
    //@ assert a * b <= 9;
    
    c = a * b * 2;
    is_odd = false;
    
    if (c >= 2) {
        abs_c = c - 2;
    } else {
        abs_c = c;
    }
    
    remainder = abs_c;
    
    /*@
        loop invariant 0 <= remainder <= abs_c;
        loop invariant remainder <= a * b * 2;
        loop invariant remainder % 2 == abs_c % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }
    
    if (remainder == 1) {
        is_odd = true;
    }
    
    return is_odd;
}

int main() {
    return 0;
}
