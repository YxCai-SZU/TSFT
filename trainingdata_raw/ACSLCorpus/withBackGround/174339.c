/*@
    predicate strictly_increasing(int *arr, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];
*/

/*@
    requires len < 0x80000000;
    requires \valid(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == 1 <==> strictly_increasing(arr, len);
*/
int is_strictly_increasing(int *arr, int len) {
    int i;
    int result;
    
    if (len <= 1) {
        return 1;
    }
    
    i = 1;
    result = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i - 1 ==> arr[j] < arr[j + 1];
        loop invariant result == 1;
        loop assigns i, result;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i - 1 >= 0;
        
        if (arr[i] <= arr[i - 1]) {
            result = 0;
            break;
        }
        i = i + 1;
    }
    
    //@ assert result == 1 ==> strictly_increasing(arr, len);
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
