#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) && (1 <= (c) && (c) <= 10);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int v[3];
    unsigned int i = 0;
    
    v[i] = a;
    i = i + 1;
    v[i] = b;
    i = i + 1;
    v[i] = c;
    
    //@ assert i == 2;
    //@ assert v[0] == a && v[1] == b && v[2] == c;
    
    return v[0] < v[1] && v[1] < v[2];
}
