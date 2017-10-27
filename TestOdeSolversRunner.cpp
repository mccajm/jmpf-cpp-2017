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
bool suite_TestOdeSolvers_init = false;
#include "TestOdeSolvers.hpp"

static TestOdeSolvers suite_TestOdeSolvers;

static CxxTest::List Tests_TestOdeSolvers = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestOdeSolvers( "TestOdeSolvers.hpp", 43, "TestOdeSolvers", suite_TestOdeSolvers, Tests_TestOdeSolvers );

static class TestDescription_suite_TestOdeSolvers_TestSomeExamples : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOdeSolvers_TestSomeExamples() : CxxTest::RealTestDescription( Tests_TestOdeSolvers, suiteDescription_TestOdeSolvers, 67, "TestSomeExamples" ) {}
 void runTest() { suite_TestOdeSolvers.TestSomeExamples(); }
} testDescription_suite_TestOdeSolvers_TestSomeExamples;

static class TestDescription_suite_TestOdeSolvers_TestAbstractClassMethods : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOdeSolvers_TestAbstractClassMethods() : CxxTest::RealTestDescription( Tests_TestOdeSolvers, suiteDescription_TestOdeSolvers, 93, "TestAbstractClassMethods" ) {}
 void runTest() { suite_TestOdeSolvers.TestAbstractClassMethods(); }
} testDescription_suite_TestOdeSolvers_TestAbstractClassMethods;

static class TestDescription_suite_TestOdeSolvers_TestDecoupledForwardEuler : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOdeSolvers_TestDecoupledForwardEuler() : CxxTest::RealTestDescription( Tests_TestOdeSolvers, suiteDescription_TestOdeSolvers, 193, "TestDecoupledForwardEuler" ) {}
 void runTest() { suite_TestOdeSolvers.TestDecoupledForwardEuler(); }
} testDescription_suite_TestOdeSolvers_TestDecoupledForwardEuler;

static class TestDescription_suite_TestOdeSolvers_TestSimpleCircle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOdeSolvers_TestSimpleCircle() : CxxTest::RealTestDescription( Tests_TestOdeSolvers, suiteDescription_TestOdeSolvers, 273, "TestSimpleCircle" ) {}
 void runTest() { suite_TestOdeSolvers.TestSimpleCircle(); }
} testDescription_suite_TestOdeSolvers_TestSimpleCircle;

static class TestDescription_suite_TestOdeSolvers_TestErrorofSolver : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOdeSolvers_TestErrorofSolver() : CxxTest::RealTestDescription( Tests_TestOdeSolvers, suiteDescription_TestOdeSolvers, 310, "TestErrorofSolver" ) {}
 void runTest() { suite_TestOdeSolvers.TestErrorofSolver(); }
} testDescription_suite_TestOdeSolvers_TestErrorofSolver;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
