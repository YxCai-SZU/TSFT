#include <stdbool.h>

/*@
    predicate ans_correct(integer a, integer b, integer ans) =
        1 <= a && a <= 10000 &&
        1 <= b && b <= 10000 &&
        ans == (a - 1) / 2 + b - 1;

    predicate req_correct(integer c, integer d, integer req) =
        1 <= c && c <= 10000 &&
        1 <= d && d <= 10000 &&
        req == c - 1 + d;

    lemma ans_bounds:
        \forall integer a, b, ans;
        ans_correct(a, b, ans) ==> 0 <= ans && ans <= 5000 + 10000 - 1;

    lemma req_bounds:
        \forall integer c, d, req;
        req_correct(c, d, req) ==> 0 <= req && req <= 10000 + 10000 - 1;
*/

/*@
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    requires 1 <= c && c <= 10000;
    requires 1 <= d && d <= 10000;
    ensures \result == ((a - 1) / 2 + b - 1 >= c - 1 + d);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int ans;
    unsigned int req;
    bool res;

    ans = (a - 1) / 2 + b - 1;
    req = c - 1 + d;

    //@ assert ans_correct(a, b, ans);
    //@ assert req_correct(c, d, req);
    //@ assert 0 <= ans && ans <= 5000 + 10000 - 1;
    //@ assert 0 <= req && req <= 10000 + 10000 - 1;

    res = ans >= req;
    //@ assert res == ((a - 1) / 2 + b - 1 >= c - 1 + d);
    return res;
}
