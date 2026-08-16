#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* ========== Function 1: tetrahedral_number ========== */
/*@
    predicate valid_input(integer n) = 0 <= n <= 255;

    logic integer tetrahedral_formula(integer n) =
        n * (n + 1) * (n + 2) / 6;

    lemma intermediate_bound1:
        \forall integer n; valid_input(n) ==> n * (n + 1) <= 65280;

    lemma intermediate_bound2:
        \forall integer n; valid_input(n) ==> n * (n + 1) * (n + 2) <= 16776960;

    lemma final_bound:
        \forall integer n; valid_input(n) ==> n * (n + 1) * (n + 2) / 6 <= 2796200;
*/

uint32_t tetrahedral_number(uint32_t n)
{
    uint32_t result;

    //@ assert valid_input(n);
    result = n * (n + 1) * (n + 2) / 6;

    return result;
}

/* ========== Function 2: count_min_category ========== */
/*@ predicate valid_params(long n, long a, long b, long *p) =
      3 <= n && n <= 100 &&
      1 <= a && a < b && b < 20 &&
      \valid(p + (0 .. n-1)) &&
      \forall integer j; 0 <= j < n ==> 1 <= p[j] && p[j] <= 20;
*/


/*@ lemma min_non_negative:
      \forall integer x, y, z;
      x >= 0 && y >= 0 && z >= 0 ==>
      (x < y ? (x < z ? x : z) : (y < z ? y : z)) >= 0;
*/

long count_min_category(long n, long a, long b, const long *p) {
    long count1 = 0;
    long count2 = 0;
    long count3 = 0;
    long i = 0;
    
    while (i < n) {
        long pi = p[i];
        
        //@ assert 1 <= pi && pi <= 20;
        
        if (pi <= a) {
            count1 += 1;
        } else if (pi <= b) {
            count2 += 1;
        } else {
            count3 += 1;
        }
        
        i += 1;
    }
    
    //@ assert count1 >= 0 && count2 >= 0 && count3 >= 0;
    
    long min_val;
    if (count1 < count2) {
        if (count1 < count3) {
            min_val = count1;
        } else {
            min_val = count3;
        }
    } else if (count2 < count3) {
        min_val = count2;
    } else {
        min_val = count3;
    }
    
    //@ assert min_val >= 0;
    return min_val;
}

/* ========== Function 3: calculate_reward ========== */
/*@ predicate X_in_range(integer x) = 1 <= x && x <= 205;
    predicate Y_in_range(integer y) = 1 <= y && y <= 205;
    predicate money_in_range(integer m) = 0 <= m && m <= (205 * 1000000) + (205 * 1000000) + 1000000;
 */

/*@ logic integer calculate_money(integer x, integer y) =
        x * 1000000 + y * 1000000 + 
        (x < y ? (y - x) * 100000 : (x - y) * 100000) + 
        (x == 0 && y == 0 ? 1000000 : 0);
 */

/*@ lemma money_nonnegative: 
        \forall integer x, y; 
        X_in_range(x) && Y_in_range(y) ==> calculate_money(x, y) >= 0;
    lemma money_upper_bound: 
        \forall integer x, y; 
        X_in_range(x) && Y_in_range(y) ==> calculate_money(x, y) <= (205 * 1000000) + (205 * 1000000) + 1000000;
 */

size_t calculate_reward(size_t X, size_t Y) {
    size_t money = 0;
    
    money += X * 1000000;
    //@ assert money == X * 1000000;
    
    money += Y * 1000000;
    //@ assert money == X * 1000000 + Y * 1000000;
    
    if (X < Y) {
        money += (Y - X) * 100000;
        //@ assert money == X * 1000000 + Y * 1000000 + (Y - X) * 100000;
    } else {
        money += (X - Y) * 100000;
        //@ assert money == X * 1000000 + Y * 1000000 + (X - Y) * 100000;
    }
    
    if (X == 0 && Y == 0) {
        money += 1000000;
        //@ assert money == X * 1000000 + Y * 1000000 + (X < Y ? (Y - X) * 100000 : (X - Y) * 100000) + 1000000;
    }
    
    //@ assert money >= 0;
    return money;
}

/* ========== Synthesized Function: tournament_score ========== */
size_t tournament_score(long n, long a, long b, const long *p, size_t X, size_t Y) {
    long diversity = count_min_category(n, a, b, p);
    //@ assert diversity >= 0;
    
    uint32_t capped_diversity;
    if (diversity > 255) {
        capped_diversity = 255;
    } else {
        capped_diversity = (uint32_t)diversity;
    }
    //@ assert 0 <= capped_diversity && capped_diversity <= 255;
    
    uint32_t multiplier = tetrahedral_number(capped_diversity);
    //@ assert multiplier == tetrahedral_formula(capped_diversity);
    
    size_t reward = calculate_reward(X, Y);
    //@ assert reward >= 0;
    
    size_t score = reward * ((size_t)multiplier + 1);
    
    //@ assert score >= 0;
    
    return score;
}
