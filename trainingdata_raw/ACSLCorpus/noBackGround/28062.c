/*@
    requires len >= 0;
    requires len < 0x80000000;
    requires \valid(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (len)/2 ==> (arr)[i] == (arr)[(len) - 1 - i]);
 */
int is_palindromic(int *arr, int len) {
    int i = 0;
    //@ ghost int old_len = len;

    /*@
        loop invariant 0 <= i <= len/2;
        loop invariant len == old_len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] == arr[len - 1 - j];
        loop assigns i;
        loop variant len/2 - i;
     */
    while (i < len / 2) {
        //@ assert 0 <= i < len/2;
        if (arr[i] != arr[len - 1 - i]) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}
