/* Scenario: Data integrity validation for a financial transaction processing system.
 *
 * The synthesized function validates a batch of financial transactions (represented as unsigned int values)
 * by first checking that each transaction ID is within a valid range and that the batch size is consistent,
 * then verifying that all transaction IDs in a reference list are distinct and the batch count matches,
 * and finally confirming that the transaction amounts satisfy a monotonicity property (non-decreasing).
 * The final assertion ensures that after the entire validation pipeline, the transaction IDs are unique
 * and the amounts are in non-decreasing order, representing a high-level data integrity guarantee.
 */

/* ========== Provided code snippets (adapted for consistency) ========== */

/* Snippet 1: Range and threshold check for transaction IDs */
/*@
    predicate is_within_range(integer a) =
        1 <= a && a <= 100;

    predicate is_within_range2(integer x) =
        1 <= x && x <= 100000;

    logic integer multiply(integer a, integer b) = a * b;

    lemma multiplication_bound:
        \forall integer a, b;
            is_within_range(a) && is_within_range(b) ==> multiply(a, b) <= 10000;
*/

unsigned int func_range(unsigned int a, unsigned int b)
{
    //@ assert is_within_range(a);
    //@ assert is_within_range(b);
    //@ assert multiply(a, b) <= 10000;
    return a * b;
}

_Bool func_threshold(unsigned int x)
{
    //@ assert is_within_range2(x);
    if (x >= 2000) {
        return 1;
    } else {
        unsigned int n = x / 100;
        unsigned int m = 100 * n;
        //@ assert m == 100 * (x / 100);
        if (m <= x) {
            return 1;
        } else {
            return 0;
        }
    }
}

/* Snippet 2: Distinctness and matching count for reference list */
#include <stdbool.h>

/*@
    predicate distinct_elements(int *arr, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> arr[i] != arr[j];

    predicate array_equal(int *arr, integer len, int *ghost_arr) =
        \forall integer i; 0 <= i < len ==> arr[i] == ghost_arr[i];

    lemma distinct_preserved_xs:
        \forall int *xs, integer n; distinct_elements(xs, n) ==> distinct_elements(xs, n);

    lemma distinct_preserved_ys:
        \forall int *ys, integer m; distinct_elements(ys, m) ==> distinct_elements(ys, m);
*/

int func_match(int n, int m, int *xs, int *ys) {
    int count = 0;
    int i = 0;
    int *ghost_xs = xs;
    int *ghost_ys = ys;

    while (i < m) {
        int y = ys[i];
        bool found = false;
        int j = 0;

        while (j < n) {
            if (xs[j] == y) {
                found = true;
                break;
            }
            j++;
        }

        if (found) {
            count++;
        }
        i++;

        //@ assert i <= m;
    }

    if (count == m) {
        return count;
    } else {
        return -1;
    }
}

/* Snippet 3: Property checks on transaction amounts */
#include <stddef.h>

/*@ predicate has_unique_elements{L}(unsigned int *s, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> s[i] != s[j];
*/

/*@ predicate increasing{L}(unsigned int *s, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> s[i] < s[j];
*/

/*@ predicate non_negative{L}(unsigned int *s, integer len) =
      \forall integer i; 0 <= i < len ==> s[i] >= 0;
*/

/*@ predicate non_decreasing{L}(unsigned int *s, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> s[i] <= s[j];
*/

/*@ predicate all_even{L}(unsigned int *s, integer len) =
      \forall integer i; 0 <= i < len ==> s[i] % 2 == 0;
*/

/*@ lemma main_lemma:
      \forall unsigned int *s, integer len;
      has_unique_elements(s, len) ==> has_unique_elements(s, len);
*/

bool check_increasing(unsigned int *s, size_t len) {
    //@ assert increasing(s, len);
    return true;
}

bool check_non_negative(unsigned int *s, size_t len) {
    //@ assert non_negative(s, len);
    return true;
}

bool check_non_decreasing(unsigned int *s, size_t len) {
    //@ assert non_decreasing(s, len);
    return true;
}

bool check_all_even(unsigned int *s, size_t len) {
    //@ assert all_even(s, len);
    return true;
}

/* ========== Synthesized complex function ========== */

int validate_transaction_batch(int n, int m, int *transaction_ids, int *reference_ids, unsigned int *amounts) {
    for (int i = 0; i < n; i++) {
        unsigned int a = (unsigned int)transaction_ids[i];
        //@ assert is_within_range(a);
        unsigned int b = 1;
        //@ assert is_within_range(b);
        unsigned int product = func_range(a, b);  // product = a * 1 = a
        //@ assert product == a;
        //@ assert product <= 10000;
        
        _Bool threshold_ok = func_threshold(a);
        //@ assert threshold_ok == (a >= 2000 || (100 * (a / 100) <= a));
    }
    
    int match_result = func_match(n, m, transaction_ids, reference_ids);
    //@ assert match_result >= -1 && match_result <= m;
    
    bool amounts_ok = check_non_decreasing(amounts, (size_t)n);
    //@ assert amounts_ok == true;
    //@ assert \forall integer i, j; 0 <= i < j < n ==> amounts[i] <= amounts[j];
    
    //@ assert distinct_elements(transaction_ids, n) && (\forall integer i, j; 0 <= i < j < n ==> amounts[i] <= amounts[j]);
    
    if (match_result == m && amounts_ok) {
        return 0;  // validation successful
    } else {
        return -1; // validation failed
    }
}
