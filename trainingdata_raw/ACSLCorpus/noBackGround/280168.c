#include <stdbool.h>

/*@
    requires \valid_read(v + (0 .. 2));
    requires v[0] == 1 || v[0] == 2;
    requires v[1] == 1 || v[1] == 2;
    requires v[2] == 1 || v[2] == 2;
    assigns \nothing;
    ensures \result == (v[2] == 1 || (v[1] == 1 && v[0] == 2) || (v[1] == 2 && v[0] == 1));
*/
bool func(int* v) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert \valid_read(v + 0);
    a = v[0];
    
    //@ assert \valid_read(v + 1);
    b = v[1];
    
    //@ assert \valid_read(v + 2);
    c = v[2];
    
    //@ assert a == 1 || a == 2;
    //@ assert b == 1 || b == 2;
    //@ assert c == 1 || c == 2;
    
    result = (c == 1 || (b == 1 && a == 2) || (b == 2 && a == 1));
    
    //@ assert result == (v[2] == 1 || (v[1] == 1 && v[0] == 2) || (v[1] == 2 && v[0] == 1));
    return result;
}
