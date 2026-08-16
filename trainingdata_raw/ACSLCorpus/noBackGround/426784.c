/*@
    requires s_len < 0x80000000;
    ensures \result == s_len;
    assigns \nothing;
*/
int lemma_len_eq(int s_len)
{
    //@ assert ((s_len) == (s_len));
    return s_len;
}

/*@
    requires s_len < 0x80000000;
    ensures \result == s_len;
    assigns \nothing;
*/
int calc_example_5(int s_len)
{
    int tmp;
    
    //@ assert ((s_len) == (s_len));
    tmp = lemma_len_eq(s_len);
    //@ assert ((tmp) == (s_len));
    return tmp;
}

int main()
{
    return 0;
}
