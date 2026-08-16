#include <stdbool.h>

/*@ predicate is_valid_index(int i, int len) = 0 <= i < len;
    predicate is_valid_value(int v) = 1 <= v <= 100;
    predicate is_arithmetic_sequence(int a, int b, int c) = b - a == c - b;
*/

/*@ lemma diff_preservation:
      \forall int a, int b, int c;
        b - a == c - b ==> is_arithmetic_sequence(a, b, c);
*/

/*@
  requires \valid(numbers + (0..2));
  requires \forall integer i; 0 <= i < 3 ==> 1 <= numbers[i] <= 100;
  ensures \result == (numbers[1] - numbers[0] == numbers[2] - numbers[1]);
  assigns \nothing;
*/
bool func(int numbers[3]) {
    int a, b, c;
    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    
    //@ assert numbers[1] - numbers[0] == b - a;
    
    //@ assert numbers[2] - numbers[1] == c - b;
    
    return (b - a == c - b);
}
