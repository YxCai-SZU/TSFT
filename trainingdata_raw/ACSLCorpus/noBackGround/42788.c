#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0 && n <= 100000;
  requires \valid(aa + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (aa)[i] > 0 && (aa)[i] <= 1000000000);
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> (aa)[i] % 2 == 0);
*/
bool func(size_t n, int *aa)
{
    bool even = true;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant even == true <==> (\forall integer i; 0 <= i < index ==> aa[i] % 2 == 0);
      loop invariant (\forall integer i; 0 <= i < (n) ==> (aa)[i] > 0 && (aa)[i] <= 1000000000);
      loop assigns index, even;
    */
    while (index < n)
    {
        int a = aa[index];
        if (a % 2 != 0)
        {
            even = false;
            break;
        }
        index++;
    }
    
    //@ assert even == true <==> (\forall integer i; 0 <= i < (n) ==> (aa)[i] % 2 == 0);
    return even;
}
