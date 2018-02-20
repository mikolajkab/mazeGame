#include <stdlib.h>

#include "CWindow.h"
#include "CMaze.h"

int main(int argc, char** argv)
{
  CWindow Window("Maze Game");
  CMaze Maze;
  Window.Init();
  Window.Display(Maze.getTileWidth(), Maze.getTileHeight(), &Maze.background);
  Window.Reshape();
  Window.Loop();
  exit(EXIT_SUCCESS);
}