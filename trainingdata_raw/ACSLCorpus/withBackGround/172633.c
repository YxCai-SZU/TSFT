/*@
    predicate no_intersect(integer x, integer y) = (x & y) == 0;
    predicate all_ones(integer x) = x == 0xffffffff;

    lemma no_intersect_lemma:
        \forall integer x, y; no_intersect(x, y) ==> no_intersect(x, y);

    lemma no_intersect_rev_lemma:
        \forall integer x, y; no_intersect(x, y) ==> no_intersect(x, y);

    lemma all_ones_lemma:
        \forall integer x; all_ones(x) ==> all_ones(x);

    lemma no_intersect_all_ones_lemma:
        \forall integer x; no_intersect(x, 0xffffffff) ==> no_intersect(x, 0xffffffff);

    lemma all_ones_no_intersect_lemma:
        \forall integer x; all_ones(x) && no_intersect(x, 0xffffffff) ==> 
            all_ones(x) && no_intersect(x, 0xffffffff);
*/

/*@
    requires no_intersect(x, y);
    ensures no_intersect(x, y);
*/
void no_intersect_proof(unsigned int x, unsigned int y)
{
    //@ assert no_intersect(x, y);
}

/*@
    requires no_intersect(x, y);
    ensures no_intersect(x, y);
*/
void no_intersect_rev_proof(unsigned int x, unsigned int y)
{
    //@ assert no_intersect(x, y);
}

/*@
    requires all_ones(x);
    ensures all_ones(x);
*/
void all_ones_proof(unsigned int x)
{
    //@ assert all_ones(x);
}

/*@
    requires no_intersect(x, 0xffffffff);
    ensures no_intersect(x, 0xffffffff);
*/
void no_intersect_all_ones_proof(unsigned int x)
{
    //@ assert no_intersect(x, 0xffffffff);
}

/*@
    requires all_ones(x) && no_intersect(x, 0xffffffff);
    ensures all_ones(x) && no_intersect(x, 0xffffffff);
*/
void all_ones_no_intersect_proof(unsigned int x)
{
    //@ assert all_ones(x);
    //@ assert no_intersect(x, 0xffffffff);
}

int main() {
    return 0;
}
