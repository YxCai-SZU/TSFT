#include <limits.h>

/*@
    predicate in_range(integer v) = -1000 <= v <= 1000;
    
    logic integer cube(integer x) = x * x * x;
    
    lemma cube_range: \forall integer x; in_range(x) ==> -1000000000 <= cube(x) <= 1000000000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == cube(a) + cube(b);
    assigns \nothing;
*/
int sum_cubes(int a, int b) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    
    //@ assert a * a >= -1000000 && a * a <= 1000000;
    //@ assert b * b >= -1000000 && b * b <= 1000000;
    
    //@ assert a * a * a >= -1000000000 && a * a * a <= 1000000000;
    //@ assert b * b * b >= -1000000000 && b * b * b <= 1000000000;
    
    result = a * a * a + b * b * b;
    
    //@ assert result == cube(a) + cube(b);
    return result;
}

int main() {
    return 0;
}
