#include <stdbool.h>

/*@
    logic integer p(integer a, integer b, integer c) =
        c == 0 ? a :
        c == 1 ? b :
        p(b, a, c - 2);
*/

/*@
    predicate p_constant(integer n, integer m, integer c) =
        c < 2 ==> (p(n, m, c) == n || p(n, m, c) == m);
*/

/*@
    lemma lemma_p_constant:
        \forall integer n, m, c;
            c >= 0 && c < 2 ==> (p(n, m, c) == n || p(n, m, c) == m);
*/

/*@
    lemma lemma_p_turn_taker:
        \forall integer n, m, c;
            c >= 2 ==> p(n, m, c) == p(m, n, c - 2);
*/

/*@
    lemma lemma_p_same:
        \forall integer n, m;
            n == m ==> p(n, m, 0) == p(n, m, 1);
*/

int main()
{
    // Variable declarations
    int n = 0;
    int m = 0;
    int c = 0;
    
    //@ assert p_constant(n, m, c);
    
    return 0;
}
