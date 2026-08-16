/*@
    predicate is_square(integer n, integer result) = result == n * n;
    predicate is_small(integer n) = n < 1000;
    predicate is_safe_square(integer n, integer result) = 
        is_small(n) ==> is_square(n, result) && result < 1000000;
*/

/*@
    requires is_small(n);
    ensures is_safe_square(n, \result);
*/
unsigned int find_square_num(unsigned int n) {
    // Variable declarations at top of scope
    unsigned int result;
    
    //@ assert n < 1000;
    
    result = n * n;
    
    //@ assert result == n * n;
    
    return result;
}

int main() {
    return 0;
}
