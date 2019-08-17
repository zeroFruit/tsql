//
// Created by zf on 2019-08-14.
//

#ifndef TSQL_TABLE_H
#define TSQL_TABLE_H

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "row.h"
#include "btree.h"

#define TABLE_MAX_PAGES 100

typedef struct {
    int file_descriptor;
    uint32_t file_length;
    uint32_t num_pages;
    void* pages[TABLE_MAX_PAGES];
} Pager;

void* get_page(Pager* pager, uint32_t page_num);

static const uint32_t PAGE_SIZE = 4096;

typedef struct {
    uint32_t root_page_num;
    Pager* pager;
} Table;

Table* db_open(const char* filename);
void db_close(Table* table);

void free_table(Table* table);

typedef struct {
  Table* table;
  uint32_t page_num;
  uint32_t cell_num;
  bool end_of_table; // Indicates a position one past the last element
} Cursor;

Cursor* table_start(Table* table);
Cursor* table_find(Table* table, uint32_t key);

void* cursor_value(Cursor* cursor);

void cursor_advance(Cursor* cursor);

void leaf_node_insert(Cursor* cursor, uint32_t key, Row* value);

#endif //TSQL_TABLE_H
