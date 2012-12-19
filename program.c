#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>


/* This program filters an argument list by removing any strings matching
 * the first argument
 */

int main(int argc, char **argv) {
  /* The element at argv[1] is the string to remove, if present */
  int i = 1;
  
  /* If no arguments are given, complain and exit. */
  if (argc < 2) {
    fprintf(stderr, "Error: no arguments specified.\n");
    return 1;
  }

  /* If there is only one argument, also complain and exit. */
  if (argc == 2) {
    fprintf(stderr,
            "Error: no arguments specified after argument to ignore.\n");
    return 1;
  }


  unsigned arg_count = 0;

  char* to_remove = argv[1];
  char** arglist = malloc(sizeof(char*) * argc);
  for (; i < argc; ++i){
    if (strcmp(to_remove, argv[i])) {
      arglist[arg_count] = argv[i];
      arg_count++;
    }
  }
  if (arg_count == 0) {
    fprintf(stderr, "Empty command built; will not be executed.\n");
    return 1;
  }
  /* NULL-terminate the argument list for execvp() */
  arglist[arg_count] = NULL;
  if (execvp(arglist[0], arglist))
    perror("Error executing command");
  return -1;
}
