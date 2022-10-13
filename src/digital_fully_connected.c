#include <kernels.h>
#include "utils.h"

extern L2_DATA uint32_t configuration_register[16];
extern L2_DATA Instruction_memory_object_digital instruction_memory_compiled_digital[2];

// Warning: we already assume here that A and B have the same shape!
int32_t digital_fully_connected(const void *input_L2, 
                const void *input,
                const void *weights_L2,
                const void *weights, 
                void *output,
                Layer_parameters * layer) {
    return 0;
}