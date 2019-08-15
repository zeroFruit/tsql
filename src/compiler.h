//
// Created by zf on 2019-08-14.
//

#ifndef COMPILER_H
#define COMPILER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();

void read_input(InputBuffer* input_buffer);

void close_input_buffer(InputBuffer* input_buffer);


typedef enum {
    PREPARE_SUCCESS,
    PREPARE_NEGATIVE_ID,
    PREPARE_STRING_TOO_LONG,
    PREPARE_SYNTAX_ERROR,
    PREPARE_UNRECOGNIZED_STATEMENT,
} PrepareResult_t;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT,
} StatementType_t;

typedef struct {
    StatementType_t type;
    Row row_to_insert;  // only used by insert statement
} Statement;

PrepareResult_t prepare_insert(InputBuffer* input_buffer,
                               Statement* statement);

PrepareResult_t prepare_statement(InputBuffer* input_buffer,
                                  Statement* statement);


#endif //COMPILER_H
