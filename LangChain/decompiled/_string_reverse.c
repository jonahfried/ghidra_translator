
void _string_reverse(long *param_1)

{
  void *pvVar1;
  undefined8 uVar2;
  int local_20;
  int local_1c;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_reverse.\n");
  }
  else {
    pvVar1 = _malloc(param_1[1] + 1);
    if (pvVar1 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_reverse.\n");
    }
    else {
      local_1c = (int)param_1[1];
      local_20 = 0;
      while (local_1c = local_1c + -1, -1 < local_1c) {
        *(undefined *)((long)pvVar1 + (long)local_20) = *(undefined *)(*param_1 + (long)local_1c);
        local_20 = local_20 + 1;
      }
      *(undefined *)((long)pvVar1 + param_1[1]) = 0;
      uVar2 = _string_c_str(param_1);
      _string_replace(param_1,uVar2,pvVar1);
      _free(pvVar1);
    }
  }
  return;
}

