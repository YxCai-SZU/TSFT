// Generated C + ACSL

/*@
    requires z1_len > 10;
    requires z1 != \null;
    requires \valid(z1 + (0 .. z1_len-1));
    requires z1[0] == 7;
    requires z2_len > 10;
    requires z2 != \null;
    requires \valid(z2 + (0 .. z2_len-1));
    requires z2[0] == 17;
    assigns z2[0 .. z2_len-1];
*/
void mm(int* z1, int z1_len, int* z2, int z2_len)
{
  int* a = z1;
  /*@ assert (a[0] == 7); */
  a = z2;
  /*@ assert (a[0] == 17); */
  int old_a0 = a[0];
  /*@ assert (old_a0 == 17); */
  z2[0] = 27;
  /*@ assert (old_a0 == 17); */
  /*@ assert (a[0] == 27); */
}