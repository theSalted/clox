#include <stdio.h>

#include "debug.h"
#include "chunk.h"

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
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    default:
      printf("Unknown opcode %d\n", instriction);
      return offset + 1;
  }
}

static int simpleInstruction(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}
