#include <stdbool.h>

/*@
  requires \valid(numbers) && \valid(numbers+1) && \valid(numbers+2);
  requires numbers[0] >= 0 && numbers[1] >= 0 && numbers[2] >= 0;
  requires numbers[0] + numbers[1] + numbers[2] <= 20;
  ensures \result == (numbers[0] + numbers[1] == numbers[2] ||
                      numbers[1] + numbers[2] == numbers[0] ||
                      numbers[0] + numbers[2] == numbers[1]);
*/
bool func(unsigned long long *numbers) {
    unsigned long long sum = 0;
    unsigned int i = 0;
    
    //@ ghost unsigned long long a = numbers[0];
    //@ ghost unsigned long long b = numbers[1];
    //@ ghost unsigned long long c = numbers[2];
    
    /*@
      loop invariant 0 <= i <= 3;
      loop invariant sum >= 0;
      loop invariant sum <= 20;
      loop invariant (\valid((numbers)) && \valid((numbers)+1) && \valid((numbers)+2));
      loop invariant numbers[0] >= 0 && numbers[1] >= 0 && numbers[2] >= 0;
      loop invariant numbers[0] + numbers[1] + numbers[2] <= 20;
      loop invariant i == 0 ==> sum == 0;
      loop invariant i == 1 ==> sum == numbers[0];
      loop invariant i == 2 ==> sum == numbers[0] + numbers[1];
      loop invariant i == 3 ==> sum == numbers[0] + numbers[1] + numbers[2];
      loop assigns sum, i;
      loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert i >= 0 && i < 3;
        sum += numbers[i];
        i++;
    }
    
    //@ assert sum == numbers[0] + numbers[1] + numbers[2];
    
    unsigned long long a_val = numbers[0];
    unsigned long long b_val = numbers[1];
    unsigned long long c_val = numbers[2];
    
    //@ assert sum == a_val + b_val + c_val;
    
    return (sum == 2 * a_val) || (sum == 2 * b_val) || (sum == 2 * c_val);
}
