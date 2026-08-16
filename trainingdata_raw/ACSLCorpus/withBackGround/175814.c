#include <stdbool.h>

/*@ predicate sorted(int *arr, integer len) =
      \forall integer i; 0 <= i < len-1 ==> arr[i] < arr[i+1];
*/

/*@
  requires 1 <= a <= 10000;
  requires 1 <= b <= 10000;
  requires 1 <= c <= 10000;
  requires 1 <= d <= 10000;
  ensures \result == true <==> a < b && b < c && c < d;
*/
bool func(int a, int b, int c, int d)
{
    bool result;
    //@ assert 1 <= a <= 10000 && 1 <= b <= 10000 && 1 <= c <= 10000 && 1 <= d <= 10000;
    if (a < b && b < c && c < d)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    //@ assert result == true <==> a < b && b < c && c < d;
    return result;
}

/*@
  requires 1 <= a <= 10000;
  requires 1 <= b <= 10000;
  requires 1 <= c <= 10000;
  requires 1 <= d <= 10000;
  ensures \result == true <==> a < b && b < c && c < d;
*/
bool main_func(int a, int b, int c, int d)
{
    int v[4];
    bool result;
    
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    
    //@ assert v[0] == a && v[1] == b && v[2] == c && v[3] == d;
    //@ assert 1 <= a <= 10000 && 1 <= b <= 10000 && 1 <= c <= 10000 && 1 <= d <= 10000;
    
    result = func(a, b, c, d);
    //@ assert result == true <==> a < b && b < c && c < d;
    return result;
}
