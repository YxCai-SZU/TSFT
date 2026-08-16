/*@
    predicate division_axiom(integer x) = x / 1 == x;
    predicate modulo_axiom(integer x) = x % 1 == 0;
*/

/*@
    lemma axiom_division: \forall integer x; division_axiom(x);
    lemma axiom_modulo: \forall integer x; modulo_axiom(x);
*/

/*@
    requires a == b;
    ensures \result == b / 1;
*/
int calc_example_8(int a, int b)
{
    //@ assert a == b;
    //@ assert b / 1 == b;
    //@ assert a == b / 1;
    return a;
}

/*@
    requires a % 1 == 0;
    ensures \result == 0;
*/
int calc_example_9(int a)
{
    //@ assert a % 1 == 0;
    return 0;
}

int main()
{
    return 0;
}
