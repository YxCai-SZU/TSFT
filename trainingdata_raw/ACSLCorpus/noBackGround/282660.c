#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100) && (1 <= (D) <= 100);
    ensures ((\result) == true <==> ((((A)) <= ((C)) <= ((B))) || (((A)) <= ((D)) <= ((B)))));
*/
bool func(int A, int B, int C, int D)
{
    bool is_ok = false;
    
    //@ assert (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100) && (1 <= (D) <= 100);
    
    if (A <= C && C <= B)
    {
        is_ok = true;
    }
    
    //@ assert is_ok == true <==> ((A) <= (C) <= (B)) || (is_ok == true && ((A) <= (D) <= (B)));
    
    if (A <= D && D <= B)
    {
        is_ok = true;
    }
    
    //@ assert ((is_ok) == true <==> ((((A)) <= ((C)) <= ((B))) || (((A)) <= ((D)) <= ((B)))));
    
    return is_ok;
}
