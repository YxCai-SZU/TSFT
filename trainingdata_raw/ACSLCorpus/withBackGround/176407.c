#include <limits.h>

/*@ predicate a_lt_b(integer a, integer b) = a < b;
    predicate b_lt_c(integer b, integer c) = b < c;
    predicate result_condition(integer a, integer b, integer c) = 
        a < b && b < c;
*/

/*@
    requires a > INT_MIN && b > INT_MIN && c > INT_MIN;
    requires a < INT_MAX && b < INT_MAX && c < INT_MAX;
    ensures \result == (a < b && b < c);
*/
int func(int a, int b, int c) {
    int a_lt_b;
    int b_lt_c;
    int sum;
    
    a_lt_b = (a < b) ? 1 : 0;
    b_lt_c = (b < c) ? 1 : 0;
    
    //@ assert a_lt_b == 0 || a_lt_b == 1;
    //@ assert b_lt_c == 0 || b_lt_c == 1;
    
    sum = a_lt_b + b_lt_c;
    
    //@ assert sum >= 0 && sum <= 2;
    
    return sum == 2;
}
