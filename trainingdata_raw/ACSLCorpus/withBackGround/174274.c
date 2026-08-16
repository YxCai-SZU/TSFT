/*@
    predicate nonnegative_divisible(integer X) =
        0 <= X <= 100;

    lemma func_lemma: \forall integer X;
        nonnegative_divisible(X) ==>
        X / 5 == X / 5 + 0;
*/

/*@
    requires nonnegative_divisible(X);
    ensures \result == X / 5 + 0;
    assigns \nothing;
*/
int func(int X)
{
    int x;
    //@ assert X / 5 == X / 5;
    x = X / 5;
    //@ assert X / 5 == x;
    //@ assert x == x + 0;
    return x;
}
