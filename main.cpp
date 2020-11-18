#include "RegistrarOffice.cpp"

int main(int argc, char** argv) {
  RegistrarOffice* reg = new RegistrarOffice();
  reg->RunSimulation(argv[1]);
  delete reg;
  return 0;
}
