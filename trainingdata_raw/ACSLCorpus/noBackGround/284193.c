#include <stddef.h>

/*@ requires 
      (2 <= (len) && (len) <= 50) && 
      (\forall integer i; 0 <= i < (len) ==> (((v)[i]) == 0 || ((v)[i]) == 1)) && 
      \valid(v + (0 .. len-1)); 
    ensures 
      \result >= 0 && 
      \result <= (int)len && 
      (\forall integer i; 0 <= i < len ==> (v[i] == 1 ==> \result > 0)); */
int func(int *v, size_t len)
{
    int count = 0;
    size_t index = 0;

    /*@ loop invariant 
          0 <= index <= len && 
          0 <= count <= (int)index && 
          (\forall integer i; 0 <= i < index ==> (v[i] == 1 ==> count > 0)) && 
          (\forall integer i; 0 <= i < (len) ==> (((v)[i]) == 0 || ((v)[i]) == 1)) && 
          (2 <= (len) && (len) <= 50); 
        loop assigns index, count; 
        loop variant len - index; */
    while (index < len)
    {
        //@ assert (\forall integer i; 0 <= i < (len) ==> (((v)[i]) == 0 || ((v)[i]) == 1));
        if (v[index] == 1)
        {
            count += 1;
        }
        index += 1;
    }
    return count;
}
