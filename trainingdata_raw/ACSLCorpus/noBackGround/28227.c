#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0 && n <= 100;
  requires \valid(input_numbers + (0 .. n-1));
  requires ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (input_numbers)[i] && (input_numbers)[i] <= 100);
  ensures \result >= 0 && \result <= n;
*/
int func(int n, int *input_numbers)
{
    int answer = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant ((answer) >= 0 && (answer) <= (index) && (index) <= (n));
      loop assigns answer, index;
      loop variant n - index;
    */
    while (index < n) {
        int a = input_numbers[index];
        int temp = a;
        
        /*@
          loop invariant temp >= 0 && temp <= a;
          loop assigns temp;
          loop variant temp;
        */
        while (temp >= 2 || temp <= -2) {
            if (temp > 0) {
                temp = temp - 2;
            } else {
                temp = temp + 2;
            }
        }
        
        bool is_even = (temp == 0);
        if (is_even) {
            answer += 1;
        }
        index += 1;
    }
    
    //@ assert ((answer) >= 0 && (answer) <= ((n)) && ((n)) <= (n));
    return answer;
}
