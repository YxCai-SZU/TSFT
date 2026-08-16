// Generated C + ACSL

/*@
    requires \valid_read(arr + (0 .. arr_len - 1));
    requires arr_len >= 0;
    requires threshold >= 0;
    ensures 0 <= \result <= arr_len;
*/
int CountLessThan(int* arr, int arr_len, int threshold) {
    int count = 0;
    
    /*@
        loop invariant 0 <= i <= arr_len;
        loop invariant 0 <= count <= i;
        loop assigns i, count;
        loop variant arr_len - i;
    */
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] < threshold) {
            count++;
        }
    }
    
    return count;
}