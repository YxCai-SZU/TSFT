/*@
    predicate is_non_zero_positive(integer value) =
        value > 0 && value <= 10;
*/

/*@
    lemma non_zero_positive_lemma:
        \forall integer x;
            x > 0 ==> is_non_zero_positive(5);
*/

/*@
    requires x > 0;
    ensures \result > 0 && \result <= 10;
    assigns \nothing;
*/
int non_zero_positive(int x)
{
    int ret;
    //@ assert x > 0;
    ret = 5;
    //@ assert ret > 0 && ret <= 10;
    return ret;
}

int main(void)
{
    int x;
    int r;
    
    x = 5;
    //@ assert x > 0;
    r = non_zero_positive(x);
    //@ assert r > 0 && r <= 10;
    return 0;
}
