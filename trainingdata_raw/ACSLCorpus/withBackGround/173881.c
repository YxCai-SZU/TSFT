#include <stdbool.h>

/*@
    predicate diff1_condition(integer a, integer c, integer d) =
        (a > c ==> a - c <= d) && (a <= c ==> c - a <= d);
    predicate diff2_condition(integer b, integer c, integer d) =
        (b > c ==> b - c <= d) && (b <= c ==> c - b <= d);
    predicate diff3_condition(integer a, integer b, integer d) =
        (b > a ==> b - a <= d) && (b <= a ==> a - b <= d);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> 
            (a > c ? a - c <= d : c - a <= d) ||
            (b > c ? b - c <= d : c - b <= d) ||
            (b > a ? b - a <= d : a - b <= d);
*/
bool func(int a, int b, int c, int d)
{
    int diff1;
    int diff2;
    int diff3;
    bool is_less_than_d;
    
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;
    
    if (a > c) {
        diff1 = a - c;
    } else {
        diff1 = c - a;
    }
    
    if (b > c) {
        diff2 = b - c;
    } else {
        diff2 = c - b;
    }
    
    if (b > a) {
        diff3 = b - a;
    } else {
        diff3 = a - b;
    }
    
    is_less_than_d = false;
    
    if (diff1 <= d || diff2 <= d || diff3 <= d) {
        is_less_than_d = true;
    }
    
    //@ assert is_less_than_d == true <==> (diff1 <= d || diff2 <= d || diff3 <= d);
    
    return is_less_than_d;
}
