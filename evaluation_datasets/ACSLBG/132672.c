/*@
predicate valid_chain(integer a, integer b, integer c, integer d) =
    1 <= a && a < b && b < c && c <= d;

lemma chain_lemma:
    \forall integer a, b, c, d;
    valid_chain(a, b, c, d) ==> a < d;
*/


void func(int a, int b, int c, int d)
{
    //@ assert 1 <= a;
    //@ assert a < b;
    //@ assert b < c;
    //@ assert c <= d;
    //@ assert a < d;
}

int main() {
    return 0;
}
