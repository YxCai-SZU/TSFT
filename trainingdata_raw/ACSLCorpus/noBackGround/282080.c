/*@
requires x > 0;
ensures \result == 1;
assigns \nothing;
*/
int g(int x) {
    //@ assert x > 0;
    return 1;
}

/*@
requires i > 0;
ensures \result == 1;
assigns \nothing;
*/
int lemma_g_positive_wrapper(int i) {
    //@ assert i > 0;
    return g(i);
}

/*@
ensures \result == 1;
assigns \nothing;
*/
int prove_forall_wrapper() {
    int x = 1;
    //@ assert x > 0;
    return g(x);
}

/*@
requires i > 0;
ensures \result == 1;
assigns \nothing;
*/
int lemma_q_proves_g_wrapper(int i) {
    //@ assert i > 0;
    return g(i);
}

/*@
requires i > 0;
ensures \result == 1;
assigns \nothing;
*/
int choose_q_helper_wrapper(int i) {
    //@ assert i > 0;
    return lemma_q_proves_g_wrapper(i);
}

int main() {
    int result;
    
    result = g(5);
    //@ assert result == 1;
    
    result = lemma_g_positive_wrapper(3);
    //@ assert result == 1;
    
    result = prove_forall_wrapper();
    //@ assert result == 1;
    
    result = lemma_q_proves_g_wrapper(7);
    //@ assert result == 1;
    
    result = choose_q_helper_wrapper(9);
    //@ assert result == 1;
    
    return 0;
}
