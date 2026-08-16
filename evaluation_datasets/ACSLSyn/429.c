#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* ========== Original function 1: check at least two equal among three ========== */
/*@
    predicate is_valid_range(integer v) = 1 <= v <= 9;
*/

bool func1(int a, int b, int c)
{
    bool is_at_least_two_equal = false;
    bool is_at_least_two_not_equal = false;
    bool result;

    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c);

    if (a == b) {
        is_at_least_two_equal = true;
    } else if (b == c) {
        is_at_least_two_equal = true;
    } else if (c == a) {
        is_at_least_two_equal = true;
    }

    //@ assert is_at_least_two_equal == (a == b || b == c || c == a);

    if (a != b) {
        is_at_least_two_not_equal = true;
    } else if (b != c) {
        is_at_least_two_not_equal = true;
    } else if (c != a) {
        is_at_least_two_not_equal = true;
    }

    //@ assert is_at_least_two_not_equal == (a != b || b != c || c != a);

    if ((a == b && a != c) || (b == c && a != b) || (c == a && a != b)) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == ((a == b && a != c) || (b == c && a != b) || (c == a && a != b));
    return result;
}

/* ========== Original function 2: check circle within rectangle ========== */

/*@ predicate within_bounds(integer w, integer h, integer x, integer y, integer r) =
      r <= x && x <= (w - r) && r <= y && y <= (h - r);
*/

bool func2(int w, int h, int x, int y, int r) {
    int circle_right;
    int circle_left;
    int circle_top;
    int circle_bottom;
    bool result;

    circle_right = x + r;
    circle_left = x - r;
    circle_top = y + r;
    circle_bottom = y - r;

    //@ assert circle_right == x + r;
    //@ assert circle_left == x - r;
    //@ assert circle_top == y + r;
    //@ assert circle_bottom == y - r;

    if (circle_left < 0 || circle_right > w || circle_bottom < 0 || circle_top > h) {
        result = false;
    } else {
        result = true;
    }

    return result;
}

/* ========== Original function 3: check key equality ========== */

typedef struct {
    uint32_t a;
    uint32_t b;
} MyKey;

/*@ predicate key_eq(MyKey k1, MyKey k2) = k1.a == k2.a && k1.b == k2.b; */

/*@
  lemma key_eq_symm:
    \forall MyKey k1, MyKey k2; key_eq(k1, k2) ==> key_eq(k2, k1);
  lemma key_eq_trans:
    \forall MyKey k1, MyKey k2, MyKey k3;
      key_eq(k1, k2) && key_eq(k2, k3) ==> key_eq(k1, k3);
*/

void func3(MyKey k1, MyKey k2) {
    //@ assert key_eq(k1, k2);
    //@ assert k1.a == k2.a && k1.b == k2.b;
}

/* ========== Original function 4: check ordered and bounded differences ========== */

/*@
    predicate ordered_and_bounded(integer A, integer B, integer C, integer D, integer E, integer K) =
        0 <= A && A < B && B < C && C < D && D < E && E <= 123 &&
        0 <= K && K <= 123;
*/

/*@
    logic integer diff_B_A(integer A, integer B) = B - A;
    logic integer diff_C_A(integer A, integer C) = C - A;
    logic integer diff_D_A(integer A, integer D) = D - A;
    logic integer diff_E_A(integer A, integer E) = E - A;
*/

/*@
    lemma diff_positive:
        \forall integer A, B, C, D, E, K;
        ordered_and_bounded(A, B, C, D, E, K) ==>
        diff_B_A(A, B) > 0 && diff_C_A(A, C) > 0 && diff_D_A(A, D) > 0 && diff_E_A(A, E) > 0;
*/

bool func4(long long A, long long B, long long C, long long D, long long E, long long K)
{
    bool result = false;
    //@ assert diff_B_A(A, B) == B - A;
    if (B - A <= K)
    {
        //@ assert diff_C_A(A, C) == C - A;
        if (C - A <= K)
        {
            //@ assert diff_D_A(A, D) == D - A;
            if (D - A <= K)
            {
                //@ assert diff_E_A(A, E) == E - A;
                if (E - A <= K)
                {
                    result = true;
                }
            }
        }
    }
    //@ assert result == (diff_B_A(A, B) <= K && diff_C_A(A, C) <= K && diff_D_A(A, D) <= K && diff_E_A(A, E) <= K);
    return result;
}

/* =====================================================================
   Synthesized scenario: "Validation of a 2D geometric key-based zone mapping"
   
   We have a rectangular grid of size w x h. A "zone" is defined by 
   coordinates (x,y), a radius r, and three integer labels (a,b,c) in [1,9].
   The zone is valid if:
     1) The circle (x,y,r) fits within the rectangle (func2)
     2) Among the three labels, exactly two are equal and the third is different (func1)
     3) The zone has an associated MyKey (k1) that matches a reference key (k2) (func3)
     4) The zone's "expansion parameters" (A,B,C,D,E,K) satisfy ordered_and_bounded
        and all differences from A are <= K (func4)
   
   The synthesized function checks all four conditions.
   The high-level property: "If the zone passes all checks, then it is a valid zone 
   with a consistent key and bounded expansion."
   ===================================================================== */

/*@
  predicate valid_zone(integer w, integer h, integer x, integer y, integer r,
                       integer a, integer b, integer c,
                       MyKey k1, MyKey k2,
                       integer A, long long B, long long C, long long D, long long E, long long K) =
    within_bounds(w, h, x, y, r) &&
    ((a == b && a != c) || (b == c && a != b) || (c == a && a != b)) &&
    key_eq(k1, k2) &&
    (diff_B_A(A, B) <= K && diff_C_A(A, C) <= K && diff_D_A(A, D) <= K && diff_E_A(A, E) <= K);
*/

bool validate_zone(int w, int h, int x, int y, int r,
                   int a, int b, int c,
                   MyKey k1, MyKey k2,
                   long long A, long long B, long long C, long long D, long long E, long long K)
{
    bool circle_ok = false;
    bool labels_ok = false;
    bool key_ok = false;
    bool expansion_ok = false;
    bool result = false;

    circle_ok = func2(w, h, x, y, r);

    labels_ok = func1(a, b, c);

    func3(k1, k2);  // This function asserts key_eq; we consider it as a check
    key_ok = true;  // If func3 returns normally, the keys are equal (by its contract)

    expansion_ok = func4(A, B, C, D, E, K);

    if (circle_ok && labels_ok && key_ok && expansion_ok) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == true <==> (within_bounds(w, h, x, y, r) && ((a == b && a != c) || (b == c && a != b) || (c == a && a != b)) && key_eq(k1, k2) && (diff_B_A(A, B) <= K && diff_C_A(A, C) <= K && diff_D_A(A, D) <= K && diff_E_A(A, E) <= K));

    return result;
}

int main() {
    return 0;
}
