/*@
    logic integer f(integer x) = x + 1;

    lemma f_increases: \forall integer x, y; x <= y ==> f(x) <= f(y);
    lemma f_flex_left: \forall integer x; x <= 3 ==> f(x) <= 4;
    lemma f_flex_right: \forall integer x; x >= 3 ==> f(x) >= 4;
*/

/*@
    requires x <= y;
    ensures \result == 1;
*/
int lemma_f_increases(int x, int y)
{
    //@ assert x <= y;
    //@ assert f(x) <= f(y);
    return 1;
}

/*@
    requires x <= 3;
    ensures \result == 1;
*/
int lemma_f_flex_left(int x)
{
    //@ assert x <= 3;
    //@ assert f(x) <= 4;
    return 1;
}

/*@
    requires x >= 3;
    ensures \result == 1;
*/
int lemma_f_flex_right(int x)
{
    //@ assert x >= 3;
    //@ assert f(x) >= 4;
    return 1;
}

/*@
    ensures \result == 1;
*/
int establish_forall()
{
    int x;
    int y;
    
    //@ assert \forall integer x, y; x <= y ==> f(x) <= f(y);
    return 1;
}

int main()
{
    return 0;
}
