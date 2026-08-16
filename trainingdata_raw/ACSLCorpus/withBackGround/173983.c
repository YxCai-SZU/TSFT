#include <limits.h>

/*@
    predicate bounds(integer a, integer b) =
        -100 <= a <= 100 && -100 <= b <= 100;
    
    logic integer sum_val(integer a, integer b) = a + b;
    logic integer diff_val(integer a, integer b) = a - b;
    logic integer prod_val(integer a, integer b) = a * b;
    
    lemma product_bounds:
        \forall integer a, b;
            bounds(a, b) ==> -10000 <= prod_val(a, b) <= 10000;
    
    lemma sum_ge_self:
        \forall integer a, b, s;
            s == sum_val(a, b) && bounds(a, b) ==> s >= sum_val(a, b);
    
    lemma diff_ge_self:
        \forall integer a, b, d;
            d == diff_val(a, b) && bounds(a, b) ==> d >= diff_val(a, b);
    
    lemma prod_ge_self:
        \forall integer a, b, p;
            p == prod_val(a, b) && bounds(a, b) ==> p >= prod_val(a, b);
*/

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
*/
int func(int a, int b)
{
    int sum;
    int diff;
    int prod;
    int res;
    
    //@ assert bounds(a, b);
    
    sum = a + b;
    //@ assert sum == sum_val(a, b);
    
    diff = a - b;
    //@ assert diff == diff_val(a, b);
    
    //@ assert -10000 <= a * b <= 10000;
    prod = a * b;
    //@ assert prod == prod_val(a, b);
    
    //@ assert sum >= sum_val(a, b);
    //@ assert diff >= diff_val(a, b);
    //@ assert prod >= prod_val(a, b);
    
    if (sum > diff && sum > prod) {
        res = sum;
    } else if (diff > prod) {
        res = diff;
    } else {
        res = prod;
    }
    
    //@ assert res == sum_val(a, b) || res == diff_val(a, b) || res == prod_val(a, b);
    //@ assert res >= sum_val(a, b);
    //@ assert res >= diff_val(a, b);
    //@ assert res >= prod_val(a, b);
    
    return res;
}
