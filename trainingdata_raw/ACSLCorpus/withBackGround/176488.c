/*@
    predicate sorted{L}(int *arr, integer len) =
        \forall integer i; 1 <= i < len ==> arr[i-1] <= arr[i];

    lemma sorted_implies_element:
        \forall int *arr, integer len, integer i;
            sorted(arr, len) && 1 <= i < len ==> arr[i-1] <= arr[i];
*/

/*@
    requires \valid(a+(0..len-1));
    requires \forall integer i; 1 <= i < len ==> a[i-1] <= a[i];
    ensures \result == 1;
*/
int func(int *a, int len) {
    int result;
    //@ assert sorted(a, len);
    result = 1;
    return result;
}
