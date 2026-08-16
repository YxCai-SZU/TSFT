#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 9;
    
    predicate is_strictly_increasing(integer a, integer b, integer c) = 
        a < b && b < c;
*/

/*@
    requires \valid(v + (0..2));
    requires is_valid_range(v[0]);
    requires is_valid_range(v[1]);
    requires is_valid_range(v[2]);
    ensures \result == true <==> is_strictly_increasing(v[0], v[1], v[2]);
*/
bool func(int v[3]) {
    int a;
    int b;
    int c;
    bool result;
    
    a = v[0];
    b = v[1];
    c = v[2];
    
    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    
    result = (a < b) && (b < c);
    
    //@ assert result == true <==> is_strictly_increasing(a, b, c);
    return result;
}
