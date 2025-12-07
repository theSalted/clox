#include <stdint.h>
#include <stdio.h>

#include "debug.h"
#include "chunk.h"
#include "value.h"

void disassembleChunk(Chunk *chunk, const char *name) {
  printf("== %s ==\n", name);
  for (int offset = 0; offset < chunk->count;) {
    offset = disassmbleInstruction(chunk, offset);
  }
}


int disassmbleInstruction(Chunk *chunk, int offset) {
  printf("%04d ", offset);

  uint8_t instriction = chunk->code[offset];
  switch (instriction) {
    case OP_CONSTANT:
    return constantInstruction("OP_CONSTANT", chunk, offset);
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    default:
      printf("Unknown opcode %d\n", instriction);
      return offset + 1;
  }
}

static int constantInstruction(const char* name, Chunk* chunk, int offset) {
  uint8_t constant = chunk->code[offset + 1];
  printf("%-16s %4d '", name, constant);
  printValue(chunk->constants.values[constant]);
  printf("'\n");
  return offset + 2;
}

static int simpleInstruction(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}
