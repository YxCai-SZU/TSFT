/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    logic integer sum(integer a, integer b, integer c) = a + b + c;

    lemma sum_range: \forall integer a, b, c;
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==> 
        1 <= sum(a, b, c) <= 300;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == (a + b + c >= 0);
*/
int func(int a, int b, int c) {
    // Variable declarations at scope top
    int result;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    
    //@ assert 1 <= a + b + c <= 300;
    
    result = 1;
    return result;
}
