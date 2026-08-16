#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 7;

    logic integer min(integer x, integer y) = (x < y) ? x : y;

    lemma ka_range: \forall integer a, k; valid_range(a) && valid_range(k) ==> 0 <= min(a, k) <= 7;
    lemma kb_range: \forall integer b, k, ka; valid_range(b) && valid_range(k) && 0 <= ka <= k ==> 0 <= min(b, k - ka) <= 7;
    lemma kc_range: \forall integer c, k, ka, kb; valid_range(c) && valid_range(k) && 0 <= ka <= k && 0 <= kb <= k - ka ==> 0 <= min(c, k - ka - kb) <= 7;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(k);
    ensures \result >= -7;
    ensures \result <= 7;
    ensures \result <= a + b + c + k;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int r = 0;
    int ka = 0;
    int kb = 0;
    int kc = 0;

    //@ assert 1 <= a <= 7 && 1 <= k <= 7;
    ka = (a < k) ? a : k;
    //@ assert 0 <= ka <= 7;
    r += ka;

    //@ assert k - ka >= 0;
    kb = (b < k - ka) ? b : (k - ka);
    //@ assert 0 <= kb <= 7;
    r -= kb;

    //@ assert k - ka - kb >= 0;
    kc = (c < k - ka - kb) ? c : (k - ka - kb);
    //@ assert 0 <= kc <= 7;
    r += kc;

    //@ assert r >= -7;
    return r;
}
