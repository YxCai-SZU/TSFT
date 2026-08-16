/*@
    requires n >= 0;
    requires \valid_read(a + (0 .. n-1));
    ensures ((\result) >= 0 && (\result) <= (n) &&
        \forall integer i; 0 <= i < (n) ==> ((a)[i] == (k) ? (\result) > 0 : (\result) >= 0));
    assigns \nothing;
*/
unsigned int search_range(const int *a, int n, int k) {
    unsigned int count = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        (count) >= 0 &&
        (count) <= (i) &&
        \forall integer j; 0 <= j < (i) ==> ((a)[j] == (k) ? (count) > 0 : (count) >= 0));
        loop assigns i, count;
        loop variant (unsigned int)n - i;
    */
    while (i < (unsigned int)n) {
        //@ assert (0 <= (i) <= (n) &&         (count) >= 0 &&         (count) <= (i) &&         \forall integer j; 0 <= j < (i) ==> ((a)[j] == (k) ? (count) > 0 : (count) >= 0));
        if (a[i] == k) {
            count++;
        }
        i++;
    }
    return count;
}
