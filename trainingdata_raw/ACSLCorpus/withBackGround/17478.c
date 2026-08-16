#include <stdint.h>

/*@ predicate valid_input(integer n, integer m) =
      n >= 1 && n <= 100 &&
      m >= 1 && m <= 100;
*/

/*@ logic integer compute_buy(integer m) = m / 2; */
/*@ logic integer compute_rest(integer m, integer buy) = m - buy * 2; */
/*@ logic integer compute_rem(integer n, integer m) = 2 * n - m; */
/*@ logic integer compute_rem2(integer rest, integer rem) =
      rest == 0 ? rem : rem - 1;
*/
/*@ logic integer compute_result(integer buy, integer rem2) =
      buy + (rem2 / 4);
*/

/*@ lemma result_nonnegative_or_minus_one:
      \forall integer n, m, buy, rest, rem, rem2, result;
        valid_input(n, m) ==>
        buy == compute_buy(m) ==>
        rest == compute_rest(m, buy) ==>
        rem == compute_rem(n, m) ==>
        rem2 == compute_rem2(rest, rem) ==>
        result == compute_result(buy, rem2) ==>
        (result >= 0 || result == -1);
*/

/*@
  requires \valid_read(v + (0..1));
  requires valid_input(v[0], v[1]);
  assigns \nothing;
  ensures \result >= 0 || \result == -1;
*/
int64_t func(const uint64_t* v) {
    uint64_t n;
    uint64_t m;
    int64_t result;
    uint64_t buy;
    uint64_t rest;
    uint64_t rem;
    uint64_t rem2;

    n = v[0];
    m = v[1];

    //@ assert valid_input(n, m);

    if (2 * n < m) {
        result = -1;
        //@ assert result == -1;
        return result;
    }

    buy = m / 2;
    rest = m - buy * 2;
    rem = 2 * n - m;
    rem2 = (rest == 0) ? rem : rem - 1;
    result = (int64_t)(buy + (rem2 / 4));

    //@ assert result >= 0;
    return result;
}
