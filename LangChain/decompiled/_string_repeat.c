
undefined8 _string_repeat(long *param_1,ulong param_2)

{
  undefined *puVar1;
  ulong local_40;
  undefined *local_38;
  undefined8 local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_repeat.\n");
    local_10 = 0;
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_repeat.\n");
    local_10 = 0;
  }
  else {
    puVar1 = (undefined *)_malloc(param_1[1] * param_2 + 1);
    if (puVar1 == (undefined *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Failed to allocate memory in string_repeat\n");
      local_10 = 0;
    }
    else {
      local_38 = puVar1;
      for (local_40 = 0; local_40 < param_2; local_40 = local_40 + 1) {
        ___memcpy_chk(local_38,*param_1,param_1[1],0xffffffffffffffff);
        local_38 = local_38 + param_1[1];
      }
      *local_38 = 0;
      local_10 = _string_create(puVar1);
      _free(puVar1);
    }
  }
  return local_10;
}

