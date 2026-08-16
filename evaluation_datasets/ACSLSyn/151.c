#include <stdbool.h>

/* ===== First underlying function: checks triangle-like inequality on bounded values ===== */

/*@
    predicate bounds(integer v) = 1 <= v <= 10000;

    logic integer sum(integer x, integer y) = x + y;

    lemma sum_bounds:
        \forall integer x, y; bounds(x) && bounds(y) ==> sum(x, y) <= 20000;
*/

bool func1(int a, int b, int c, int d)
{
    bool result;

    //@ assert bounds(a);
    //@ assert bounds(b);
    //@ assert bounds(c);
    //@ assert bounds(d);
    //@ assert sum(a, d) <= 20000;
    //@ assert sum(c, b) <= 20000;

    result = (a + d) >= c && (c + b) >= a;
    return result;
}

/* ===== Second underlying function: checks if ceil(n/2) >= k for bounded n,k ===== */

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 100 && 1 <= k && k <= 100;

    logic integer half_ceil(integer n) = (n + 1) / 2;

    lemma half_ceil_bound:
        \forall integer n; 1 <= n && n <= 100 ==> half_ceil(n) <= 50;
*/

int func2(unsigned int n, unsigned int k) {
    unsigned int even;
    unsigned int x;
    int result;

    even = (n % 2 == 0) ? n : n + 1;
    x = even / 2;

    //@ assert n <= 100;
    //@ assert k <= 100;
    //@ assert x == half_ceil(n);
    //@ assert x <= 50;

    result = (x >= k);
    return result;
}

/* ===== Synthesized function: resource allocation check in a real-world buffer system ===== */

/*@
    predicate valid_resource(integer size, integer count, integer min_size, integer max_count) =
        bounds(size) && bounds(min_size) && 1 <= count && count <= 100 && 1 <= max_count && max_count <= 100;
*/

int check_resource_allocation(int size, int count, int min_size, int max_count)
{
    bool part1;
    int part2;
    int result;

    part1 = func1(size, count, min_size, max_count);

    part2 = func2(count, max_count);

    result = (part1 && (part2 != 0)) ? 1 : 0;

    //@ assert part1 == ( (size + max_count) >= min_size && (min_size + count) >= size );
    //@ assert part2 == (half_ceil(count) >= max_count);
    //@ assert (result == 1) <==> ( (size + max_count) >= min_size && (min_size + count) >= size && (half_ceil(count) >= max_count) );

    return result;
}
