#include <limits.h>

/*@ predicate a_in_range(integer a) = -100 <= a <= 100;
    predicate b_in_range(integer b) = -100 <= b <= 100;
    predicate c_in_range(integer c) = -100 <= c <= 100;
    predicate all_in_range(integer a, integer b, integer c) = 
        a_in_range(a) && b_in_range(b) && c_in_range(c);
    
    predicate res_case1(integer res, integer a, integer b, integer c) = 
        res == 1 && a == b && b == c;
    predicate res_case2(integer res, integer a, integer b, integer c) = 
        res == 2 && a == b && a != c;
    predicate res_case3(integer res, integer a, integer b, integer c) = 
        res == 3 && a == c && a != b;
    predicate res_case4(integer res, integer a, integer b, integer c) = 
        res == 4 && b == c && a != b;
    predicate res_case5(integer res, integer a, integer b, integer c) = 
        res == 5 && a != b && b != c && a != c;
    
    predicate valid_result(integer res, integer a, integer b, integer c) = 
        res_case1(res, a, b, c) || res_case2(res, a, b, c) || 
        res_case3(res, a, b, c) || res_case4(res, a, b, c) || 
        res_case5(res, a, b, c);
*/

/*@
    requires all_in_range(a, b, c);
    ensures valid_result(\result, a, b, c);
*/
int func(int a, int b, int c) {
    int ans = 0;
    
    if (a == b && b == c) {
        ans = 1;
        //@ assert res_case1(ans, a, b, c);
    } else if (a != b && b != c && c != a) {
        ans = 5;
        //@ assert res_case5(ans, a, b, c);
    } else {
        if (a == b) {
            ans = 2;
            //@ assert res_case2(ans, a, b, c);
        } else if (a == c) {
            ans = 3;
            //@ assert res_case3(ans, a, b, c);
        } else if (b == c) {
            ans = 4;
            //@ assert res_case4(ans, a, b, c);
        }
    }
    
    //@ assert valid_result(ans, a, b, c);
    return ans;
}
