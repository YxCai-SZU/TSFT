/*@
    predicate in_range(integer x) = -100 <= x && x <= 100;
    predicate result_in_range(integer x) = -10000 <= x && x <= 10000;
    predicate valid_result(integer a, integer b, integer res) = 
        res == a + b || res == a - b || res == a * b;

    lemma product_bounds: \forall integer a, b; 
        in_range(a) && in_range(b) ==> 
        a * b >= -10000 && a * b <= 10000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures valid_result(a, b, \result);
    ensures result_in_range(\result);
    assigns \nothing;
*/
int func(int a, int b) {
    int sum;
    int diff;
    int prod;
    int max_val;

    //@ assert in_range(a) && in_range(b);
    
    sum = a + b;
    diff = a - b;
    prod = a * b;
    
    //@ assert product_bounds: a * b >= -10000 && a * b <= 10000;
    
    max_val = sum;
    
    if (diff > max_val) {
        max_val = diff;
    }
    
    if (prod > max_val) {
        max_val = prod;
    }
    
    //@ assert max_val == sum || max_val == diff || max_val == prod;
    
    return max_val;
}
