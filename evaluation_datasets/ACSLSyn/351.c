#include <stdbool.h>
#include <stddef.h>

/* ========== Function 1: Group Equality Check ========== */
/*@
predicate groups_equal{L}(unsigned int *g1, unsigned int *g2, integer len) =
    \forall integer i; 0 <= i < len ==> g1[i] == g2[i];
*/

typedef struct {
    unsigned int *g;
    int len;
} Group;

void group_example(Group *g1, Group *g2) {
    //@ assert groups_equal(g1->g, g2->g, g1->len);
    //@ assert g1->len == g2->len;
}

/* ========== Function 2: Adjacent/Equal Check ========== */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 9;

    logic integer main_condition(integer a, integer b, integer c) =
        (a == b) || (b == c) || (c == a) ||
        (a == b - 1) || (b == c - 1) || (c == a - 1) ||
        (a == b + 1) || (b == c + 1) || (c == a + 1) ? 1 : 0;
*/

bool func2(int a, int b, int c)
{
    bool result;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if (a == b - 1 || a == b + 1 || a == b) {
        result = true;
        //@ assert main_condition(a, b, c) == 1;
        return result;
    } else if (b == c - 1 || b == c + 1 || b == c) {
        result = true;
        //@ assert main_condition(a, b, c) == 1;
        return result;
    } else if (c == a - 1 || c == a + 1 || c == a) {
        result = true;
        //@ assert main_condition(a, b, c) == 1;
        return result;
    }

    //@ assert !(a == b - 1 || a == b + 1 || a == b);
    //@ assert !(b == c - 1 || b == c + 1 || b == c);
    //@ assert !(c == a - 1 || c == a + 1 || c == a);
    
    result = false;
    //@ assert main_condition(a, b, c) == 0;
    return result;
}

/* ========== Function 3: Between Check ========== */
/*@ predicate is_between(integer a, integer b, integer c) =
      (a < c && c < b) || (a > c && c > b);
*/

bool func3(int a, int b, int c)
{
    int max_val;
    int min_val;
    bool result;

    max_val = a;
    //@ assert max_val == a;
    if (b > max_val) {
        max_val = b;
    }
    if (c > max_val) {
        max_val = c;
    }

    min_val = a;
    //@ assert min_val == a;
    if (b < min_val) {
        min_val = b;
    }
    if (c < min_val) {
        min_val = c;
    }

    if ((max_val == a && min_val == b && c > b && c < a) ||
        (max_val == b && min_val == a && c > a && c < b)) {
        //@ assert is_between(a, b, c);
        result = true;
    } else {
        //@ assert !is_between(a, b, c);
        result = false;
    }

    return result;
}

/* ========== Function 4: Array Processing ========== */
/*@ predicate is_valid_array(integer n, int *numbers) =
      n >= 1 && n <= 200000 &&
      \valid(numbers + (0 .. n-1)) &&
      (\forall integer i; 0 <= i < n ==> 1 <= numbers[i] && numbers[i] <= n) &&
      (\forall integer i, j; 0 <= i < j < n ==> numbers[i] != numbers[j]);
*/

int func4(size_t n, int *numbers) {
    size_t x = 0;
    size_t y = 0;
    size_t z = 0;
    
    while (x < n) {
        //@ assert 0 <= x < n;
        if (x == (size_t)numbers[x]) {
            z += 1;
        } else if (y < n && numbers[y] == (int)x) {
            y += 1;
        } else {
            z += 1;
        }
        x += 1;
    }
    
    if (z < 2) {
        return -1;
    } else {
        return (int)z;
    }
}

/* ========== Synthesized Complex Function: Data Validation Pipeline ========== */

/*@ 
  predicate valid_config(integer a, integer b, integer c, integer n, int *numbers) =
      is_valid_range(a) && is_valid_range(b) && is_valid_range(c) &&
      1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 &&
      is_valid_array(n, numbers) &&
      (main_condition(a, b, c) == 1 || is_between(a, b, c));
*/

int validate_and_process(Group *g1, Group *g2, int a, int b, int c, size_t n, int *numbers) {
    int result;
    
    group_example(g1, g2);
    
    bool adj_equal = func2(a, b, c);
    
    bool between = func3(a, b, c);
    
    if (adj_equal || between) {
        result = func4(n, numbers);
    } else {
        result = -1;
    }
    
    return result;
}
