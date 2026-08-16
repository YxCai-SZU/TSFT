#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((s_len) > 0 && \valid((s) + (0 .. (s_len)-1))) && ((t_len) > 0 && \valid((t) + (0 .. (t_len)-1)));
    assigns \nothing;
    ensures \result == 0;
*/
int calc_example_9(int *s, size_t s_len, int *t, size_t t_len) {
    //@ assert s_len > 0 && t_len > 0;
    
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= s_len;
        loop assigns i;
    */
    for (i = 0; i < s_len; i++) {
        //@ assert i < s_len;
    }
    
    //@ assert ((integer)(s_len)) + ((integer)(t_len)) == ((integer)(s_len)) + ((integer)(t_len));
    return 0;
}

/*@
    requires ((s_len) > 0 && \valid((s) + (0 .. (s_len)-1))) && ((t_len) > 0 && \valid((t) + (0 .. (t_len)-1)));
    assigns \nothing;
    ensures \result == 0;
*/
int lemma_seq_push(int *s, size_t s_len, int *t, size_t t_len) {
    //@ assert s_len > 0 && t_len > 0;
    
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= s_len;
        loop assigns i;
    */
    for (i = 0; i < s_len; i++) {
        //@ assert i < s_len;
    }
    
    //@ assert ((integer)(s_len) + 1) + (((integer)(t_len) > 0) ? (integer)(t_len) - 1 : 0) == ((integer)(s_len)) + ((integer)(t_len));
    return 0;
}

/*@
    requires ((s_len) > 0 && \valid((s) + (0 .. (s_len)-1))) && ((t_len) > 0 && \valid((t) + (0 .. (t_len)-1)));
    assigns \nothing;
    ensures \result == 0;
*/
int calc_example_10(int *s, size_t s_len, int *t, size_t t_len) {
    //@ assert s_len > 0 && t_len > 0;
    
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= s_len;
        loop assigns i;
    */
    for (i = 0; i < s_len; i++) {
        //@ assert i < s_len;
    }
    
    //@ assert ((integer)(s_len) + 1) + (((integer)(t_len) > 0) ? (integer)(t_len) - 1 : 0) == ((integer)(s_len)) + ((integer)(t_len));
    return 0;
}

/*@
    assigns \nothing;
*/
int main() {
    int s[] = {1, 2, 3};
    int t[] = {4, 5, 6};
    size_t s_len = 3;
    size_t t_len = 3;
    
    //@ assert ((s_len) > 0 && \valid((&s[0]) + (0 .. (s_len)-1)));
    //@ assert ((t_len) > 0 && \valid((&t[0]) + (0 .. (t_len)-1)));
    
    calc_example_9(&s[0], s_len, &t[0], t_len);
    lemma_seq_push(&s[0], s_len, &t[0], t_len);
    calc_example_10(&s[0], s_len, &t[0], t_len);
    
    return 0;
}
