// Generated C + ACSL

/*@
    requires v != \null;
    requires v_len > 0;
    requires 0 <= i < v_len && 0 <= j < v_len;
    requires \valid(v + (0 .. v_len-1));
    assigns v[i], v[j];
    ensures v[i] == \old(v[j]);
    ensures v[j] == \old(v[i]);
    ensures \forall integer k; 0 <= k < v_len && k != i && k != j ==> v[k] == \old(v[k]);
*/
void swap(int* v, int v_len, int i, int j)
{
  int aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

/*@
  predicate par(integer n) =
    n % 2 == 0;
*/

/*@
    requires v != \null;
    requires v_len > 0;
    requires \valid_read(v + (0 .. v_len-1));
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer w; 0 <= w < v_len ==> v[w] % 2 == 0);
    ensures \result == 0 <==> (\exists integer w; 0 <= w < v_len && v[w] % 2 != 0);
*/
int verificaPar(int* v, int v_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= v_len;
  loop invariant \forall integer w; 0 <= w < i ==> (v[w] % 2) == 0;
  loop assigns i;
  loop variant v_len - i;
*/
  while (((i < v_len) && ((v[i] % 2) == 0)))
    {
      i = (i + 1);
    }
  int b = (i == v_len);
  /*@ assert b >= 0 && b <= 2147483647; */
  return b;  // Dafny implicit return
}

/*@
    requires v != \null;
    requires v_len > 0;
    requires \valid_read(v + (0 .. v_len-1));
    assigns \nothing;
    ensures \forall integer w; 0 <= w < v_len ==> \result >= v[w];
    ensures \exists integer k; 0 <= k < v_len && v[k] == \result;
*/
int maximo(int* v, int v_len)
{
  int i = 1;
  int m = v[0];
/*@
  loop invariant 1 <= i <= v_len;
  loop invariant \forall integer k; 0 <= k < i ==> m >= v[k];
  loop invariant \exists integer k; 0 <= k < i && m == v[k];
  loop invariant \forall integer k; 0 <= k < v_len ==> m >= v[k] || i <= k;
  loop assigns i, m;
  loop variant v_len - i;
*/
  while ((i < v_len))
    {
      if ((m < v[i]))
      {
        m = v[i];
        /*@ assert m == v[i]; */
        /*@ assert \exists integer k; 0 <= k <= i && m == v[k]; */
      }
      /*@ assert \forall integer k; 0 <= k <= i ==> m >= v[k]; */
      i = (i + 1);
    }
  /*@ assert i == v_len; */
  /*@ assert \forall integer k; 0 <= k < v_len ==> m >= v[k]; */
  /*@ assert \exists integer k; 0 <= k < v_len && m == v[k]; */
  return m;  // Dafny implicit return
}