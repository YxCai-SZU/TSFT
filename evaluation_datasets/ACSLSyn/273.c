#include <stdbool.h>
#include <limits.h>

/* Scenario: Packet validation in a network protocol handler.
 * Data flow: 
 * 1. First function (func3) computes a bound value from two packet dimensions (a,b).
 * 2. Second function (func2) checks if the packet is "small" (both dimensions <= 8).
 * 3. Third function (lemma_unique_element2) verifies uniqueness of a buffer (not used here, but part of chain).
 * 
 * The synthesized function validates that if a packet is "small", its computed bound is within a safe range.
 */

/* --- Original functions with ACSL specs --- */

/*@
    predicate is_unique_seq{L}(int *s, integer len) =
        len > 0 &&
        \forall integer i, j; 0 <= i < j < len ==> s[i] != s[j];

    predicate contains{L}(int *s, integer len, int value) =
        \exists integer i; 0 <= i < len && s[i] == value;

    lemma unique_element_lemma{L}:
        \forall int *s, integer len;
        is_unique_seq(s, len) ==>
        (\forall integer k; 0 <= k < len ==> contains(s, len, s[k]));
*/

void lemma_unique_element(int *s, int len) {
    //@ assert len > 0;
    int a = s[0];
    //@ assert \exists integer i; 0 <= i < len && s[i] == a;
}

void lemma_unique_element2(int *s, int len) {
    lemma_unique_element(s, len);
    //@ assert \exists integer i; 0 <= i < len && s[i] == s[0];
}

/*@
    predicate a_in_range(integer a) = 1 <= a <= 16;
    predicate b_in_range(integer b) = 1 <= b <= 16;
    predicate sum_in_range(integer a, integer b) = a + b <= 16;
    predicate result_condition(integer a, integer b, bool result) = 
        result == (a <= 8 && b <= 8);
*/

bool func2(long a, long b)
{
    bool is_a;
    bool is_b;
    bool result;

    is_a = true;
    is_b = true;

    if (a > 8)
    {
        is_a = false;
    }
    //@ assert is_a == (a <= 8);

    if (b > 8)
    {
        is_b = false;
    }
    //@ assert is_b == (b <= 8);

    result = is_a && is_b;
    //@ assert result == (a <= 8 && b <= 8);

    return result;
}

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer max_sum(integer a, integer b) = a * 2 + b * 2;

    lemma res_bounds:
        \forall integer a, b, res;
        valid_range(a, b) && (res == max_sum(a, b) - 1 || res == max_sum(a, b)) ==>
        res >= 0 && res <= max_sum(a, b);
*/

int func3(int a, int b)
{
    int local_a = a;
    int local_b = b;
    int res;

    if (local_a > local_b)
    {
        //@ assert local_a * 2 <= 200;
        //@ assert local_b * 2 <= 200;
        //@ assert local_a * 2 + local_b * 2 - 1 <= 399;
        res = local_a * 2 + local_b * 2 - 1;
    }
    else
    {
        //@ assert local_a * 2 <= 200;
        //@ assert local_b * 2 <= 200;
        //@ assert local_a * 2 + local_b * 2 <= 400;
        res = local_a * 2 + local_b * 2;
    }

    //@ assert res == local_a * 2 + local_b * 2 - 1 || res == local_a * 2 + local_b * 2;
    //@ assert res >= 0;
    //@ assert res <= local_a * 2 + local_b * 2;

    return res;
}

/* --- Synthesized function with call chain length 3 --- */

/*@
    predicate packet_is_small(integer a, integer b) = 
        1 <= a <= 16 && 1 <= b <= 16 && a + b <= 16 && a <= 8 && b <= 8;

    predicate bound_is_safe(integer a, integer b, int bound) =
        bound >= 0 && bound <= a * 2 + b * 2;
*/

int validate_packet(int a, int b)
{
    bool is_small = func2((long)a, (long)b);
    //@ assert is_small == (a <= 8 && b <= 8);

    int bound = func3(a, b);
    //@ assert bound >= 0 && bound <= a * 2 + b * 2;

    int dummy[2] = {1, 2};
    lemma_unique_element2(dummy, 2);
    //@ assert \exists integer i; 0 <= i < 2 && dummy[i] == dummy[0];

    //@ assert is_small ==> (bound >= 0 && bound <= a * 2 + b * 2);

    return bound;
}

int main() {
    return 0;
}
