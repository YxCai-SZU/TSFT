// Generated C + ACSL

/*@
    requires wxyz != \null;
    requires wxyz_len >= 0;
    requires \valid_read(wxyz + (0 .. wxyz_len-1));
    assigns \nothing;
    ensures \result == 1 <==>
        (\forall integer i; 0 <= i < wxyz_len ==>
            (wxyz[i] == '0' || wxyz[i] == '1' || wxyz[i] == '2' ||
             wxyz[i] == '3' || wxyz[i] == '4' || wxyz[i] == '5' ||
             wxyz[i] == '6' || wxyz[i] == '7' || wxyz[i] == '8' ||
             wxyz[i] == '9'));
    ensures \result == 0 || \result == 1;
*/
int pqrt(char* wxyz, int wxyz_len)
{
  int abcd = 1;
  /*@ assert abcd >= 0 && abcd <= 2147483647; */
  {
    int efgh = 0;
/*@
  loop invariant 0 <= efgh <= wxyz_len;
  loop invariant efgh == \at(efgh, LoopEntry) + (\at(efgh, LoopEntry) - \at(efgh, LoopEntry)) + (efgh - \at(efgh, LoopEntry));
  loop invariant \forall integer ijkl; 0 <= ijkl < efgh ==>
    (wxyz[ijkl] == '0' || wxyz[ijkl] == '1' || wxyz[ijkl] == '2' ||
     wxyz[ijkl] == '3' || wxyz[ijkl] == '4' || wxyz[ijkl] == '5' ||
     wxyz[ijkl] == '6' || wxyz[ijkl] == '7' || wxyz[ijkl] == '8' ||
     wxyz[ijkl] == '9');
  loop assigns efgh;
  loop variant wxyz_len - efgh;
*/
    while ((efgh < wxyz_len))
      {
        if (!(wxyz[efgh] == '0' || wxyz[efgh] == '1' || wxyz[efgh] == '2' ||
              wxyz[efgh] == '3' || wxyz[efgh] == '4' || wxyz[efgh] == '5' ||
              wxyz[efgh] == '6' || wxyz[efgh] == '7' || wxyz[efgh] == '8' ||
              wxyz[efgh] == '9'))
        {
          return 0;
        }
        efgh = (efgh + 1);
      }
  }
  return abcd;
}