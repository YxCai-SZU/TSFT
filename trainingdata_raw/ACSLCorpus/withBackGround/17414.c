#include <stdbool.h>

/*@ predicate condition1(integer a, integer b, integer c, integer d) =
      (c - b == 0) && (a <= d);
    predicate condition2(integer a, integer b, integer c, integer d) =
      (b - a == 0) && (c <= d);
    predicate condition3(integer a, integer b, integer c, integer d) =
      (d - a == 0) && (b <= c);
    predicate condition4(integer a, integer b, integer c, integer d) =
      (c - d == 0) && (a <= b);
    predicate result_condition(integer a, integer b, integer c, integer d) =
      condition1(a,b,c,d) || condition2(a,b,c,d) || 
      condition3(a,b,c,d) || condition4(a,b,c,d);
*/

/*@ lemma condition1_implies_result: 
      \forall integer a,b,c,d; 
      condition1(a,b,c,d) ==> result_condition(a,b,c,d);
    lemma condition2_implies_result: 
      \forall integer a,b,c,d; 
      condition2(a,b,c,d) ==> result_condition(a,b,c,d);
    lemma condition3_implies_result: 
      \forall integer a,b,c,d; 
      condition3(a,b,c,d) ==> result_condition(a,b,c,d);
    lemma condition4_implies_result: 
      \forall integer a,b,c,d; 
      condition4(a,b,c,d) ==> result_condition(a,b,c,d);
*/

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> result_condition(a,b,c,d);
*/
bool func(long a, long b, long c, long d) {
    // Variable declarations at top
    bool result;
    
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;
    
    if ((c - b == 0) && (a <= d)) {
        //@ assert condition1(a,b,c,d);
        //@ assert result_condition(a,b,c,d);
        result = true;
    } else if ((b - a == 0) && (c <= d)) {
        //@ assert condition2(a,b,c,d);
        //@ assert result_condition(a,b,c,d);
        result = true;
    } else if ((d - a == 0) && (b <= c)) {
        //@ assert condition3(a,b,c,d);
        //@ assert result_condition(a,b,c,d);
        result = true;
    } else if ((c - d == 0) && (a <= b)) {
        //@ assert condition4(a,b,c,d);
        //@ assert result_condition(a,b,c,d);
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
