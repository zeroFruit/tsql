//
// Created by zf on 2019-08-15.
//

#ifndef TSQL_BTREE_H
#define TSQL_BTREE_H

#include <stdint.h>

#include "row.h"
#include "table.h"

typedef enum {
  NODE_INTERNAL,
  NODE_LEAF
} NodeType;

/*
 * Common Node Header Layout
 * */
extern const uint32_t NODE_TYPE_SIZE;
extern const uint32_t NODE_TYPE_OFFSET;
extern const uint32_t IS_ROOT_SIZE;
extern const uint32_t IS_ROOT_OFFSET;
extern const uint32_t PARENT_POINTER_SIZE;
extern const uint32_t PARENT_POINTER_OFFSET;
extern const uint8_t COMMON_NODE_HEADER_SIZE;

/*
 * Leaf Node Header Layout
 * */
extern const uint32_t LEAF_NODE_NUM_CELLS_SIZE;
extern const uint32_t LEAF_NODE_NUM_CELLS_OFFSET;
extern const uint32_t LEAF_NODE_HEADER_SIZE;

/*
 * Leaf Node Body Layout
 * */
extern const uint32_t LEAF_NODE_KEY_SIZE;
extern const uint32_t LEAF_NODE_KEY_OFFSET;
extern const uint32_t LEAF_NODE_VALUE_SIZE;
extern const uint32_t LEAF_NODE_VALUE_OFFSET;
extern const uint32_t LEAF_NODE_CELL_SIZE;
extern const uint32_t LEAF_NODE_SPACE_FOR_CELLS;
extern const uint32_t LEAF_NODE_MAX_CELLS;

uint32_t* leaf_node_num_cells(void* node);

void* leaf_node_cell(void* node, uint32_t cell_num);

uint32_t* leaf_node_key(void* node, uint32_t cell_num);

void* leaf_node_value(void* node, uint32_t cell_num);

void initialize_leaf_node(void* node);

NodeType get_node_type(void* node);
void set_node_type(void* node, NodeType type);

#endif //TSQL_BTREE_H
