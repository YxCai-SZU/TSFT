#include <stdbool.h>

/*@ predicate valid_input(int *input) =
      \valid(input + (0..2)) &&
      (\forall integer i; 0 <= i < 3 ==> 1 <= input[i] <= 100);
*/

/*@ predicate satisfies_condition(int *input) =
      input[0] + input[1] == input[2] ||
      input[1] + input[2] == input[0] ||
      input[0] + input[2] == input[1];
*/

/*@
  requires valid_input(input);
  ensures \result == 1 <==> satisfies_condition(input);
*/
bool func(int *input) {
    bool result = false;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    
    //@ assert \valid(input + (0..2));
    
    sum1 = input[0] + input[1];
    sum2 = input[1] + input[2];
    sum3 = input[0] + input[2];
    
    if (sum1 == input[2] || sum2 == input[0] || sum3 == input[1]) {
        result = true;
    }
    
    //@ assert result == 1 <==> satisfies_condition(input);
    return result;
}
