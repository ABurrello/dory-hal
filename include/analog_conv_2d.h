#include "utils.h"
#include "analog_encoder_instruction_memory.h"

int32_t analog_conv_2d(const void *input_L2, 
                const void *input,
                const void *weights_L2,
                const void *batchnorm_L2,
                const void *weights, 
                void *output,
                Layer_parameters * layer);