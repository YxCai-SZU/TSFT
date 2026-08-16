#include <stddef.h>
#include <stdbool.h>

/*@
    predicate contains(int *arr, integer len, int elem) =
        \exists integer idx; 0 <= idx < len && arr[idx] == elem;

    logic integer vector_len{L}(int *arr, integer len) = len;

    lemma len_non_negative: \forall int *arr, integer len; len >= 0 ==> 0 <= vector_len(arr, len);
*/

/*@
    requires 0 <= vlen < 0x80000000;
    requires \valid(v + (0 .. vlen-1));
    requires \valid(result + (0 .. vlen-1));
    requires \valid(result_len);
    assigns *result_len, result[0 .. vlen-1];
    ensures \result == 0 || \result == 1;
    ensures *result_len <= vlen;
    ensures \forall integer k; 0 <= k < *result_len ==> result[k] == e;
    ensures \forall integer k; 0 <= k < *result_len ==> contains(v, vlen, result[k]);
*/
int remove_all_not_equal(int *v, size_t vlen, int e, int *result, size_t *result_len) {
    size_t i = 0;
    size_t rlen = 0;
    
    /*@
        loop invariant 0 <= i <= vlen;
        loop invariant 0 <= rlen <= i;
        loop invariant \forall integer k; 0 <= k < rlen ==> result[k] == e;
        loop invariant \forall integer k; 0 <= k < rlen ==> contains(v, vlen, result[k]);
        loop assigns i, rlen, result[0 .. vlen-1];
        loop variant vlen - i;
    */
    while (i < vlen) {
        //@ assert 0 <= i < vlen;
        if (v[i] == e) {
            //@ assert v[i] == e;
            result[rlen] = v[i];
            //@ assert result[rlen] == e;
            rlen = rlen + 1;
        }
        i = i + 1;
    }
    
    *result_len = rlen;
    
    //@ assert rlen <= vlen;
    //@ assert \forall integer k; 0 <= k < rlen ==> result[k] == e;
    //@ assert \forall integer k; 0 <= k < rlen ==> contains(v, vlen, result[k]);
    return 0;
}
