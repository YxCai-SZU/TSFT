/*@
    predicate is_min(integer val, int* arr, integer len, integer idx) =
        \forall integer k; 0 <= k < idx ==> val <= arr[k];

    predicate min_exists(integer val, int* arr, integer len, integer idx) =
        \exists integer k; 0 <= k < idx && val == arr[k];

    logic integer min_val_logic(int* arr, integer len) =
        len > 0 ? arr[0] : 0;

    lemma min_val_lemma:
        \forall int* arr, integer len;
        len > 0 ==>
        \exists integer k; 0 <= k < len && min_val_logic(arr, len) == arr[k];
*/

/*@
    requires \valid(list1+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result <= list1[0];
    ensures \forall integer k; 0 <= k < len ==> \result <= list1[k];
    ensures \exists integer k; 0 <= k < len && \result == list1[k];
*/
int find_min_val(int* list1, int len) {
    int min_val;
    int i;
    
    min_val = list1[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer k; 0 <= k < i ==> min_val <= list1[k];
        loop invariant \exists integer k; 0 <= k < i && min_val == list1[k];
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len) {
        int val = list1[i];
        
        //@ assert val == list1[i];
        
        if (val < min_val) {
            min_val = val;
        }
        
        i = i + 1;
    }
    
    //@ assert \forall integer k; 0 <= k < len ==> min_val <= list1[k];
    return min_val;
}
