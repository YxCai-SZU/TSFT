/*@
    predicate sorted{L}(int *arr, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1];
    
    predicate not_sorted{L}(int *arr, integer len) =
        \exists integer i; 0 <= i < len - 1 && arr[i] > arr[i + 1];
*/

/*@
    requires \valid(listval + (0 .. len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result == 1 ==> sorted(listval, len);
    ensures \result == 0 ==> not_sorted(listval, len);
*/
int is_sorted(int *listval, int len) {
    int i;
    
    if (len <= 1) {
        return 1;
    }
    
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i - 1 ==> listval[j] <= listval[j + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i - 1 < len - 1;
        if (listval[i] < listval[i - 1]) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
