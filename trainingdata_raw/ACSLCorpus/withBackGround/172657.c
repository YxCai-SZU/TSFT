#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 100;
    
    predicate triangle_inequality(integer a, integer b, integer c) = 
        a + b > c && b + c > a && c + a > b;
    
    predicate equality_condition(integer a, integer b, integer c) = 
        a + b == c || b + c == a || c + a == b;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == true ==> equality_condition(a, b, c);
    ensures \result == true ==> triangle_inequality(a, b, c);
*/
bool find_unique_triangles(int a, int b, int c) {
    // Variable declarations at top
    bool ret = false;
    
    // Precondition assertions
    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    
    // Check triangle inequality
    if (a + b <= c || b + c <= a || c + a <= b) {
        return false;
    }
    
    // Check equality conditions
    if (a + b == c || b + c == a || c + a == b) {
        ret = true;
    }
    
    // Postcondition verification
    if (ret) {
        //@ assert equality_condition(a, b, c);
        //@ assert triangle_inequality(a, b, c);
    }
    
    return ret;
}
