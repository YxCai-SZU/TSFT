#include <stdbool.h>

/*@ predicate is_valid_k(integer k) = 1 <= k && k <= 100; */
/*@ predicate is_valid_x(integer x) = 1 <= x && x <= 100000; */
/*@ predicate is_valid_n(integer n) = 1 <= n && n <= 100000; */

/*@
    requires is_valid_k(k) && is_valid_x(x);
    ensures \result == (500 * k >= x);
*/
bool func(int k, int x)
{
    bool ans;
    ans = false;
    
    //@ assert is_valid_k(k) && is_valid_x(x);
    if (500 * k >= x) {
        ans = true;
    } else {
        ans = false;
    }
    
    //@ assert ans == (500 * k >= x);
    return ans;
}

/*@
    requires is_valid_k(k) && is_valid_n(n);
    ensures \result >= 0 && \result < k;
*/
int func1(int n, int k)
{
    int a;
    int b;
    
    a = n;
    
    /*@
        loop invariant 1 <= k && k <= 100;
        loop invariant 1 <= n && n <= 100000;
        loop invariant a >= 0 && a <= n;
        loop assigns a;
    */
    while (a >= k) {
        //@ assert a >= k;
        a -= k;
        //@ assert a >= 0;
    }
    
    /*@
        loop invariant 1 <= k && k <= 100;
        loop invariant 1 <= n && n <= 100000;
        loop invariant a < k;
        loop assigns a;
    */
    while (a < 0) {
        //@ assert a < 0;
        a += k;
        //@ assert a < k;
    }
    
    b = k - a;
    
    //@ assert a >= 0 && a < k;
    if (a < b) {
        //@ assert a >= 0 && a < k;
        return a;
    } else {
        //@ assert b >= 0 && b < k;
        return b;
    }
}
