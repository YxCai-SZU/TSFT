/*@
    requires n > 0;
    requires \valid(list1+(0..n-1)) && \valid(list2+(0..n-1));
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int count_elements(int *list1, int *list2, int n) {
    int count = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer k; 0 <= k < i ==> 
            (list1[k] != list2[k] ==> count > 0);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        if (list1[i] != list2[i]) {
            //@ assert list1[i] != list2[i];
            count++;
        }
        i++;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
