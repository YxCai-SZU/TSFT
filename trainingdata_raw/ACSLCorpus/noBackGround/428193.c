#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/*@ requires 
      (1 <= (n) <= 100000) && 
      (\valid((v) + (0..(n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (1 <= ((v)[i]) <= 1000000000)); 
    ensures 
      \valid(\result + (0..n-1)) && 
      \forall integer i; 0 <= i < n ==> (1 <= (\result[i]) <= 1000000000); 
    assigns v[0..n-1]; */
int64_t* func(size_t n, int64_t* v)
{
    int64_t* arr = v;
    size_t i = 0;
    
    /*@ loop invariant 
          0 <= i <= n-1 && 
          (\valid((arr) + (0..(n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (1 <= ((arr)[i]) <= 1000000000)) && 
          (1 <= (n) <= 100000); 
        loop assigns 
          arr[0..n-1], i; 
        loop variant n - i; */
    while (i < n - 1) {
        size_t j = i + 1;
        
        /*@ loop invariant 
              i < j <= n && 
              (\valid((arr) + (0..(n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (1 <= ((arr)[i]) <= 1000000000)) && 
              (1 <= (n) <= 100000); 
            loop assigns 
              arr[i], j; 
            loop variant n - j; */
        while (j < n) {
            int64_t k;
            if (arr[i] > arr[j]) {
                k = arr[i];
            } else {
                k = arr[j];
            }
            arr[i] = k;
            j++;
        }
        i++;
    }
    return arr;
}
