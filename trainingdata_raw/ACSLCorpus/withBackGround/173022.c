/*@
    predicate in_range(integer x) = -1000 <= x <= 1000;
    predicate product_in_range(integer x, integer y) = -1000000 <= x * y <= 1000000;
    predicate is_valid_product(integer res, integer a, integer b, integer c, integer d) =
        res == a * b || res == a * c || res == a * d ||
        res == b * c || res == b * d || res == c * d;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures is_valid_product(\result, a, b, c, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    //@ assert product_in_range(a, b);
    //@ assert product_in_range(a, c);
    //@ assert product_in_range(a, d);
    //@ assert product_in_range(b, c);
    //@ assert product_in_range(b, d);
    //@ assert product_in_range(c, d);
    
    int max_val;
    int temp_val;
    
    max_val = a * b;
    temp_val = a * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    temp_val = c * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert is_valid_product(max_val, a, b, c, d);
    return max_val;
}
