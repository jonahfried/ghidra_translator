
void * _string_tokenize(undefined8 *param_1,char *param_2,undefined4 *param_3)

{
  char *pcVar1;
  undefined8 uVar2;
  ulong local_58;
  ulong local_50;
  char *local_40;
  ulong local_30;
  void *local_10;
  
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (char *)0x0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Invalid input in string_tokenize.\n");
    local_10 = (void *)0x0;
  }
  else {
    local_30 = 0;
    pcVar1 = (char *)_string_strdup(*param_1);
    if (pcVar1 == (char *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_tokenize.\n");
      local_10 = (void *)0x0;
    }
    else {
      local_40 = _strtok(pcVar1,param_2);
      while (local_40 != (char *)0x0) {
        local_30 = local_30 + 1;
        local_40 = _strtok((char *)0x0,param_2);
      }
      _free(pcVar1);
      local_10 = _malloc(local_30 << 3);
      if (local_10 == (void *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed for tokens in string_tokenize.\n");
        local_10 = (void *)0x0;
      }
      else {
        pcVar1 = (char *)_string_strdup(*param_1);
        if (pcVar1 == (char *)0x0) {
          _fprintf(*(FILE **)PTR____stderrp_10000a038,
                   "Error: Memory allocation failed in string_tokenize.\n");
          _free(local_10);
          local_10 = (void *)0x0;
        }
        else {
          local_40 = _strtok(pcVar1,param_2);
          local_50 = 0;
          while (local_40 != (char *)0x0 && local_50 < local_30) {
            uVar2 = _string_create(local_40);
            *(undefined8 *)((long)local_10 + local_50 * 8) = uVar2;
            if (*(long *)((long)local_10 + local_50 * 8) == 0) {
              _fprintf(*(FILE **)PTR____stderrp_10000a038,
                       "Error: string_create failed in string_tokenize.\n");
              for (local_58 = 0; local_58 < local_50; local_58 = local_58 + 1) {
                _string_deallocate(*(undefined8 *)((long)local_10 + local_58 * 8));
              }
              _free(local_10);
              _free(pcVar1);
              return (void *)0x0;
            }
            local_50 = local_50 + 1;
            local_40 = _strtok((char *)0x0,param_2);
          }
          _free(pcVar1);
          *param_3 = (int)local_30;
        }
      }
    }
  }
  return local_10;
}

