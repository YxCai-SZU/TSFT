#include <stdbool.h>

/*@
requires \valid(v + (0..2));
requires ((3) == 3 &&
    \forall integer i; 0 <= i < (3) ==> 1 <= (v)[i] && (v)[i] <= 100);
assigns \nothing;
ensures \result == (v[1] - v[0] == v[2] - v[1]);
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    int ab;
    int bc;
    int diff;
    int result;
    
    a = v[0];
    //@ assert a == v[0];
    
    b = v[1];
    //@ assert b == v[1];
    
    c = v[2];
    //@ assert c == v[2];
    
    ab = b - a;
    //@ assert ab == b - a;
    
    bc = c - b;
    //@ assert bc == c - b;
    
    diff = ab - bc;
    //@ assert diff == ab - bc;
    
    if (diff == 0) {
        result = 1;
        //@ assert result == 1;
    } else {
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result == 1 || result == 0;
    //@ assert result == 1 ==> diff == 0;
    //@ assert result == 0 ==> diff != 0;
    
    return result == 1;
}
