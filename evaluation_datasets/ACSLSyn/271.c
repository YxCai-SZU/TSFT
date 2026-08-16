#include <stdbool.h>
#include <stddef.h>

/* ====== First snippet: func (quadratic computation) ====== */
/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer func_spec(integer r) = 3 * r * r;
    lemma func_bound: \forall integer r; r_in_range(r) ==> 3 * r * r <= 30000;
*/

int func(int r)
{
    int result;
    //@ assert r_in_range(r);
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    result = 3 * r * r;
    return result;
}

/* ====== Second snippet: func (sortedness check) ====== */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    predicate is_sorted(integer a, integer b, integer c) = a <= b && b <= c;
*/

#include <stdbool.h>

bool func2(int a, int b, int c)
{
    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    return a <= b && b <= c;
}

/* ====== Third snippet: func (list processing) ====== */
/*@ predicate valid_params(integer N, integer X) =
      1 <= N && N <= 100 &&
      1 <= X && X <= 10000;
*/

/*@ predicate valid_list(integer N, int *L, integer len) =
      len == N &&
      \forall integer i; 0 <= i < len ==> 1 <= L[i] && L[i] <= 100;
*/




int func3(int N, int X, int *L) {
    int d = 0;
    int count = 0;
    size_t i = 0;
    size_t len = (size_t)N;

    //@ assert valid_params(N, X);
    //@ assert valid_list(N, L, len);

    while (d <= X && i < len) {
        count += 1;
        
        //@ assert d + L[i] >= 0;
        
        d += L[i];
        i += 1;
        
        //@ assert count <= N;
    }
    
    //@ assert count >= 0;
    return count;
}

/* ====== Synthesized function: real-world scenario ====== */
/* Scenario: A data quality scoring system for a warehouse inventory.
   - func computes a "weight factor" based on item priority r (1-100)
   - func2 checks if three dimension values (a,b,c) are in sorted order (quality check)
   - func3 counts how many items fit under a capacity X given their sizes L[0..N-1]
   The synthesized function computes an overall quality score: the product of
   weight factor and sortedness flag, but only if the count of fitting items is non-zero.
   The high-level property: the final score is either 0 (if no items fit or sortedness fails)
   or a positive integer bounded by the maximum possible weight factor.
*/

int compute_quality_score(int r, int a, int b, int c, int N, int X, int *L) {
    int weight = func(r);
    bool sorted = func2(a, b, c);
    int count = func3(N, X, L);
    
    int score;
    if (count > 0 && sorted) {
        score = weight;
    } else {
        score = 0;
    }
    
    //@ assert (score == 0) || (score > 0 && score <= 30000);
    return score;
}
