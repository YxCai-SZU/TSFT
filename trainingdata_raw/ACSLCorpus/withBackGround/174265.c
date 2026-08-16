/*@
    predicate exists_min(int *arr, integer len, integer val) =
        \exists integer i; 0 <= i < len && arr[i] == val;

    predicate forall_min(int *arr, integer len, integer val) =
        \forall integer i; 0 <= i < len ==> val <= arr[i];

    lemma loop_invariant_maintained:
        \forall int *arr, integer len, integer i, integer min_val;
        1 <= i <= len && len > 0 &&
        exists_min(arr, i, min_val) && forall_min(arr, i, min_val) ==>
        (i < len ==> (
            (arr[i] < min_val ==> 
                exists_min(arr, i+1, arr[i]) && forall_min(arr, i+1, arr[i])) &&
            (arr[i] >= min_val ==> 
                exists_min(arr, i+1, min_val) && forall_min(arr, i+1, min_val))
        ));
*/

/*@
    requires \valid(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures exists_min(arr, len, \result);
    ensures forall_min(arr, len, \result);
*/
int min_element(int *arr, int len) {
    int min_val;
    int i;

    min_val = arr[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= len;
        loop invariant exists_min(arr, i, min_val);
        loop invariant forall_min(arr, i, min_val);
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert exists_min(arr, i, min_val);
        
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i = i + 1;
    }
    
    //@ assert exists_min(arr, len, min_val);
    return min_val;
}

int main() {
    return 0;
}
