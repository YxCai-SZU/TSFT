#include <stdbool.h>
#include <stddef.h>

/* ========== Original Function 1 (with specification) ========== */

/*@ predicate valid_params(integer X, integer Y) =
      1 <= X && X <= 205 &&
      1 <= Y && Y <= 205;
*/

/*@ logic integer rank_value(integer y) =
      y == 1 || y == 2 ? 0 :
      y == 3 || y == 4 ? 3000 :
      2000;
*/

/*@ lemma money_bounds:
      \forall integer X, Y;
      valid_params(X, Y) ==>
      (\forall integer money; 0 <= money <= 3000 * (X - 1) ==> 0 <= money <= 1000000);
*/

int func1(int X, int Y)
{
  int money = 0;
  int x = 1;
  int ranks[4] = {0, 3000, 2000, 1000};

  while (x < X) {
    int index;
    
    if (Y == 1 || Y == 2) {
      index = 0;
    } else if (Y == 3 || Y == 4) {
      index = 1;
    } else {
      index = 2;
    }
    
    //@ assert 0 <= index < 4;
    money += ranks[index];
    //@ assert money >= 0 && money <= 3000 * x;
    x += 1;
  }
  
  //@ assert money >= 0 && money <= 1000000;
  return money;
}

/* ========== Original Function 2 (with specification) ========== */

/*@ predicate valid_array(int *arr, size_t n) =
      n >= 2 && n <= 100000 &&
      \forall size_t i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 10000;
*/

/*@ predicate max_in_prefix(int *arr, size_t n, size_t idx, int max_val) =
      \forall size_t k; 0 <= k < idx ==> max_val >= arr[k];
*/

/*@ predicate second_max_in_prefix(int *arr, size_t n, size_t max_idx, size_t idx, int max2_val) =
      \forall size_t k; 0 <= k < idx ==> (k != max_idx) ==> max2_val >= arr[k];
*/

/*@ lemma max_non_negative:
      \forall int *arr, size_t n; valid_array(arr, n) ==>
      \forall size_t i; 0 <= i < n ==> arr[i] >= 0;
*/

int func2(size_t n, int *h) {
    int max = 0;
    size_t max_index = 0;
    size_t index = 0;
    
    while (index < n) {
        int current = h[index];
        if (max <= current) {
            max = current;
            max_index = index;
        }
        index++;
    }
    
    int max2;
    if (max_index > 0) {
        max2 = h[max_index - 1];
    } else {
        max2 = h[max_index + 1];
    }
    
    size_t index2 = 0;
    
    while (index2 < n) {
        int current = h[index2];
        if (index2 != max_index) {
            if (max2 <= current) {
                max2 = current;
            }
        }
        index2++;
        //@ assert index2 <= n;
    }
    
    return max2;
}

/* ========== Original Function 3 (with specification) ========== */

/*@
    predicate is_two_digit(integer a) = 10 <= a && a <= 99;
    predicate contains_nine(integer a) = a / 10 == 9 || a % 10 == 9;
*/

bool func3(unsigned long a)
{
    bool result = false;
    
    //@ assert is_two_digit(a);
    
    if (a >= 100 || a < 10) {
        return result;
    }
    
    if (a / 10 == 9) {
        result = true;
    }
    
    if (a % 10 == 9) {
        result = true;
    }
    
    //@ assert result == (a / 10 == 9 || a % 10 == 9);
    return result;
}

/* ========== Synthesized Complex Function ========== */

/* Scenario: Processing tournament player data.
   Given an array h of player heights (size n, each height between 1 and 10000),
   and tournament parameters X (number of matches) and Y (player rank category),
   we compute:
   1. The second maximum height among players (func2).
   2. Whether the second maximum height is a two-digit number containing digit 9 (func3).
   3. A monetary score based on matches and rank (func1).
   The synthesized function returns the second maximum height if it contains digit 9,
   otherwise returns the monetary score.
*/

int synthesized_func(int X, int Y, size_t n, int *h) {
    int second_max = func2(n, h);
    //@ assert second_max >= 0;
    
    bool has_nine;
    if (second_max >= 10 && second_max <= 99) {
        has_nine = func3((unsigned long)second_max);
    } else {
        has_nine = false;
    }
    //@ assert has_nine == (10 <= second_max <= 99 && (second_max / 10 == 9 || second_max % 10 == 9));
    
    int money = func1(X, Y);
    //@ assert money >= 0 && money <= 1000000;
    
    int result;
    if (has_nine) {
        result = second_max;
    } else {
        result = money;
    }
    
    //@ assert (has_nine ? result == second_max : result == money);
    //@ assert result >= 0;
    return result;
}
