#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires 1 <= v[0] <= 100;
    requires 1 <= v[1] <= 100;
    requires 1 <= v[2] <= 100;
    ensures \result == (v[0] + v[1] == v[2] || v[1] + v[2] == v[0] || v[0] + v[2] == v[1]);
*/
bool func(int v[3]) {
    int a;
    int b;
    int c;
    bool result;
    
    a = v[0];
    b = v[1];
    c = v[2];
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    //@ assert ((a) + (b)) <= 200;
    //@ assert ((a) + (c)) <= 200;
    //@ assert (((c)) + (c)) <= 200;
    
    result = (a + b == c) || (a + c == b) || (b + c == a);
    return result;
}
