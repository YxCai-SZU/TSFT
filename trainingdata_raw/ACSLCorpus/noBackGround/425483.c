/*@
    requires len > 0;
    ensures ((len) == (len) &&
        \forall integer i; 0 <= i < (len) ==> (seq)[i] == (seq)[i]);
*/
void lemma_sequence_id(unsigned int *seq, int len)
{
    //@ assert ((len) == (len));
}

/*@
    requires 0 <= idx && idx <= len;
    ensures ((len + 1) == (((len) + 1)));
*/
void lemma_insert(unsigned int *seq, int len, unsigned int elem, int idx)
{
    //@ assert ((len) + 1) == len + 1;
}

/*@
    requires 0 <= idx && idx < len;
    ensures ((len - 1) == (((len) - 1)));
*/
void lemma_remove(unsigned int *seq, int len, int idx)
{
    //@ assert ((len) - 1) == len - 1;
}

/*@
    requires len >= 2;
    ensures ((len) == (len) &&
        \forall integer i; 0 <= i < (len) ==> (seq)[i] == (seq)[i]);
*/
void calc_example(unsigned int *seq, int len)
{
    //@ assert ((len) == (len));
    lemma_sequence_id(seq, len);
    //@ assert ((len) == (len) &&         \forall integer i; 0 <= i < (len) ==> (seq)[i] == (seq)[i]);
}

int main()
{
    return 0;
}
