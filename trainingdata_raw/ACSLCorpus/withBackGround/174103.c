/*@
    predicate x_in_range(integer x) = 1 <= x && x <= 100;
    predicate y_in_range(integer y) = 1 <= y && y <= 100;
    predicate sum_in_range(integer x, integer y) = 2 <= x + y && x + y <= 200;

    lemma func_lemma:
        \forall integer x, y;
            x_in_range(x) && y_in_range(y) ==> sum_in_range(x, y);
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result <= 200;
*/
int func(int x, int y)
{
    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    //@ assert 2 <= x + y && x + y <= 200;
    //@ assert x + y <= 200;
    return x + y;
}

int main()
{
    return 0;
}
