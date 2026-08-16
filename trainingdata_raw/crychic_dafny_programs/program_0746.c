// Generated C + ACSL

typedef struct {
    char* name;
    int name_len;
} Column;

typedef struct {
    char* name;
    int name_len;
    Column* columns;
    int columns_len;
} Table;

int FindTable(Table* tables, int tables_len, char* name, int name_len);
void AddColumn(Table* table, Column column);
void DropColumn(Table* table, char* columnName, int columnName_len);

/*@
    requires tables_len > 0;
    requires tables != \null;
    requires \valid(tables + (0 .. tables_len-1));
    requires \forall integer k; 0 <= k < tables_len ==> \valid(tables[k].name + (0 .. tables[k].name_len-1));
    requires \forall integer k; 0 <= k < tables_len ==> tables[k].columns_len >= 0;
    requires \forall integer k; 0 <= k < tables_len ==> 
             (tables[k].columns_len > 0 ==> \valid(tables[k].columns + (0 .. tables[k].columns_len-1)));
    assigns tables[0 .. tables_len-1];
*/
void Upgrade(Table* tables, int tables_len)
{
  int trailTableIdx = FindTable(tables, tables_len, "trail", 5);
  if ((trailTableIdx >= 0))
  {
    /*@ assert 0 <= trailTableIdx < tables_len; */
    /*@ assert \valid(&tables[trailTableIdx]); */
    Column geomColumn;
    geomColumn.name = "geom";
    geomColumn.name_len = 4;
    AddColumn(&tables[trailTableIdx], geomColumn);
  }
}

/*@
    requires tables != \null;
    requires tables_len > 0;
    requires \valid(tables + (0 .. tables_len-1));
    requires \forall integer k; 0 <= k < tables_len ==> \valid(tables[k].name + (0 .. tables[k].name_len-1));
    requires \forall integer k; 0 <= k < tables_len ==> tables[k].columns_len >= 0;
    requires \forall integer k; 0 <= k < tables_len ==> 
             (tables[k].columns_len > 0 ==> \valid(tables[k].columns + (0 .. tables[k].columns_len-1)));
    requires \forall integer k; 0 <= k < tables_len ==> 
             (tables[k].columns_len > 0 ==> 
              \forall integer j; 0 <= j < tables[k].columns_len ==> 
                \valid(tables[k].columns[j].name + (0 .. tables[k].columns[j].name_len-1)));
    assigns tables[0 .. tables_len-1];
*/
void Downgrade(Table* tables, int tables_len)
{
  int trailTableIdx = FindTable(tables, tables_len, "trail", 5);
  if ((trailTableIdx >= 0))
  {
    /*@ assert 0 <= trailTableIdx < tables_len; */
    /*@ assert \valid(&tables[trailTableIdx]); */
    /*@ assert tables[trailTableIdx].columns_len >= 0; */
    /*@ assert tables[trailTableIdx].columns_len > 0 ==> 
               \valid(tables[trailTableIdx].columns + (0 .. tables[trailTableIdx].columns_len-1)); */
    DropColumn(&tables[trailTableIdx], "geom", 4);
  }
}

/*@
    requires tables != \null;
    requires tables_len > 0;
    requires \valid_read(tables + (0 .. tables_len-1));
    requires name != \null;
    requires name_len >= 0;
    requires \valid_read(name + (0 .. name_len-1));
    ensures -1 <= \result < tables_len;
    assigns \nothing;
*/
int FindTable(Table* tables, int tables_len, char* name, int name_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= tables_len;
  loop invariant \valid_read(tables + (0..tables_len-1));
  loop invariant \valid_read(name + (0..name_len-1));
  loop assigns i;
  loop variant tables_len - i;
*/
  while ((i < tables_len))
    {
      /*@ assert 0 <= i < tables_len; */
      /*@ assert \valid_read(&tables[i]); */
      if ((tables[i].name == name))
      {
        /*@ assert 0 <= i < tables_len; */
        return i;
      }
      i = (i + 1);
    }
  /*@ assert i == tables_len; */
  return -1;
}

/*@
    requires \valid(table);
    requires table->columns_len >= 0;
    assigns table->columns_len;
*/
void AddColumn(Table* table, Column column)
{
  table->columns_len = (table->columns_len + 1);
}

/*@
    requires \valid(table);
    requires table->columns_len >= 0;
    requires table->columns_len > 0 ==> \valid(table->columns + (0 .. table->columns_len-1));
    requires \valid_read(columnName + (0 .. columnName_len-1));
    requires columnName_len >= 0;
    assigns table->columns_len;
    ensures table->columns_len >= 0;
    ensures table->columns_len <= \old(table->columns_len);
*/
void DropColumn(Table* table, char* columnName, int columnName_len)
{
  int newColumnsCount = 0;
  int i = 0;
/*@
  loop invariant 0 <= i <= table->columns_len;
  loop invariant 0 <= newColumnsCount <= i;
  loop invariant table->columns_len >= 0;
  loop invariant table->columns_len == \at(table->columns_len, Pre);
  loop invariant table->columns_len > 0 ==> \valid(table->columns + (0 .. table->columns_len-1));
  loop assigns i, newColumnsCount;
  loop variant table->columns_len - i;
*/
  while ((i < table->columns_len))
    {
      /*@ assert 0 <= i < table->columns_len; */
      /*@ assert \valid(&table->columns[i]); */
      if ((table->columns[i].name != columnName))
      {
        newColumnsCount = (newColumnsCount + 1);
      }
      i = (i + 1);
      /*@ assert 0 <= newColumnsCount <= i; */
    }
  /*@ assert i == table->columns_len; */
  /*@ assert 0 <= newColumnsCount <= table->columns_len; */
  table->columns_len = newColumnsCount;
}