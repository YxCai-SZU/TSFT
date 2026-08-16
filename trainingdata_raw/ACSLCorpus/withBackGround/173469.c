/*@
    predicate equal(integer x, integer y) = x == y;

    lemma lemma_1: \forall integer x, y; equal(x, y) ==> x * 2 == y * 2;
    lemma lemma_2: \forall integer x, y; equal(x, y) ==> x * 2 + 1 == y * 2 + 1;
    lemma lemma_3: \forall integer x, y; equal(x, y) ==> x * 3 == y * 3;
    lemma lemma_4: \forall integer x, y; equal(x, y) ==> x * 3 + 1 == y * 3 + 1;
    lemma lemma_5: \forall integer x, y; equal(x, y) ==> x * 4 == y * 4;
    lemma lemma_6: \forall integer x, y; equal(x, y) ==> x * 4 + 1 == y * 4 + 1;
*/

/*@
    requires x == 5;
    ensures \result == 11;
*/
int calc_example_1(int x)
{
    //@ assert x == 5;
    //@ assert x * 2 + 1 == 11;
    return x * 2 + 1;
}

/*@
    requires x == 5;
    ensures \result == 16;
*/
int calc_example_2(int x)
{
    //@ assert x == 5;
    //@ assert x * 3 + 1 == 16;
    return x * 3 + 1;
}

/*@
    requires x == 5;
    ensures \result == 21;
*/
int calc_example_3(int x)
{
    //@ assert x == 5;
    //@ assert x * 4 + 1 == 21;
    return x * 4 + 1;
}

int main()
{
    return 0;
}
