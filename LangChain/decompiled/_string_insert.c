
void _string_insert(long *param_1,ulong param_2,char *param_3)

{
  size_t sVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_insert.\n");
  }
  else if (param_3 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The strItem is NULL in string_insert.\n");
  }
  else if ((ulong)param_1[1] < param_2) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Position out of bounds in string_insert.\n")
    ;
  }
  else {
    sVar1 = _strlen(param_3);
    lVar2 = param_1[1] + sVar1;
    if ((ulong)param_1[2] < lVar2 + 1U) {
      lVar3 = _memory_pool_allocate(param_1[3],lVar2 + 1);
      if (lVar3 == 0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_insert.\n");
        return;
      }
      ___memcpy_chk(lVar3,*param_1,param_2,0xffffffffffffffff);
      ___memcpy_chk(lVar3 + param_2 + sVar1,*param_1 + param_2,param_1[1] - param_2,
                    0xffffffffffffffff);
      *param_1 = lVar3;
      param_1[2] = lVar2 + 1;
    }
    else {
      ___memmove_chk(*param_1 + param_2 + sVar1,*param_1 + param_2,param_1[1] - param_2,
                     0xffffffffffffffff);
    }
    ___memcpy_chk(*param_1 + param_2,param_3,sVar1,0xffffffffffffffff);
    param_1[1] = lVar2;
  }
  return;
}

