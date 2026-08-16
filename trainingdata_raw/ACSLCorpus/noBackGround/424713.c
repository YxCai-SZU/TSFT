/*@
    requires len > 0;
    requires \valid_read(arr + (0 .. len - 1));
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] < (arr)[i + 1]);
*/
int check_less(int *arr, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] < arr[j + 1];
        loop invariant len > 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len;
        if (arr[i] >= arr[i + 1]) {
            return 0;
        }
        i++;
    }
    return 1;
}

/*@
    requires len > 0;
    requires \valid_read(arr + (0 .. len - 1));
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] < (arr)[i + 1]);
*/
int check_less_spec(int *arr, int len) {
    return check_less(arr, len);
}
