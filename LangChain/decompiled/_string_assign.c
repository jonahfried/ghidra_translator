
void _string_assign(long *param_1,char *param_2)

{
  size_t sVar1;
  long lVar2;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_assign.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The newStr is NULL in string_assign.\n");
  }
  else {
    sVar1 = _strlen(param_2);
    if ((ulong)param_1[2] < sVar1 + 1) {
      lVar2 = _memory_pool_allocate(param_1[3],sVar1 + 1);
      if (lVar2 == 0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_assign.\n");
        return;
      }
      *param_1 = lVar2;
      param_1[2] = sVar1 + 1;
    }
    ___strcpy_chk(*param_1,param_2,0xffffffffffffffff);
    param_1[1] = sVar1;
  }
  return;
}

