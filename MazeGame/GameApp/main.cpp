/*!
  funkcja main() calego programu
*/


#include "Game.h"

int main()            /// funkcja main()
{
  srand(time(NULL));  /// powoduje losowa generacje liczne przez rand()
  CGame game;         /// < deklaracja klasy reprezentujacej gre
  game.runMainLoop(); /// wywolanie glownej funkcji klasy main

  return 0;
}