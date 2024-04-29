
void _string_format(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                   long param_9,long param_10,undefined8 param_11,undefined8 param_12,
                   undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  undefined local_f8 [16];
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_a8;
  undefined4 local_98;
  undefined4 local_88;
  undefined4 local_78;
  undefined4 local_68;
  undefined4 local_58;
  void *local_48;
  int local_3c;
  long local_38;
  long local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined *local_20;
  undefined *local_18;
  long local_10;
  
  if (in_AL != '\0') {
    local_c8 = param_1;
    local_b8 = param_2;
    local_a8 = param_3;
    local_98 = param_4;
    local_88 = param_5;
    local_78 = param_6;
    local_68 = param_7;
    local_58 = param_8;
  }
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  local_e8 = param_11;
  local_e0 = param_12;
  local_d8 = param_13;
  local_d0 = param_14;
  local_38 = param_10;
  local_30 = param_9;
  if (param_9 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_format.\n");
  }
  else if (param_10 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The format string is NULL in string_format.\n");
  }
  else {
    local_18 = local_f8;
    local_20 = &stack0x00000008;
    local_24 = 0x30;
    local_28 = 0x10;
    local_3c = ___vsnprintf_chk(0,0,0,0xffffffffffffffff,param_10,&local_28);
    if (local_3c < 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: vsnprintf failed in string_format.\n");
    }
    else {
      local_48 = _malloc((long)(local_3c + 1));
      if (local_48 == (void *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Failed to allocate memory in string_format.\n");
      }
      else {
        ___vsnprintf_chk(local_48,(long)(local_3c + 1),0,0xffffffffffffffff,local_38,&local_28);
        _string_assign(local_30,local_48);
        _free(local_48);
      }
    }
  }
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

