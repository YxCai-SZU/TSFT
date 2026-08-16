#include <stdbool.h>

/* First function: parity check (even/odd detection) */
/*@
    predicate is_even_mod(integer x, integer result) =
        (x % 2 == 0 ==> result == 0) &&
        (x % 2 != 0 ==> result == 1);
*/

int parity_check(int x)
{
    bool is_even = true;
    int temp_x = x;

    while (temp_x > 1)
    {
        temp_x -= 2;
    }

    if (temp_x == 1 || temp_x == -1)
    {
        is_even = false;
    }

    //@ assert is_even_mod(x, is_even ? 0 : 1);
    return is_even ? 0 : 1;
}

/* Second function: count local monotonic triples in a permutation */
/*@
    predicate unique_elements(int *p, integer n) =
        \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];

    predicate in_range(int *p, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= p[i] && p[i] <= n;
*/

int count_monotonic_triples(int n, int *p) {
    int cnt = 0;
    unsigned int index = 1;

    while (index < (unsigned int)(n - 1)) {
        int pim1 = p[index - 1];
        int pi = p[index];
        int pip1 = p[index + 1];
        
        //@ assert 1 <= pim1 && pim1 <= n;
        //@ assert 1 <= pi && pi <= n;
        //@ assert 1 <= pip1 && pip1 <= n;
        
        if ((pim1 < pi && pi < pip1) || (pim1 > pi && pi > pip1)) {
            cnt += 1;
        }
        index += 1;
    }
    int ans = cnt;
    //@ assert 0 <= ans <= n;
    return ans;
}

/* 
 * Synthesized function: Real-world scenario - permutation parity analyzer
 * Analyzes a permutation array and returns the parity of the count of 
 * monotonic triples (where three consecutive elements are strictly 
 * increasing or strictly decreasing).
 * 
 * Data flow: 
 * 1. Count monotonic triples in the permutation
 * 2. Compute the parity (even/odd) of that count
 * 
 * High-level property: The final result correctly indicates whether the 
 * number of monotonic triples in the permutation is even (0) or odd (1).
 */
int analyze_permutation_parity(int n, int *p) {
    int triple_count = count_monotonic_triples(n, p);
    
    int result = parity_check(triple_count);
    
    //@ assert is_even_mod(triple_count, result);
    return result;
}

int main(void) {
    return 0;
}
