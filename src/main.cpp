#include <CLI11.hpp>
#include <print>

int main(int argc, char **argv) {
  CLI::App app{"A CLI to-do list"};


  CLI11_PARSE(app, argc, argv);
  return EXIT_SUCCESS;
}
