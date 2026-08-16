/*@
predicate less_than(integer x, integer y) = x < y;

lemma nested_calc_lemma:
    \forall integer x, y;
        less_than(x, y) ==> x + 1 <= y + 2;
*/

/*@
    requires less_than(x, y);
    ensures \result == 1;
*/
int nested_calc(int x, int y)
{
    int intermediate;
    intermediate = x + 1;

    //@ assert x < y;
    //@ assert y > x;
    //@ assert y + 2 > x + 1;
    //@ assert y + 2 >= x + 1;
    //@ assert x + 1 <= y + 2;
    //@ assert x + 1 <= y + 2;
    //@ assert x + 1 == y + 2 || x + 1 < y + 2;
    //@ assert x + 1 <= y + 2;
    //@ assert x + 1 == y + 2 || x + 1 < y + 2;
    //@ assert x + 1 < y + 2;
    //@ assert x + 1 <= y + 2;
    //@ assert x + 1 == y + 2 || x + 1 < y + 2;
    //@ assert x + 1 < y + 2;
    //@ assert x + 1 <= y + 2;
    //@ assert x + 1 == y + 2 || x + 1 < y + 2;
    //@ assert x + 1 <= y + 2;

    return 1;
}

int main()
{
    return 0;
}
