#include "utils.h"
#include "encoder_instruction_memory.h"

int32_t conv_2d(const void *input_L2, 
                const void *input,
                const void *weights_L2,
                const void *weights, 
                void *output,
                Layer_parameters * layer);