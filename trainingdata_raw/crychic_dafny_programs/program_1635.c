// Generated C + ACSL

/*@
    requires employees != \null;
    requires employees_len > 0;
    requires \valid_read(employees + (0 .. employees_len-1));
    assigns \nothing;
    ensures \forall integer i; 0 <= i < employees_len ==> employees[i] <= \result;
    ensures \exists integer i; 0 <= i < employees_len && employees[i] == \result;
*/
int MaxSalary(int* employees, int employees_len)
{
  int maxSal = employees[0];
  /*@ assert maxSal == employees[0]; */
  int i = 1;
/*@
  loop invariant 1 <= i <= employees_len;
  loop invariant \forall integer k; 0 <= k < i ==> employees[k] <= maxSal;
  loop invariant \exists integer k; 0 <= k < i && employees[k] == maxSal;
  loop invariant \forall integer k; 0 <= k < employees_len ==> employees[k] <= maxSal || i <= k;
  loop invariant maxSal == employees[0] || \exists integer k; 1 <= k < i && employees[k] == maxSal;
  loop assigns i, maxSal;
  loop variant employees_len - i;
*/
  while ((i < employees_len))
    {
      if ((employees[i] > maxSal))
      {
        maxSal = employees[i];
        /*@ assert maxSal == employees[i]; */
        /*@ assert \exists integer k; 0 <= k <= i && employees[k] == maxSal; */
      }
      /*@ assert \forall integer k; 0 <= k <= i ==> employees[k] <= maxSal; */
      /*@ assert \exists integer k; 0 <= k <= i && employees[k] == maxSal; */
      i = (i + 1);
    }
  /*@ assert i == employees_len; */
  /*@ assert \forall integer k; 0 <= k < employees_len ==> employees[k] <= maxSal; */
  /*@ assert \exists integer k; 0 <= k < employees_len && employees[k] == maxSal; */
  return maxSal;  // Dafny implicit return
}

// skipped function AverageSalaryByDepartment due to unsupported type