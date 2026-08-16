/*@
    predicate X_in_range(integer X) = -40 <= X && X <= 40;
    predicate result_correct(integer X, integer result) =
        (X < 30 ==> result == 0) && (X >= 30 ==> result == 1);
*/

/*@
    requires X_in_range(X);
    ensures result_correct(X, \result);
*/
int func(long long X) {
    int result;
    long long i;
    
    result = 0;
    i = 0;
    
    /*@
        loop invariant X_in_range(X);
        loop invariant i >= 0;
        loop invariant i > 0 ==> result_correct(X, result);
        loop assigns result, i;
    */
    while (i < 100000) {
        if (X >= 30) {
            result = 1;
        } else {
            result = 0;
        }
        i += 1;
    }
    
    return result;
}
