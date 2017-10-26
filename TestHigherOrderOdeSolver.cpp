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
bool suite_TestHigherOrderOdeSolver_init = false;
#include "TestHigherOrderOdeSolver.hpp"

static TestHigherOrderOdeSolver suite_TestHigherOrderOdeSolver;

static CxxTest::List Tests_TestHigherOrderOdeSolver = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestHigherOrderOdeSolver( "TestHigherOrderOdeSolver.hpp", 34, "TestHigherOrderOdeSolver", suite_TestHigherOrderOdeSolver, Tests_TestHigherOrderOdeSolver );

static class TestDescription_suite_TestHigherOrderOdeSolver_TestSimpleCircleConvergence : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHigherOrderOdeSolver_TestSimpleCircleConvergence() : CxxTest::RealTestDescription( Tests_TestHigherOrderOdeSolver, suiteDescription_TestHigherOrderOdeSolver, 63, "TestSimpleCircleConvergence" ) {}
 void runTest() { suite_TestHigherOrderOdeSolver.TestSimpleCircleConvergence(); }
} testDescription_suite_TestHigherOrderOdeSolver_TestSimpleCircleConvergence;

static class TestDescription_suite_TestHigherOrderOdeSolver_TestSimpleCircle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHigherOrderOdeSolver_TestSimpleCircle() : CxxTest::RealTestDescription( Tests_TestHigherOrderOdeSolver, suiteDescription_TestHigherOrderOdeSolver, 97, "TestSimpleCircle" ) {}
 void runTest() { suite_TestHigherOrderOdeSolver.TestSimpleCircle(); }
} testDescription_suite_TestHigherOrderOdeSolver_TestSimpleCircle;

static class TestDescription_suite_TestHigherOrderOdeSolver_TestErrorofSolver : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHigherOrderOdeSolver_TestErrorofSolver() : CxxTest::RealTestDescription( Tests_TestHigherOrderOdeSolver, suiteDescription_TestHigherOrderOdeSolver, 134, "TestErrorofSolver" ) {}
 void runTest() { suite_TestHigherOrderOdeSolver.TestErrorofSolver(); }
} testDescription_suite_TestHigherOrderOdeSolver_TestErrorofSolver;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
