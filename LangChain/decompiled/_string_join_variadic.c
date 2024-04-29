
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8
_string_join_variadic
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,ulong param_9,
          undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,
          undefined8 param_14)

{
  char in_AL;
  long *local_158;
  long *local_140;
  long local_128 [4];
  undefined8 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  undefined4 local_e8;
  undefined4 local_d8;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_a8;
  undefined4 local_98;
  undefined4 local_88;
  undefined8 local_78;
  undefined8 *local_70;
  ulong local_68;
  undefined *local_60;
  undefined *local_58;
  long local_50;
  ulong local_48;
  long local_40;
  ulong local_38;
  undefined8 local_30;
  uint local_28;
  undefined4 local_24;
  long *local_20;
  long *local_18;
  long local_10;
  
  if (in_AL != '\0') {
    local_f8 = param_1;
    local_e8 = param_2;
    local_d8 = param_3;
    local_c8 = param_4;
    local_b8 = param_5;
    local_a8 = param_6;
    local_98 = param_7;
    local_88 = param_8;
  }
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  local_18 = local_128;
  local_20 = (long *)&stack0x00000008;
  local_24 = 0x30;
  local_28 = 8;
  local_40 = 0;
  for (local_48 = 0; local_48 < param_9; local_48 = local_48 + 1) {
    if (local_28 < 0x29) {
      local_140 = (long *)((long)local_18 + (long)(int)local_28);
      local_28 = local_28 + 8;
    }
    else {
      local_140 = local_20;
      local_20 = local_20 + 1;
    }
    local_50 = *local_140;
    local_40 = *(long *)(local_50 + 8) + local_40;
  }
  local_128[1] = param_10;
  local_128[2] = param_11;
  local_128[3] = param_12;
  local_108 = param_13;
  local_100 = param_14;
  local_38 = param_9;
  local_58 = (undefined *)_malloc(local_40 + 1);
  if (local_58 == (undefined *)0x0) {
    _perror("Failed to allocate memory in string_join_variadic");
    local_30 = 0;
  }
  else {
    local_18 = local_128;
    local_20 = (long *)&stack0x00000008;
    local_24 = 0x30;
    local_28 = 8;
    local_60 = local_58;
    for (local_68 = 0; local_68 < local_38; local_68 = local_68 + 1) {
      if (local_28 < 0x29) {
        local_158 = (long *)((long)local_18 + (long)(int)local_28);
        local_28 = local_28 + 8;
      }
      else {
        local_158 = local_20;
        local_20 = local_20 + 1;
      }
      local_70 = (undefined8 *)*local_158;
      ___memcpy_chk(local_60,*local_70,local_70[1],0xffffffffffffffff);
      local_60 = local_60 + local_70[1];
    }
    *local_60 = 0;
    local_78 = _string_create(local_58);
    _free(local_58);
    local_30 = local_78;
  }
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return local_30;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

