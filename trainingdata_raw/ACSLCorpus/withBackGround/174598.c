#include <stdbool.h>

/*@ predicate is_valid_range(integer a) = 1 <= a <= 3; */
/*@ predicate are_distinct(integer a, integer b) = a != b; */
/*@ logic integer complement_sum(integer a, integer b) = 6 - a - b; */

/*@ lemma complement_correctness: 
      \forall integer a, b; 
      is_valid_range(a) && is_valid_range(b) && are_distinct(a,b) ==> 
      complement_sum(a,b) >= 1 && complement_sum(a,b) <= 3; */

/*@ requires is_valid_range(A) && is_valid_range(B) && are_distinct(A,B); 
    ensures \result == complement_sum(A,B); 
*/
int func(int A, int B)
{
  int answers[3];
  int result = 0;
  int i = 0;
  
  answers[0] = 1;
  answers[1] = 2;
  answers[2] = 3;
  
  /*@ assert A-1 >= 0 && A-1 < 3; */
  answers[A-1] = 0;
  /*@ assert B-1 >= 0 && B-1 < 3; */
  answers[B-1] = 0;
  
  /*@ loop invariant 0 <= i <= 3;
      loop invariant \forall integer k; 0 <= k < i ==> answers[k] == 0;
      loop invariant answers[0] + answers[1] + answers[2] == complement_sum(A,B);
      loop assigns i, result;
  */
  while (i < 3) {
    if (answers[i] > 0) {
      result = answers[i];
      break;
    }
    i++;
  }
  
  /*@ assert result == complement_sum(A,B); */
  return result;
}
