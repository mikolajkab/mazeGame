#include <stdlib.h>

#include "CWindow.h"
#include "CMaze.h"

int main(int argc, char** argv)
{
  CWindow Window("Maze Game");
  CMaze Maze;
  Window.Init();
  Window.Display();
  Window.Loop();
  exit(EXIT_SUCCESS);
}