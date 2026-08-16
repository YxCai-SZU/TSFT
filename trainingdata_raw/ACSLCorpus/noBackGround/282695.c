/*@
    requires \valid(arr + (0..len-1));
    requires ((len) > 0);
    ensures (\exists integer i; 0 <= i < (len) && (arr)[i] == (\result));
    assigns \nothing;
*/
int find_max_in_rotated_array(int* arr, int len) {
    int low;
    int high;
    int mid;
    
    low = 0;
    high = len - 1;
    
    /*@
        loop invariant 0 <= low <= high < len;
        loop invariant ((len) > 0);
        loop assigns low, high, mid;
        loop variant high - low;
    */
    while (low < high) {
        mid = low + (high - low) / 2;
        
        //@ assert 0 <= mid < len;
        
        if (arr[mid] > arr[high]) {
            //@ assert mid + 1 <= high;
            low = mid + 1;
        } else {
            //@ assert low <= mid;
            high = mid;
        }
    }
    
    //@ assert low == high;
    //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == (arr[high]));
    return arr[high];
}
