/*@
    logic integer f(integer x) = x + 1;

    lemma f_increases:
        \forall integer x, y; x <= y ==> f(x) <= f(y);

    lemma even_f_increases:
        \forall integer i, j; i <= j && i % 2 == 0 && j % 2 == 0 ==> f(i) <= f(j);

    predicate g(integer i, integer j) = i <= j;

    lemma g_proves_f:
        \forall integer i, j; g(i, j) ==> f(i) <= f(j);
*/

/*@
    requires \true;
    ensures \forall integer i, j; i % 2 == 0 && j % 2 == 0 && i <= j ==> f(i) <= f(j);
*/
void test_even_f_increases()
{
    /*@ assert \forall integer i, j; i % 2 == 0 && j % 2 == 0 && i <= j ==> f(i) <= f(j); */
}

int main()
{
    return 0;
}
