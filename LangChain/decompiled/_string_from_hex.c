
long _string_from_hex(long *param_1)

{
  ulong uVar1;
  long lVar2;
  char local_2b;
  undefined local_2a;
  undefined local_29;
  ulong local_28;
  long local_20;
  long *local_18;
  long local_10;
  
  local_18 = param_1;
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_from_hex.\n");
    local_10 = 0;
  }
  else {
    uVar1 = _string_empty(param_1);
    if (((uVar1 & 1) == 0) && ((local_18[1] & 1U) == 0)) {
      local_20 = _string_create("");
      if (local_20 == 0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_from_hex.\n");
        local_10 = 0;
      }
      else {
        for (local_28 = 0; local_28 < (ulong)local_18[1]; local_28 = local_28 + 2) {
          local_2b = *(char *)(*local_18 + local_28);
          local_2a = *(undefined *)(*local_18 + 1 + local_28);
          local_29 = 0;
          lVar2 = _strtol(&local_2b,(char **)0x0,0x10);
          _string_push_back(local_20,(int)(char)lVar2);
        }
        local_10 = local_20;
      }
    }
    else {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Invalid hex string in string_from_hex.\n")
      ;
      local_10 = 0;
    }
  }
  return local_10;
}

