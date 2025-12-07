#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

void disassembleChunk(Chunk* chuk, const char* name);
int disassmbleInstruction(Chunk* chunk, int offset);

static int constantInstruction(const char* name, Chunk* chunk, int offset);
static int simpleInstruction(const char* name, int offset);

#endif
