/*@
    predicate is_nonnegative(integer x) = x >= 0;

    lemma abs_nonlinear_lemma:
        \forall integer a; 0 <= a <= 10 ==> a * a >= 0;

    lemma pos_lemma:
        \forall integer a; 0 <= a <= 10 ==> a >= 0;
*/

/*@
    requires 0 <= a <= 10;
    ensures \result == a;
    ensures is_nonnegative(\result);
*/
int abs_nonlinear(int a)
{
    //@ assert 0 <= a <= 10;
    //@ assert a >= 0;
    return a;
}

/*@
    requires 0 <= a <= 10;
    ensures \result == a;
    ensures is_nonnegative(\result);
*/
int pos(int a)
{
    //@ assert 0 <= a <= 10;
    //@ assert a >= 0;
    return a;
}

int main()
{
    return 0;
}
