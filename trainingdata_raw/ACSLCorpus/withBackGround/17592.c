#include <stdint.h>

/*@
    predicate bounds(integer n, integer m) =
        0 <= n <= 100 && 0 <= m <= 100;

    logic integer func_spec1(integer n, integer m) = n + m / 2;
    logic integer func_spec2(integer n, integer m) = (n * 2 + m) / 4;

    lemma arithmetic_lemma1:
        \forall integer n, m; bounds(n, m) && n * 2 <= m ==>
            (m - n * 2) / 4 + n <= func_spec1(n, m);

    lemma arithmetic_lemma2:
        \forall integer n, m; bounds(n, m) && n * 2 <= m ==>
            (m - n * 2) / 4 + n <= func_spec2(n, m);

    lemma arithmetic_lemma3:
        \forall integer n, m; bounds(n, m) && !(n * 2 <= m) ==>
            m / 2 <= func_spec1(n, m);

    lemma arithmetic_lemma4:
        \forall integer n, m; bounds(n, m) && !(n * 2 <= m) ==>
            m / 2 <= func_spec2(n, m);
*/

/*@
    requires 0 <= n <= 100 && 0 <= m <= 100;
    ensures \result <= n + m / 2;
    ensures \result <= (n * 2 + m) / 4;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert 0 <= n <= 100 && 0 <= m <= 100;
    
    if (n * 2 <= m) {
        //@ assert 0 <= n && n <= 100;
        //@ assert 0 <= m && m <= 100;
        //@ assert m - n * 2 <= 100;
        //@ assert (m - n * 2) / 4 <= 25;
        result = (m - n * 2) / 4 + n;
    } else {
        //@ assert m / 2 <= 50;
        result = m / 2;
    }
    
    return result;
}
