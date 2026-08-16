#include <stddef.h>

/*@
    predicate is_non_empty_seq{L}(int *v, integer len) = len > 0;
    predicate is_non_negative_len{L}(int *v, integer len) = len >= 0;
*/

/*@
    requires \valid(v+(0..len-1));
    requires is_non_empty_seq(v, len);
    ensures is_non_negative_len(v, len);
    assigns \nothing;
*/
void calc_vector_example_1(int *v, int len) {
    //@ assert len > 0;
    //@ assert len >= 0;
}

/*@
    lemma test_calc_vector_example_1:
        \forall int *v, integer len;
            len == 5 ==> is_non_empty_seq(v, len) && is_non_negative_len(v, len);
*/

int main() {
    int v[5];
    int i;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> v[j] == j * 10;
        loop assigns i, v[0..4];
        loop variant 5 - i;
    */
    for (i = 0; i < 5; i++) {
        v[i] = i * 10;
    }
    
    //@ assert \forall integer j; 0 <= j < 5 ==> v[j] == j * 10;
    calc_vector_example_1(v, 5);
    return 0;
}
