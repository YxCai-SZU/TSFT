#include <stdbool.h>

/*@
  requires 1 <= A && A <= 10000;
  requires 1 <= B && B <= 10000;
  requires 1 <= C && C <= 10000;
  requires 1 <= D && D <= 10000;
  ensures \result == true <==> (((A) > (B) ? (A) - (B) : (B) - (A)) <= (D) ||
      ((B) > (C) ? (B) - (C) : (C) - (B)) <= (D) ||
      ((C) > (D) ? (C) - (D) : (D) - (C)) <= (D));
*/
bool func(unsigned int A, unsigned int B, unsigned int C, unsigned int D)
{
    unsigned int diff1;
    unsigned int diff2;
    unsigned int diff3;
    bool result;

    diff1 = (A > B) ? (A - B) : (B - A);
    diff2 = (B > C) ? (B - C) : (C - B);
    diff3 = (C > D) ? (C - D) : (D - C);

    if (diff1 <= D)
    {
        result = true;
        //@ assert (((A) > (B) ? (A) - (B) : (B) - (A)) <= (D) ||       ((B) > (C) ? (B) - (C) : (C) - (B)) <= (D) ||       ((C) > (D) ? (C) - (D) : (D) - (C)) <= (D));
        return result;
    }
    else if (diff2 <= D)
    {
        result = true;
        //@ assert (((A) > (B) ? (A) - (B) : (B) - (A)) <= (D) ||       ((B) > (C) ? (B) - (C) : (C) - (B)) <= (D) ||       ((C) > (D) ? (C) - (D) : (D) - (C)) <= (D));
        return result;
    }
    else if (diff3 <= D)
    {
        result = true;
        //@ assert (((A) > (B) ? (A) - (B) : (B) - (A)) <= (D) ||       ((B) > (C) ? (B) - (C) : (C) - (B)) <= (D) ||       ((C) > (D) ? (C) - (D) : (D) - (C)) <= (D));
        return result;
    }

    //@ assert diff1 > D && diff2 > D && diff3 > D;
    result = false;
    //@ assert !(((A) > (B) ? (A) - (B) : (B) - (A)) <= (D) ||       ((B) > (C) ? (B) - (C) : (C) - (B)) <= (D) ||       ((C) > (D) ? (C) - (D) : (D) - (C)) <= (D));
    return result;
}
