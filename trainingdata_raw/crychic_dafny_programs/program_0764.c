// Generated C + ACSL

/*@
    requires x_skew != \null;
    requires \valid(x_skew + (0 .. 8));
    requires x_skew[1*3 + 0] == -x_skew[0*3 + 1];
    requires x_skew[2*3 + 0] == -x_skew[0*3 + 2];
    requires x_skew[2*3 + 1] == -x_skew[1*3 + 2];
    requires x_skew[0*3 + 1] == -x_skew[1*3 + 0];
    requires x_skew[0*3 + 2] == -x_skew[2*3 + 0];
    requires x_skew[1*3 + 2] == -x_skew[2*3 + 1];
    requires x != \null;
    requires \valid(x + (0 .. 2));
    requires \separated(x + (0 .. 2), x_skew + (0 .. 8));
    assigns x[0 .. 2];
    ensures x[0] == -x_skew[1*3 + 2];
    ensures x[1] == x_skew[0*3 + 2];
    ensures x[2] == -x_skew[0*3 + 1];
*/
int* SO3_to_R3(int* x_skew, int* x)
{
  x[0] = -x_skew[1*3 + 2];
  //@ assert x[0] == -x_skew[1*3 + 2];
  //@ assert x[0] == -x_skew[5];
  
  x[1] = x_skew[0*3 + 2];
  //@ assert x[1] == x_skew[0*3 + 2];
  //@ assert x[1] == x_skew[2];
  
  x[2] = -x_skew[0*3 + 1];
  //@ assert x[2] == -x_skew[0*3 + 1];
  //@ assert x[2] == -x_skew[1];
  
  //@ assert x[0] == -x_skew[1*3 + 2];
  //@ assert x[1] == x_skew[0*3 + 2];
  //@ assert x[2] == -x_skew[0*3 + 1];
  
  return x;
}