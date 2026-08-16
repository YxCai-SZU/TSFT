/*@
    requires n > 0 && k > 0;
    requires \valid(h + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (h)[i] > 0);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int k, unsigned int *h) {
    unsigned int num = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= num <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (h)[i] > 0);
        loop invariant \forall integer j; 0 <= j < i ==> (h[j] >= k ==> num > 0);
        loop assigns i, num;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert num <= i;
        if (h[i] >= k) {
            num = num + 1;
        }
        i = i + 1;
    }
    //@ assert num <= n;
    return num;
}
