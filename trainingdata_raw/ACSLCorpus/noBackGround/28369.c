#include <stdbool.h>
#include <stddef.h>

/*@ requires 
      (3 <= (n) && (n) <= 100 &&
      1 <= (a) && (a) < (b) && (b) < 20) &&
      (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
    ensures
      \result >= 0;
    ensures
      \result <= n;
*/
int func(int n, int a, int b, int *p)
{
    int count[3];
    int i;
    
    count[0] = 0;
    count[1] = 0;
    count[2] = 0;
    i = 0;
    
    /*@ loop invariant 
          0 <= i && i <= n;
        loop invariant
          (3 <= (n) && (n) <= 100 &&
      1 <= (a) && (a) < (b) && (b) < 20);
        loop invariant
          (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
        loop invariant
          ((&count[0])[0] >= 0 && (&count[0])[0] <= (i) &&
      (&count[0])[1] >= 0 && (&count[0])[1] <= (i) &&
      (&count[0])[2] >= 0 && (&count[0])[2] <= (i) &&
      (\forall integer j; 0 <= j < (i) ==>
         ((p)[j] <= (a) ==> (&count[0])[0] > 0) &&
         ((p)[j] > (a) && (p)[j] <= (b) ==> (&count[0])[1] > 0) &&
         ((p)[j] > (b) ==> (&count[0])[2] > 0)));
        loop assigns
          i, count[0], count[1], count[2];
        loop variant
          n - i;
    */
    while (i < n) {
        int value;
        value = p[i];
        
        if (value <= a) {
            //@ assert value <= a;
            count[0] = count[0] + 1;
        } else if (value <= b) {
            //@ assert value > a && value <= b;
            count[1] = count[1] + 1;
        } else {
            //@ assert value > b;
            count[2] = count[2] + 1;
        }
        
        i = i + 1;
    }
    
    int min_value;
    if (count[0] < count[1] && count[0] < count[2]) {
        min_value = count[0];
    } else if (count[1] < count[0] && count[1] < count[2]) {
        min_value = count[1];
    } else {
        min_value = count[2];
    }
    
    //@ assert min_value >= 0;
    //@ assert min_value <= n;
    
    return min_value;
}
