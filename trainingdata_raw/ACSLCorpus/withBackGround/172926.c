#include <stddef.h>

/*@ predicate is_valid_index(int i, int len) = 0 <= i < len; */
/*@ predicate is_valid_value(int val) = 1 <= val <= 1000000000; */
/*@ predicate element_exists(int val, int *arr, int len, int idx) = 
      is_valid_index(idx, len) && arr[idx] == val; */
/*@ predicate max_up_to(int max, int *arr, int bound) = 
      \forall int k; 0 <= k < bound ==> max >= arr[k]; */

/*@ lemma initial_conditions_maintained: 
      \forall int *v, int len, int i; 
      1 <= i <= len && 
      (\forall int j; is_valid_index(j, len) ==> is_valid_value(v[j])) 
      ==> (\forall int j; is_valid_index(j, len) ==> is_valid_value(v[j])); */

/*@ lemma existence_lemma: 
      \forall int *v, int len, int i, int max_val; 
      1 <= i <= len && 
      (\exists int j; is_valid_index(j, i) && max_val == v[j]) 
      ==> (\exists int j; is_valid_index(j, len) && max_val == v[j]); */

/*@ requires \valid(v+(0..len-1));
    requires len >= 1;
    requires \forall int i; 0 <= i < len ==> v[i] >= 1 && v[i] <= 1000000000;
    ensures \result >= 0;
    ensures \exists int i; 0 <= i < len && \result == v[i];
    assigns \nothing;
 */
int func(int *v, int len) {
    int max_val;
    size_t i;
    
    max_val = v[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant \forall int j; 0 <= j < len ==> v[j] >= 1 && v[j] <= 1000000000;
        loop invariant \exists int j; 0 <= j < i && max_val == v[j];
        loop invariant \forall int k; 0 <= k < i ==> max_val >= v[k];
        loop assigns max_val, i;
        loop variant len - i;
     */
    while (i < (size_t)len) {
        //@ assert \forall int j; 0 <= j < len ==> v[j] >= 1 && v[j] <= 1000000000;
        if (v[i] > max_val) {
            max_val = v[i];
        }
        i++;
    }
    
    //@ assert \exists int j; 0 <= j < len && max_val == v[j];
    return max_val;
}

int main() {
    return 0;
}
