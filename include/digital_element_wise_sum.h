#include "utils.h"
#include "digital_encoder_instruction_memory.h"

int32_t digital_element_wise_sum(const void *input_L2, 
                        const void *inputA,
                        const void *weights_2_L2, 
                        const void *inputB, 
                        void *output,
                        Layer_parameters * layer);