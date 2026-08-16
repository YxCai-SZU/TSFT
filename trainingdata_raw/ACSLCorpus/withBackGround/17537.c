/*@
predicate seq_eq{L}(char *a, integer a_len, char *b, integer b_len) =
    a_len == b_len &&
    \forall integer i; 0 <= i < a_len ==> \at(a[i], L) == \at(b[i], L);

lemma transitivity:
    \forall char *t, *p, *f;
    \forall integer t_len, p_len, f_len;
    seq_eq(t, t_len, p, p_len) ==>
    seq_eq(p, p_len, f, f_len) ==>
    seq_eq(t, t_len, f, f_len);
*/

/*@
requires seq_eq(text, text_len, pledge, pledge_len);
requires seq_eq(pledge, pledge_len, proof, proof_len);
ensures seq_eq(text, text_len, proof, proof_len);
*/
void assert_eq_pledge_proof(char *text, int text_len,
                            char *pledge, int pledge_len,
                            char *proof, int proof_len)
{
    //@ assert seq_eq(text, text_len, pledge, pledge_len);
    //@ assert seq_eq(pledge, pledge_len, proof, proof_len);
    //@ assert seq_eq(text, text_len, proof, proof_len);
}

int main() {
    return 0;
}
