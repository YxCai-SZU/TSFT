#include <stdbool.h>

/* ===== First underlying function (from snippet 1) ===== */
/*@
    predicate bounds(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= 100;

    logic integer half(integer n) = n / 2;
    logic integer km1(integer k) = k - 1;

    lemma half_bound: \forall integer n; 1 <= n && n <= 100 ==> half(n) <= 50;
    lemma km1_bound: \forall integer k; 1 <= k && k <= 100 ==> km1(k) <= 99;
*/

bool func1(unsigned int n, unsigned int k)
{
    bool result;

    //@ assert bounds(n, k);
    //@ assert half(n) <= 50;
    //@ assert km1(k) <= 99;
    
    result = (n / 2 >= k - 1);
    return result;
}

/* ===== Second underlying function (from snippet 2) ===== */
/*@
    predicate left_cond(integer a, integer c, integer b) =
        a < c && c < b;
    predicate right_cond(integer a, integer c, integer b) =
        a > c && c > b;
*/

bool func2(int a, int b, int c)
{
    bool left = false;
    bool right = false;

    if (a < c)
    {
        left = true;
    }
    if (c < b)
    {
        left = left && true;
    }
    else
    {
        left = left && false;
    }

    if (a > c)
    {
        right = true;
    }
    if (c > b)
    {
        right = right && true;
    }
    else
    {
        right = right && false;
    }

    //@ assert left == (a < c && c < b);
    //@ assert right == (a > c && c > b);

    return left || right;
}

/* ===== Synthesized function: real-world scenario ===== */
/* Scenario: Network packet size validator.
 * Given a packet of size 'size' and a buffer of capacity 'capacity',
 * we check if the packet can be split into two fragments (a and b)
 * such that the middle fragment 'c' lies strictly between a and b,
 * and also the size/capacity relationship satisfies half(capacity) >= size - 1.
 * This models a memory allocation check where fragmentation is allowed.
 */

/*@
    predicate valid_packet(integer size, integer capacity, integer a, integer b, integer c) =
        1 <= size <= 100 &&
        1 <= capacity <= 100 &&
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= c <= 100 &&
        ((a < c && c < b) || (a > c && c > b)) &&
        (capacity / 2 >= size - 1);
*/

bool validate_packet(unsigned int size, unsigned int capacity, int a, int b, int c)
{
    bool frag_ok;
    bool size_ok;
    bool result;

    frag_ok = func2(a, b, c);

    size_ok = func1(capacity, size);  // n=capacity, k=size -> checks capacity/2 >= size-1

    result = frag_ok && size_ok;

    //@ assert result == true ==> (valid_packet(size, capacity, a, b, c));
    //@ assert result == false ==> !valid_packet(size, capacity, a, b, c);

    return result;
}
