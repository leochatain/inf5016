#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main(int argc, char* argv[]) {
  // Get the top level suite from the registry.
  CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  // Add the test to the list of tests to run.
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(suite);

  // Change the default outputter to a compiler error format outputter.
  runner.setOutputter(new CppUnit::CompilerOutputter(
      &runner.result(), std::cerr));

  // Run the tests.
  bool wasSuccesful = runner.run();

  // Return error code 1 if one of the tests failed.
  return wasSuccesful ? 0 : 1;
}
