/*@
    predicate positive_array(int *arr, integer len) =
        \forall integer j; 0 <= j < len ==> arr[j] > 0;

    predicate count_invariant(int *arr, integer len, integer k, integer i, integer cnt) =
        i <= len &&
        cnt <= i &&
        positive_array(arr, len) &&
        \forall integer j; 0 <= j < i ==> (arr[j] >= k ==> cnt > 0);
*/

/*@
    requires n > 0 && k > 0;
    requires \valid(h + (0 .. n-1));
    requires positive_array(h, n);
    ensures 0 <= \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result > 0);
*/
unsigned int func(unsigned int n, unsigned int k, int *h) {
    unsigned int count = 0;
    unsigned int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant positive_array(h, n);
        loop invariant \forall integer j; 0 <= j < i ==> (h[j] >= k ==> count > 0);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert positive_array(h, n);
        if (h[i] >= (int)k) {
            //@ assert h[i] >= k ==> count + 1 > 0;
            count++;
        }
        i++;
    }
    return count;
}
