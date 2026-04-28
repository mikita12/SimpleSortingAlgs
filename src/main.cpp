#include "Parameters.h"



int main(int argc, char **argv) {
  Parameters::readParameters(argc - 1, argv + 1);
  Parameters::printParameters(); // debug
  // Teraz pisz logikę na podstawie ustawionych parametrów
}