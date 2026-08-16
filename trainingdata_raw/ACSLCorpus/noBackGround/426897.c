#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 2 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 1000);
  ensures \result == true <==> (\exists integer i; 0 <= i < (n) && (a)[i] % 2 == 0);
  assigns \nothing;
*/
bool func(size_t n, int *a) {
    size_t even_count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= even_count <= i;
      loop invariant \forall integer j; 0 <= j < i ==> 1 <= a[j] && a[j] <= 1000;
      loop invariant (even_count > 0) <==> (\exists integer j; 0 <= j < i && a[j] % 2 == 0);
      loop assigns i, even_count;
      loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        //@ assert 1 <= value && value <= 1000;
        
        if (value % 2 == 0) {
            even_count += 1;
        }
        i += 1;
    }
    
    //@ assert (even_count > 0) <==> (\exists integer i; 0 <= i < (n) && (a)[i] % 2 == 0);
    return even_count > 0;
}

int main() {
    return 0;
}
