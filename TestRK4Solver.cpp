/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TestRK4Solver_init = false;
#include "TestRK4Solver.hpp"

static TestRK4Solver suite_TestRK4Solver;

static CxxTest::List Tests_TestRK4Solver = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestRK4Solver( "TestRK4Solver.hpp", 35, "TestRK4Solver", suite_TestRK4Solver, Tests_TestRK4Solver );

static class TestDescription_suite_TestRK4Solver_TestSimpleCircleConvergence : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestRK4Solver_TestSimpleCircleConvergence() : CxxTest::RealTestDescription( Tests_TestRK4Solver, suiteDescription_TestRK4Solver, 64, "TestSimpleCircleConvergence" ) {}
 void runTest() { suite_TestRK4Solver.TestSimpleCircleConvergence(); }
} testDescription_suite_TestRK4Solver_TestSimpleCircleConvergence;

static class TestDescription_suite_TestRK4Solver_TestSimpleCircle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestRK4Solver_TestSimpleCircle() : CxxTest::RealTestDescription( Tests_TestRK4Solver, suiteDescription_TestRK4Solver, 91, "TestSimpleCircle" ) {}
 void runTest() { suite_TestRK4Solver.TestSimpleCircle(); }
} testDescription_suite_TestRK4Solver_TestSimpleCircle;

static class TestDescription_suite_TestRK4Solver_TestErrorofSolver : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestRK4Solver_TestErrorofSolver() : CxxTest::RealTestDescription( Tests_TestRK4Solver, suiteDescription_TestRK4Solver, 128, "TestErrorofSolver" ) {}
 void runTest() { suite_TestRK4Solver.TestErrorofSolver(); }
} testDescription_suite_TestRK4Solver_TestErrorofSolver;

static class TestDescription_suite_TestRK4Solver_TestVanderPol : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestRK4Solver_TestVanderPol() : CxxTest::RealTestDescription( Tests_TestRK4Solver, suiteDescription_TestRK4Solver, 149, "TestVanderPol" ) {}
 void runTest() { suite_TestRK4Solver.TestVanderPol(); }
} testDescription_suite_TestRK4Solver_TestVanderPol;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
