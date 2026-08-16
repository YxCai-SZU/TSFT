/*@
    predicate greater_than_threshold{L}(int *s, integer len, integer threshold) =
        \forall integer i; 0 <= i < len ==> s[i] > threshold;
*/

/*@
    requires len > 0;
    requires greater_than_threshold(list, len, threshold);
    ensures \result == len;
    assigns \nothing;
*/
unsigned int count_greater_than_threshold(const int *list, unsigned int len, int threshold) {
    unsigned int count = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count == i;
        loop invariant greater_than_threshold(list, len, threshold);
        loop invariant \forall integer j; 0 <= j < i ==> list[j] > threshold;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert list[i] > threshold;
        count += 1;
        i += 1;
    }
    
    return count;
}
