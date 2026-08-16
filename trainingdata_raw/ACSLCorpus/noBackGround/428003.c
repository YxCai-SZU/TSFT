/*@
  requires (3 * (j) + 4 > (j) - 2);
  ensures (3 * (j) + 4 > (j) - 2);
*/
void example(int j)
{
  //@ assert (3 * (j) + 4 > (j) - 2);
  //@ assert (3 * (j) + 4 > (j) - 2);
}
