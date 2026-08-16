#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_vec_deque{L}(int16_t *arr, size_t len, size_t cap) =
        len <= cap &&
        \valid(arr + (0 .. cap-1));

    logic integer seq_len{L}(int16_t *arr, size_t len) = len;

    logic integer seq_get{L}(int16_t *arr, size_t len, integer i) =
        (0 <= i < len) ? arr[i] : 0;

    logic integer seq_last{L}(int16_t *arr, size_t len) =
        (len > 0) ? arr[len-1] : 0;

    logic integer seq_push{L}(int16_t *arr, size_t len, integer e) =
        len + 1;

    predicate seq_eq_push{L}(int16_t *arr1, size_t len1, int16_t *arr2, size_t len2, integer e) =
        len1 == len2 + 1 &&
        (\forall integer i; 0 <= i < len2 ==> arr1[i] == arr2[i]) &&
        arr1[len2] == e;

    predicate seq_eq_push_twice{L}(int16_t *arr1, size_t len1, int16_t *arr2, size_t len2, integer e1, integer e2) =
        len1 == len2 + 2 &&
        (\forall integer i; 0 <= i < len2 ==> arr1[i] == arr2[i]) &&
        arr1[len2] == e1 &&
        arr1[len2+1] == e2;
*/

typedef struct {
    int16_t *data;
    size_t length;
    size_t capacity;
} VecDeque;

/*@
    requires valid_vec_deque(v->data, v->length, v->capacity);
    requires v->capacity >= 2;
    ensures valid_vec_deque(v->data, v->length, v->capacity);
    ensures seq_len(v->data, v->length) == 2;
    ensures seq_get(v->data, v->length, 0) == 3;
    ensures seq_get(v->data, v->length, 1) == 6;
    assigns v->length, v->data[0], v->data[1];
*/
void set_to_three_and_six(VecDeque *v) {
    //@ ghost size_t old_len = v->length;
    //@ ghost int16_t *old_data = v->data;
    
    v->length = 0;
    
    //@ assert seq_len(v->data, v->length) == 0;
    
    v->data[0] = 3;
    v->length = 1;
    
    //@ assert seq_len(v->data, v->length) == 1;
    
    v->data[1] = 6;
    v->length = 2;
    
    //@ assert seq_len(v->data, v->length) == 2;
}

/*@
    lemma vec_deque_push:
        \forall VecDeque v, VecDeque oldv, integer e;
        seq_eq_push(v.data, v.length, oldv.data, oldv.length, e) ==>
        (\forall integer i; 0 <= i < oldv.length ==> seq_get(v.data, v.length, i) == seq_get(oldv.data, oldv.length, i)) &&
        seq_last(v.data, v.length) == e;
*/

/*@
    lemma vec_deque_push_twice:
        \forall VecDeque v, VecDeque oldv, integer e1, integer e2;
        seq_eq_push_twice(v.data, v.length, oldv.data, oldv.length, e1, e2) ==>
        (\forall integer i; 0 <= i < oldv.length ==> seq_get(v.data, v.length, i) == seq_get(oldv.data, oldv.length, i)) &&
        seq_get(v.data, v.length, oldv.length) == e1 &&
        seq_get(v.data, v.length, oldv.length + 1) == e2;
*/

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
