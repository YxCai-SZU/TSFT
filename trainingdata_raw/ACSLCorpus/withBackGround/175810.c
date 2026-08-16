/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 100;

    logic integer odd_count(integer i) = (i - 1 + 1) / 2;

    lemma count_bound: \forall integer n, integer i;
        is_valid_range(n) && 1 <= i && i <= n + 1 && i > 1 ==> 
        odd_count(i) <= (n + 1) / 2;
*/

/*@
    requires is_valid_range(n);
    ensures \result == (n + 1) / 2;
    assigns \nothing;
*/
int func(int n) {
    int count;
    int i;
    
    count = 0;
    i = 1;
    
    /*@
        loop invariant 1 <= i && i <= n + 1;
        loop invariant count == odd_count(i);
        loop invariant i > 1 ==> count <= (n + 1) / 2;
        loop assigns count, i;
        loop variant n - i + 1;
    */
    while (i <= n) {
        //@ assert count == odd_count(i);
        
        if (i % 2 == 1) {
            count += 1;
        }
        i += 1;
    }
    
    //@ assert count == (n + 1) / 2;
    return count;
}
