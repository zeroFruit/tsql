//
// Created by zf on 2019-08-15.
//

#include "row.h"

void print_row(Row* row) {
  printf("(%d, %s, %s)\n", row->id, row->username, row->email);
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