/*@
    predicate is_odd(integer a, integer b) = (a * b) % 2 != 0;
*/

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == 1 <==> is_odd(a, b);
    ensures \result == 0 <==> !is_odd(a, b);
*/
int input_tuple(unsigned long long a, unsigned long long b) {
    unsigned long long product;
    int result;
    
    product = a * b;
    
    if (product % 2 == 0) {
        //@ assert product % 2 == 0;
        result = 0;
    } else {
        //@ assert product % 2 != 0;
        result = 1;
    }
    
    return result;
}
