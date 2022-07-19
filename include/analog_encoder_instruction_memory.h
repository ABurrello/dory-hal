#include "utils.h"

#ifndef INSTR_TYPE_H
#define INSTR_TYPE_H
typedef enum Instruction_type {
    STOP,            
    CONV,
    TO_DO,
    EWS
} Instruction_type;
#endif

void analog_encoder_instruction_memory(
    uint32_t pointer_input,
    uint32_t pointer_weights,
    uint32_t pointer_output,
    Layer_parameters * layer);
