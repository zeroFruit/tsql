//
// Created by zf on 2019-08-14.
//

#ifndef TSQL_TABLE_H
#define TSQL_TABLE_H

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TABLE_MAX_PAGES 100

// HARDCODED!!
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

typedef struct {
    int file_descriptor;
    uint32_t file_length;
    void* pages[TABLE_MAX_PAGES];
} Pager;

typedef struct {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE + 1];
    char email[COLUMN_EMAIL_SIZE + 1];
} Row;

void print_row(Row* row);

#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

extern const uint32_t ID_SIZE;
extern const uint32_t USERNAME_SIZE;
extern const uint32_t EMAIL_SIZE;

extern const uint32_t ID_OFFSET;
extern const uint32_t USERNAME_OFFSET;
extern const uint32_t EMAIL_OFFSET;

extern const uint32_t ROW_SIZE;

extern const uint32_t PAGE_SIZE;
extern const uint32_t ROWS_PER_PAGE;
extern const uint32_t TABLE_MAX_ROWS;

typedef struct {
    uint32_t num_rows;
    Pager* pager;
} Table;

Table* db_open(const char* filename);
void db_close(Table* table);

void free_table(Table* table);


void* row_slot(Table* table, uint32_t row_num);

#endif //TSQL_TABLE_H
