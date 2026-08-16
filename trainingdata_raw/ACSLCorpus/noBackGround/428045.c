/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len >= 1;
    requires \forall integer i; 0 <= i < len ==> arr[i] == 0 || arr[i] == 1;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < len ==> arr[i] == 0 || arr[i] == 1);
    assigns \nothing;
*/
int func(const int *arr, int len) {
    int i;
    i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (((arr)[j]) == 0 || ((arr)[j]) == 1));
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert ((arr[i]) == 0 || (arr[i]) == 1);
        if (arr[i] != 0 && arr[i] != 1) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}
