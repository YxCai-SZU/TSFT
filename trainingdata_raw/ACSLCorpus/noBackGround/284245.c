#include <stdbool.h>

/*@ requires 
      \forall integer i; 0 <= i < 3 ==> ('0' <= (n[i]) && (n[i]) <= '9'); 
    ensures 
      \result == true <==> ((n[0]) == (n[2]) && (n[1]) != '0'); */
bool is_palindrome(char n[3])
{
    char a;
    char b;
    char c;
    
    a = n[0];
    b = n[1];
    c = n[2];
    
    //@ assert n[0] == a;
    //@ assert n[1] == b;
    //@ assert n[2] == c;
    
    return a == c && b != '0';
}

int main() {
    return 0;
}
