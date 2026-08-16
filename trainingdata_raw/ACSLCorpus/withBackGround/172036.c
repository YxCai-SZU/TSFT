#include <stdbool.h>
#include <stddef.h>

/*@
    predicate all_greater_than_threshold(int *v, integer len, integer threshold) =
        \forall integer i; 0 <= i < len ==> v[i] > threshold;

    predicate all_less_than_threshold(int *v, integer len, integer threshold) =
        \forall integer i; 0 <= i < len ==> v[i] < threshold;

    predicate all_greater_than_or_equal_threshold(int *v, integer len, integer threshold) =
        \forall integer i; 0 <= i < len ==> v[i] >= threshold;

    predicate all_less_than_or_equal_threshold(int *v, integer len, integer threshold) =
        \forall integer i; 0 <= i < len ==> v[i] <= threshold;

    predicate all_within_range(int *v, integer len, integer min_value, integer max_value) =
        \forall integer i; 0 <= i < len ==> v[i] >= min_value && v[i] <= max_value;
*/

/*@
    requires len > 0;
    requires \valid_read(v + (0 .. len-1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && v[i] == \result;
    ensures \forall integer j; 0 <= j < len ==> v[j] <= \result;
*/
int find_max_num(int *v, size_t len) {
    int max_num;
    size_t i;
    
    max_num = v[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer j; 0 <= j < i && v[j] == max_num;
        loop invariant \forall integer k; 0 <= k < i ==> v[k] <= max_num;
        loop assigns max_num, i;
        loop variant len - i;
    */
    while (i < len) {
        if (v[i] > max_num) {
            max_num = v[i];
        }
        i++;
    }
    
    return max_num;
}

/*@
    lemma max_exists_in_array:
        \forall int *v, integer len, integer max_val;
        len > 0 && \valid_read(v + (0 .. len-1)) &&
        (\forall integer j; 0 <= j < len ==> v[j] <= max_val) &&
        (\exists integer i; 0 <= i < len && v[i] == max_val) ==>
        \true;
*/

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
