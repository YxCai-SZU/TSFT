/*@
predicate is_positive(integer x) = x > 0;

lemma n_plus_one_gt_three: \forall integer n; n > 2 ==> n + 1 > 3;
*/

/*@
requires n > 2;
ensures \result > 3;
assigns \nothing;
*/
int example_6(int n)
{
    //@ assert n > 2;
    //@ assert n + 1 > 3;
    return n + 1;
}

int main()
{
    int n = 3;
    int result = example_6(n);
    //@ assert result > 3;
    return 0;
}
