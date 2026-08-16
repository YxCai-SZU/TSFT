#include <stdbool.h>

/*@
  requires \valid(numbers);
  requires numbers[0] == 1 && numbers[1] == 1;
  ensures (((numbers[0]) < 10 && (numbers[1]) < 10) ==> 
             \result == ((numbers[0]) * (numbers[1])));
  ensures (!((numbers[0]) < 10 && (numbers[1]) < 10) ==> \result == -1);
*/
int func(unsigned int* numbers)
{
    int result = -1;
    unsigned int n0 = numbers[0];
    unsigned int n1 = numbers[1];
    
    //@ assert (1 <= (n0) && (n0) <= 20) && (1 <= (n1) && (n1) <= 20);
    
    if (n0 < 10 && n1 < 10) {
        //@ assert ((n0) < 10 && (n1) < 10);
        //@ assert ((n0) * (n1)) <= 100;
        
        result = (int)(n0 * n1);
    }
    
    return result;
}
