/*@
    predicate non_zero(integer y) = y != 0;

    logic integer newquotient(integer x, integer y) = x / y;
    logic integer newremainder(integer x, integer y) = x % y;

    lemma lemma_newdivision:
        \forall integer x, y; non_zero(y) ==>
            x == newquotient(x, y) * y + newremainder(x, y);
*/

/*@
    requires \true;
    ensures \true;
*/
void main() {
    //@ assert newquotient(10, 3) * 3 + newremainder(10, 3) == 10;
    //@ assert newquotient(100, 200) * 200 + newremainder(100, 200) == 100;
}
