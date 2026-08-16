#include <stdbool.h>

/*@ predicate contains_even(integer len, int *s) =
      \exists integer i; 0 <= i < len && s[i] % 2 == 0;
*/

/*@ predicate contains_multiple_of_3(integer len, int *s) =
      \exists integer i; 0 <= i < len && s[i] % 3 == 0;
*/

/*@ lemma no_even_no_multiple_of_3:
      \forall integer len, int *s;
        (\forall integer i; 0 <= i < len ==> s[i] % 2 != 0) &&
        (\forall integer i; 0 <= i < len ==> s[i] % 3 != 0) ==>
        !contains_even(len, s) && !contains_multiple_of_3(len, s);
*/

/*@
  requires 0 <= len;
  requires \valid(s + (0 .. len-1));
  requires \forall integer i; 0 <= i < len ==> s[i] % 2 != 0;
  requires \forall integer i; 0 <= i < len ==> s[i] % 3 != 0;
  ensures \result == true;
  assigns \nothing;
*/
bool check_vector(int *s, int len)
{
    //@ assert !contains_even(len, s);
    //@ assert !contains_multiple_of_3(len, s);
    return true;
}

int main()
{
    int v[3];
    v[0] = 1;
    v[1] = 5;
    v[2] = 7;
    
    //@ assert \forall integer i; 0 <= i < 3 ==> v[i] % 2 != 0;
    //@ assert \forall integer i; 0 <= i < 3 ==> v[i] % 3 != 0;
    
    bool result = check_vector(&v[0], 3);
    //@ assert result == true;
    return 0;
}
