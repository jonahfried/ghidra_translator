
void _string_resize(long *param_1,ulong param_2)

{
  long lVar1;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_resize.\n");
  }
  else if (param_2 < (ulong)param_1[1]) {
    param_1[1] = param_2;
    *(undefined *)(*param_1 + param_2) = 0;
  }
  else if ((ulong)param_1[1] < param_2) {
    if ((ulong)param_1[2] <= param_2) {
      lVar1 = _memory_pool_allocate(param_1[3],param_2 + 1);
      if (lVar1 == 0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_resize.\n");
        return;
      }
      ___memcpy_chk(lVar1,*param_1,param_1[1],0xffffffffffffffff);
      *param_1 = lVar1;
      param_1[2] = param_2 + 1;
    }
    ___memset_chk(*param_1 + param_1[1],0,param_2 - param_1[1],0xffffffffffffffff);
    param_1[1] = param_2;
  }
  return;
}

