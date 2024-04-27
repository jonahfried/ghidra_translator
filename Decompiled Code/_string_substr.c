
void ** _string_substr(long *param_1,ulong param_2,void *param_3)

{
  void *pvVar1;
  void *local_28;
  void **local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_substr.\n");
    local_10 = (void **)0x0;
  }
  else if (param_2 < (ulong)param_1[1]) {
    local_28 = param_3;
    if ((ulong)param_1[1] < param_2 + (long)param_3) {
      local_28 = (void *)(param_1[1] - param_2);
    }
    local_10 = (void **)_string_create(0);
    if (local_10 == (void **)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed for substring in string_substr.\n");
      local_10 = (void **)0x0;
    }
    else {
      local_10[1] = local_28;
      local_10[2] = (void *)((long)local_28 + 1);
      pvVar1 = _malloc((size_t)local_10[2]);
      *local_10 = pvVar1;
      if (*local_10 == (void *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed for dataStr in substring in string_substr.\n");
        _free(local_10);
        local_10 = (void **)0x0;
      }
      else {
        ___strncpy_chk(*local_10,*param_1 + param_2,local_28,0xffffffffffffffff);
        *(undefined *)((long)*local_10 + (long)local_28) = 0;
      }
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Position out of bounds in string_substr.\n")
    ;
    local_10 = (void **)0x0;
  }
  return local_10;
}

