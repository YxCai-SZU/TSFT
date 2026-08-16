#include <stdbool.h>

/*@ requires 
      (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100) && (-100 <= (D) <= 100) && 
      A <= B && C <= D; 
    ensures 
      \result == ((B) * (D)) || 
      \result == ((B) * (C)) || 
      \result == ((A) * (D)) || 
      \result == ((A) * (C)); */
long func(long A, long B, long C, long D)
{
    long pattern[4];
    long max_val;
    int i;
    
    //@ assert (-10000 <= (((A) * (C))) <= 10000);
    //@ assert (-10000 <= (((A) * (D))) <= 10000);
    //@ assert (-10000 <= (((B) * (C))) <= 10000);
    //@ assert (-10000 <= (((B) * (D))) <= 10000);
    
    pattern[0] = A * C;
    pattern[1] = A * D;
    pattern[2] = B * C;
    pattern[3] = B * D;
    
    max_val = pattern[0];
    i = 1;
    
    /*@ loop invariant 
          1 <= i <= 4 &&
          pattern[0] == ((A) * (C)) &&
          pattern[1] == ((A) * (D)) &&
          pattern[2] == ((B) * (C)) &&
          pattern[3] == ((B) * (D)) &&
          (-10000 <= (pattern[0]) <= 10000) &&
          (-10000 <= (pattern[1]) <= 10000) &&
          (-10000 <= (pattern[2]) <= 10000) &&
          (-10000 <= (pattern[3]) <= 10000) &&
          (\exists integer j; 0 <= j < 4 && max_val == pattern[j]) &&
          (-10000 <= (max_val) <= 10000);
      loop assigns i, max_val;
      loop variant 4 - i; */
    while (i < 4) {
        if (pattern[i] > max_val) {
            max_val = pattern[i];
        }
        i++;
    }
    
    //@ assert max_val == pattern[0] || max_val == pattern[1] || max_val == pattern[2] || max_val == pattern[3];
    return max_val;
}

int main() {
    return 0;
}
