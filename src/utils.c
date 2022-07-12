#include "utils.h"

L2_DATA uint32_t configuration_register[16] = {0};
L2_DATA Instruction_memory_object instruction_memory_compiled[2] = {0};

void global_sync(){
  while (hwme_get_status() != 0);
}

