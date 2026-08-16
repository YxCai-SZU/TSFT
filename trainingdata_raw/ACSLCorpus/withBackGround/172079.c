#include <stdbool.h>

/*@
    predicate condition1(integer a, integer b, integer c, integer d) =
        a < c && b > d;
    predicate condition2(integer a, integer b, integer c, integer d) =
        c < a && d > b;
    predicate condition3(integer a, integer b, integer c, integer d) =
        a <= c && b >= d;
    predicate condition4(integer a, integer b, integer c, integer d) =
        c <= a && d >= b;
    predicate condition5(integer a, integer b, integer c, integer d) =
        a == c && b == d;
    
    lemma all_conditions_false:
        \forall integer a, b, c, d;
        !condition1(a,b,c,d) && !condition2(a,b,c,d) && 
        !condition3(a,b,c,d) && !condition4(a,b,c,d) && 
        !condition5(a,b,c,d) ==> 
        !((a < c && b > d) || (c < a && d > b) || 
          (a <= c && b >= d) || (c <= a && d >= b) || 
          (a == c && b == d));
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> 
            (a < c && b > d) || (c < a && d > b) || 
            (a <= c && b >= d) || (c <= a && d >= b) || 
            (a == c && b == d);
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top
    bool res = false;
    
    if (a < c && b > d) {
        res = true;
        //@ assert condition1(a,b,c,d);
        return res;
    }
    
    if (c < a && d > b) {
        res = true;
        //@ assert condition2(a,b,c,d);
        return res;
    }
    
    if (a <= c && b >= d) {
        res = true;
        //@ assert condition3(a,b,c,d);
        return res;
    }
    
    if (c <= a && d >= b) {
        res = true;
        //@ assert condition4(a,b,c,d);
        return res;
    }
    
    if (a == c && b == d) {
        res = true;
        //@ assert condition5(a,b,c,d);
        return res;
    }
    
    //@ assert !condition1(a,b,c,d) && !condition2(a,b,c,d);
    //@ assert !condition3(a,b,c,d) && !condition4(a,b,c,d);
    //@ assert !condition5(a,b,c,d);
    
    res = false;
    return res;
}
