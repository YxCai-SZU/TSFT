#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *arr, integer n) =
        n >= 1 && n <= 200000 &&
        \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000000;

    predicate vector_eq(int *v, int *v_a, integer len) =
        \forall integer k; 0 <= k < len ==> v[k] == v_a[k];
*/

/*@
    requires valid_array(v_a, n);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *v_a) {
    int v[200000];
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer k; 0 <= k < i ==> v[k] == v_a[k];
        loop assigns i, v[0..199999];
        loop variant n - i;
    */
    while (i < n) {
        v[i] = v_a[i];
        i++;
    }
    
    int last_val;
    bool has_last = false;
    int count = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant index > 0 ==> vector_eq(&v[0], v_a, index);
        loop invariant 0 <= count <= index;
        loop assigns index, last_val, has_last, count;
        loop variant n - index;
    */
    while (index < n) {
        int a = v[index];
        
        if (has_last) {
            if (last_val <= a) {
                last_val = a;
                count++;
            }
        } else {
            last_val = a;
            has_last = true;
            count++;
        }
        
        index++;
        //@ assert count <= n;
    }
    
    return count;
}
