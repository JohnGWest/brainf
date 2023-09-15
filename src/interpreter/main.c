#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

void brainf_exec(char *code);

int main(int argc, char *argv[])
{
  char code[] = ",>,>,>,>,.<.<.<.<.";

  brainf_exec(code);

  return EXIT_SUCCESS;
}

void brainf_exec(char *code)
{
  printf("Made it?\n");
  fflush(stdout);
  size_t code_length = strlen(code);

  uint8_t memory[1024] = {0};
  size_t memory_index = 0;


  for (size_t i = 0; i < code_length; ++i)
  {
    switch (code[i])
    {
    case '+':
      memory[memory_index] += 1;
      break;
    case '-':
      memory[memory_index] -= 1;
      break;
    case '>':
      memory_index += 1;
      break;
    case '<':
      memory_index -= 1;
      break;
    case '.':
      putchar(memory[memory_index]);
      break;
    case ',':
      memory[memory_index] = getchar();
      break;
    case '[':
      for (size_t scope = 0; i < code_length && scope > 0; ++i)
      {
        switch (code[i])
        {
        case '[':
          scope += 1;
          break;
        case ']':
          scope -= 1;
          break;
        }
      }
      break;
    case ']':
      for (size_t scope = 0; i < SIZE_MAX && scope > 0; --i)
      {
        switch(code[i])
        {
        case ']':
          scope += 1;
          break;
        case '[':
          scope -= 1;
          break;
        }
      }
    }
  }
}