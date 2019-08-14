//
// Created by zf on 2019-08-14.
//

#include "core.h"

void print_prompt() { printf("db > "); }

MetaCommandResult do_meta_command(InputBuffer* input_buffer) {
    if (strcmp(input_buffer->buffer, ".exit") == 0) {
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

void serialize_row(Row* source, void* destination) {
    memcpy((uint32_t*)destination + ID_OFFSET, &(source->id), ID_SIZE);
    memcpy((uint32_t*)destination + USERNAME_OFFSET, &(source->username),
           USERNAME_SIZE);
    memcpy((uint32_t*)destination + EMAIL_OFFSET, &(source->email), EMAIL_SIZE);
}

void deserialize_row(void* source, Row* destination) {
    memcpy(&(destination->id), (uint32_t*)source + ID_OFFSET, ID_SIZE);
    memcpy(&(destination->username), (uint32_t*)source + USERNAME_OFFSET,
           USERNAME_SIZE);
    memcpy(&(destination->email), (uint32_t*)source + EMAIL_OFFSET, EMAIL_SIZE);
}

ExecuteResult execute_insert(Statement* statement, Table* table) {
    if (table->num_rows >= TABLE_MAX_ROWS) {
        return EXECUTE_TABLE_FULL;
    }

    Row* row_to_insert = &(statement->row_to_insert);

    serialize_row(row_to_insert, row_slot(table, table->num_rows));
    table->num_rows += 1;

    return EXECUTE_SUCCESS;
}

ExecuteResult execute_select(Statement* statement, Table* table) {
    Row row;
    for (uint32_t i = 0; i < table->num_rows; i++) {
        deserialize_row(row_slot(table, i), &row);
        print_row(&row);
    }
    return EXECUTE_SUCCESS;
}

ExecuteResult execute_statement(Statement* statement, Table* table) {
    switch (statement->type) {
        case STATEMENT_INSERT:
            return execute_insert(statement, table);
        case STATEMENT_SELECT:
            return execute_select(statement, table);
    }
}