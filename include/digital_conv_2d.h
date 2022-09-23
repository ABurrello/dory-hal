#include "utils.h"
#include "digital_encoder_instruction_memory.h"

int32_t digital_conv_2d(const void *input_L2, 
                const void *input,
                const void *weights_L2,
                const void *weights, 
                void *output,
                const int input_L1,
                Layer_parameters * layer);