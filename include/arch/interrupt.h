#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>
#include <stdbool.h>

#include <config.h>
#include <arch/cpu.h>

typedef uint8_t interrupt_vector_t;
typedef struct interrupt_stack_frame_t interrupt_stack_frame_t;

typedef uint64_t (*interrupt_handler_t)(
    interrupt_vector_t vector,
    uint64_t error_code,
    registers_t *registers,
    interrupt_stack_frame_t *interrupt_stack_frame
    );

static inline void interrupt_flag_set();
static inline void interrupt_flag_clear();

typedef bool interrupt_state_t;

static inline interrupt_state_t interrupt_state_get();
static inline void interrupt_state_restore(interrupt_state_t state);
static inline interrupt_state_t interrupt_enable();
static inline interrupt_state_t interrupt_disable();

typedef void (*interrupt_rpc_t)(
    registers_t *registers,
    interrupt_stack_frame_t *interrupt_stack_frame,
    uint64_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t e
    );

void interrupt_rpc(interrupt_rpc_t rpc, uint64_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t e);

#include <arch/x86_64/interrupt.h>

#endif
