/* Real-world scenario: Network packet buffer allocation
 * Given a packet of size 'n' with header overhead 'm',
 * func computes an initial allocation estimate.
 * func2 computes additional overhead based on protocol flags a, b, c.
 * The synthesized function computes total buffer allocation,
 * ensuring it does not exceed a safe limit.
 */

/*@
    predicate bounds(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer product(integer n, integer m) = n * m;

    lemma product_bound: \forall integer n, m; bounds(n, m) ==> product(n, m) <= 10000;
*/

unsigned int func(unsigned int n, unsigned int m)
{
    unsigned int ans;

    //@ assert bounds(n, m);
    //@ assert product(n, m) <= 10000;

    if (m > (n * m) / 2)
    {
        ans = (n * m) / 2 + (n * m) % 2;
    }
    else
    {
        ans = m;
    }

    //@ assert ans <= m;
    return ans;
}

/*@
    predicate valid_range(integer x) = 0 <= x <= 50;

    logic integer func_spec(integer a, integer b, integer c) =
        (c > a + b + 1 ? c - a - b - 1 : 0) +
        (b > a + 1 ? b - a - 1 : 0);

    lemma func_lemma:
        \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        func_spec(a, b, c) >= 0 &&
        func_spec(a, b, c) <= a + b + c;
*/

long func2(long a, long b, long c)
{
    long ans = 0;
    long tmp1 = 0;
    long tmp2 = 0;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);

    if (c > a + b + 1)
    {
        tmp1 = c - a - b - 1;
    }
    else
    {
        tmp1 = 0;
    }

    //@ assert tmp1 >= 0 && tmp1 <= a + b + c;

    if (b > a + 1)
    {
        tmp2 = b - a - 1;
    }
    else
    {
        tmp2 = 0;
    }

    //@ assert tmp2 >= 0 && tmp2 <= a + b + c;

    ans = tmp1 + tmp2;

    //@ assert ans >= 0 && ans <= a + b + c;

    return ans;
}

unsigned int total_buffer_allocation(unsigned int n, unsigned int m, long a, long b, long c)
{
    unsigned int base = func(n, m);
    long overhead = func2(a, b, c);
    unsigned int total;

    //@ assert base <= m;
    //@ assert overhead >= 0 && overhead <= a + b + c;

    total = base + (unsigned int)overhead;

    //@ assert total <= m + a + b + c;
    return total;
}
