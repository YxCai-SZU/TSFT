#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer low, integer high) =
        low <= a && a <= high;

    logic integer safe_sum(integer a, integer b) = a + b;
    predicate sum_ge_c(integer a, integer b, integer c) = safe_sum(a, b) >= c;
*/

/*@
    requires valid_range(a, 1, 5000);
    requires valid_range(b, 1, 5000);
    requires valid_range(c, 1, 10000);
    ensures \result == 1 <==> sum_ge_c(a, b, c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    bool ans;
    
    sum = a + b;
    ans = sum >= c;
    return ans;
}

/*@
    logic integer safe_diff(integer a, integer b, integer c) =
        safe_sum(a, b) > c ? safe_sum(a, b) - c : 0;

    lemma diff_nonnegative:
        \forall integer a, b, c;
            valid_range(a, 1, 5000) && valid_range(b, 1, 5000) && valid_range(c, 1, 10000) ==>
            safe_diff(a, b, c) >= 0;
*/

/*@
    requires valid_range(a, 1, 5000);
    requires valid_range(b, 1, 5000);
    requires valid_range(c, 1, 10000);
    ensures \result == safe_diff(a, b, c);
    ensures \result >= 0;
*/
int func2(int a, int b, int c)
{
    int sum;
    int ans;
    
    sum = a + b;
    //@ assert valid_range(sum, 2, 10000);
    
    if (sum > c) {
        ans = sum - c;
        //@ assert ans == safe_diff(a, b, c);
    } else {
        ans = 0;
        //@ assert ans == safe_diff(a, b, c);
    }
    
    return ans;
}

/*@
    requires valid_range(a, 1, 5000);
    requires valid_range(b, 1, 5000);
    requires valid_range(c, 1, 10000);
    ensures \result == safe_diff(a, b, c);
    ensures \result >= 0;
*/
int func3(int a, int b, int c)
{
    int sum;
    int ans;
    
    sum = a + b;
    //@ assert valid_range(sum, 2, 10000);
    
    if (sum > c) {
        ans = sum - c;
        //@ assert ans == safe_diff(a, b, c);
    } else {
        ans = 0;
        //@ assert ans == safe_diff(a, b, c);
    }
    
    return ans;
}
