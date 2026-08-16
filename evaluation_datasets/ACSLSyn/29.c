#include <stdbool.h>
#include <stddef.h>

/* ACSL predicates and lemmas from first function */
/*@
    predicate is_valid_params(integer n, integer m, integer k) =
        1 <= n <= 1000 && 1 <= m <= 1000 && 0 <= k <= n * m;
    
    logic integer product(integer n, integer m) = n * m;
    
    lemma product_bound: \forall integer n, m; 
        1 <= n <= 1000 && 1 <= m <= 1000 ==> n * m <= 1000000;
*/

/* Original func1: checks parity condition and bound */
bool func(unsigned int n, unsigned int m, unsigned int k) {
    bool ans;
    
    //@ assert 1 <= n <= 1000 && 1 <= m <= 1000 && 0 <= k <= n * m;
    //@ assert n * m <= 1000 * 1000;
    
    ans = (k % 2 == (n * m) % 2) && k <= n * m;
    
    //@ assert ans == (k % 2 == (n * m) % 2) && k <= n * m;
    
    return ans;
}

/* ACSL predicates and lemmas from second function */
/*@ predicate is_ordered(integer a0, integer a1, integer a2) =
      a0 <= a1 && a1 <= a2;
*/

/*@ predicate is_in_range(integer a0, integer a1, integer a2) =
      a0 >= -100 && a0 <= 100 &&
      a1 >= -100 && a1 <= 100 &&
      a2 >= -100 && a2 <= 100;
*/

/*@ logic integer diff1(integer a0, integer a1) = a1 - a0;
    logic integer diff2(integer a1, integer a2) = a2 - a1;
*/

/*@ lemma diff_equality_lemma:
      \forall integer a0, a1, a2;
        is_ordered(a0, a1, a2) && is_in_range(a0, a1, a2) ==>
        (diff1(a0, a1) == diff2(a1, a2)) ==>
        (a1 - a0 == a2 - a1);
*/

/* Original func2: checks if three numbers are equally spaced */
bool func2(long long a[3])
{
    long long v[2];
    bool is_equal;
    int i;

    v[0] = a[1] - a[0];
    v[1] = a[2] - a[1];
    is_equal = true;
    i = 0;

    while (i < 1) {
        //@ assert i == 0;
        if (v[i] != v[i + 1]) {
            is_equal = false;
        }
        i += 1;
    }

    //@ assert is_equal == (v[0] == v[1]);
    return is_equal;
}

/* 
   Scenario: Grid-based arithmetic sequence validator
   This function simulates a grid validator for a game board.
   Given grid dimensions n x m and a position k on the grid,
   it first validates that k has the correct parity to be reachable
   (using func). Then it checks if three consecutive points on the
   grid form an arithmetic progression (using func2).
   
   The high-level property: If the parity check passes and the three
   points form an arithmetic progression, then the grid configuration
   is valid for the game.
*/

bool synthesized_func(unsigned int n, unsigned int m, unsigned int k, long long a[3]) {
    bool parity_ok;
    bool arithmetic_ok;
    
    //@ assert is_valid_params(n, m, k);
    parity_ok = func(n, m, k);
    //@ assert parity_ok == ((k % 2 == (n * m) % 2) && k <= n * m);
    
    //@ assert \valid(a+(0..2)) && is_in_range(a[0], a[1], a[2]) && is_ordered(a[0], a[1], a[2]);
    arithmetic_ok = func2(a);
    //@ assert arithmetic_ok == (a[1] - a[0] == a[2] - a[1]);
    
    //@ assert parity_ok && arithmetic_ok ==> (k % 2 == (n * m) % 2) && k <= n * m && (a[1] - a[0] == a[2] - a[1]);
    
    return parity_ok && arithmetic_ok;
}
