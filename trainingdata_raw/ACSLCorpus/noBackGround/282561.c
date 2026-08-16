#include <stdbool.h>

/*@
  requires ((1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100));
  ensures \result == true <==> (((c) >= (a)) && ((c) <= (b)));
*/
bool func(int a, int b, int c) {
    bool result;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    result = (c >= a && c <= b);
    return result;
}

/*@
  requires \valid(dest);
  ensures *dest >= \old(*dest);
  ensures *dest >= src || *dest == \old(*dest);
*/
void max_update(int* dest, int src) {
    int old_dest;
    old_dest = *dest;
    
    if (*dest < src) {
        *dest = src;
    }
    
    //@ assert *dest >= old_dest;
    //@ assert *dest >= src || *dest == old_dest;
}

/*@
  requires \valid(dest);
  ensures *dest <= \old(*dest);
  ensures *dest <= src || *dest == \old(*dest);
*/
void min_update(int* dest, int src) {
    int old_dest;
    old_dest = *dest;
    
    if (*dest > src) {
        *dest = src;
    }
    
    //@ assert *dest <= old_dest;
    //@ assert *dest <= src || *dest == old_dest;
}

/*@
  requires \valid(vec + (0 .. 2));
  ensures \forall integer i; 0 <= i && i < 2 ==> vec[i] == (i+1);
  ensures vec[2] == 10;
*/
void vector_example(int* vec) {
    int i;
    
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    
    //@ assert vec[0] == 1;
    //@ assert vec[1] == 2;
    //@ assert vec[2] == 3;
    
    vec[2] = 10;
    
    //@ assert vec[0] == 1;
    //@ assert vec[1] == 2;
    //@ assert vec[2] == 10;
}
