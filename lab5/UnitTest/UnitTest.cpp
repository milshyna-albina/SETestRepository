#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\user\Documents\хпи\Software engineering\lab5\lab5\code.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(isInteger_Tests)
    {
    public:
        TEST_METHOD(isInteger_get7_noExceptionThrown)
        {
            string input = "7";
            try
            { 
                isInteger(input);
                Assert::IsTrue(true);
            }
            catch (...)
            {
                Assert::Fail();
            }
        }
        TEST_METHOD(isInteger_get7a_exceptionThrown)
        {
            string input = "7a";
            try
            {
                isInteger(input);
                Assert::Fail();
            }
            catch (...)
            {
                Assert::IsTrue(true);
            }
        }
        TEST_METHOD(isInteger_get7point3_exceptionThrown)
        {
            string input = "7.3";
            try
            {
                isInteger(input);
                Assert::Fail();
            }
            catch (...)
            {
                Assert::IsTrue(true);
            }
        }
    };


    TEST_CLASS(validateN_Tests)
    {
    public:
        TEST_METHOD(validateN_get10_noExceptionThrown)
        {
            string input = "10";
            try
            {
                validateN(input);
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::Fail();
            }
        }
        TEST_METHOD(validateN_get1_exceptionThrown)
        {
            string input = "1";
            try {
                validateN(input);
                Assert::Fail();
            }
            catch (...) {
                Assert::IsTrue(true);
            }
        }
    };


    TEST_CLASS(validateNumber_Tests)
    {
    public:
        TEST_METHOD(validateNumber_get12_noExceptionThrown)
        {
            string input = "12";
            try
            {
                validateNumber(input);
                Assert::IsTrue(true);
            }
            catch (...)
            {
                Assert::Fail();
            }
        }
        TEST_METHOD(validateNumber_get12point3_noExceptionThrown)
        {
            string input = "12.3";
            try
            {
                validateNumber(input);
                Assert::IsTrue(true);
            }
            catch (...)
            {
                Assert::Fail();
            }
        }
        TEST_METHOD(validateNumber_getminus12point3_noExceptionThrown)
        {
            string input = "-12.3";
            try
            {
                validateNumber(input);
                Assert::IsTrue(true);
            }
            catch (...)
            {
                Assert::Fail();
            }
        }
        TEST_METHOD(validateNumber_get12apoint3_exceptionThrown)
        {
            string input = "12a.3";
            try
            {
                validateNumber(input);
                Assert::Fail();
            }
            catch (...)
            {
                Assert::IsTrue(true);
            }
        }
        TEST_METHOD(validateNumber_getpoint_exceptionThrown)
        {
            string input = ".";
            try
            {
                validateNumber(input);
                Assert::Fail();
            }
            catch (...)
            {
                Assert::IsTrue(true);
            }
       
        }
    };


    TEST_CLASS(validateStep_Tests)
    {
    public:
        TEST_METHOD(validateStep_get0point5_noExceptionThrown)
        {
            double step = 0.5;
            try
            {
                validateStep(step);
                Assert::IsTrue(true);
            }
            catch (...)
            {
                Assert::Fail();
            }
        }
        TEST_METHOD(validateStep_get2_noExceptionThrown)
        {
            double step = 2;
            try
            {
                validateStep(step);
                Assert::IsTrue(true);
            }
            catch (...)
            {
                Assert::Fail();
            }
        }
        TEST_METHOD(validateStep_get0_exceptionThrown)
        {
            double step = 0;
            try
            {
                validateStep(step);
                Assert::Fail();
            }
            catch (...)
            {
                Assert::IsTrue(true);
            }
        }
        TEST_METHOD(validateStep_getminus1_exceptionThrown)
        {
            double step = -1;
            try
            {
                validateStep(step);
                Assert::Fail();
            }
            catch (...)
            {
                Assert::IsTrue(true);
            }
        }
    };

    TEST_CLASS(validateRange_Tests)
    {
    public:
        TEST_METHOD(validateRange_get2point7and8_noExceptionThrown)
        {
            double a = 2.7;
            double b = 8;
            try
            {
                validateRange(a, b);
                Assert::IsTrue(true);
            }
            catch (...)
            {
                Assert::Fail();
            }
        }
        TEST_METHOD(validateRange_get5and5_exceptionThrown)
        {
            double a = 5;
            double b = 5;
            try
            {
                validateRange(a, b);
                Assert::Fail();
            }
            catch (...)
            {
                Assert::IsTrue(true);
            }
        }
        TEST_METHOD(validateRange_get10and3point2_exceptionThrown)
        {
            double a = 10;
            double b = 3.2;
            try
            {
                validateRange(a, b);
                Assert::Fail();
            }
            catch (...)
            {
                Assert::IsTrue(true);
            }
        }
    };


    TEST_CLASS(SimpleAlgorithm_Tests)
    {
    public:
        TEST_METHOD(SimpleAlgorithm_get5and1point2_0point688827returned)
        {
            int n = 5;
            double x = 1.2;
            double expected = 0.688827;

            double actual = SimpleAlgorithm(n, x);

            double delta = 0.000001;
            Assert::IsTrue(abs(expected - actual) < delta);
        }
        TEST_METHOD(SimpleAlgorithm_get7andminus3_31returned)
        {
            int n = 7;
            double x = -3;
            double expected = 31;

            double actual = SimpleAlgorithm(n, x);

            Assert::AreEqual(expected, actual);
           
        }
    };

    TEST_CLASS(ExtendedAlgorithm_Tests)
    {
    public:
        TEST_METHOD(ExtendedAlgorithm_get5andminus3and8and2_37point4825779042617returned)
        {
            int n = 5;
            double a = -3;
            double b = 8;
            double step = 2;
            double expected = 37.4825779042617;

            double actual = ExtendedAlgorithm(n, a, b, step);

            double delta = 0.000001;
            Assert::IsTrue(abs(expected - actual) < delta);
        }
        TEST_METHOD(ExtendedAlgorithm_get5and2point5and2point7and0point05_0point0429569528495815returned)
        {
            int n = 8;
            double a = 2.5;
            double b = 2.7;
            double step = 0.05;
            double expected = 0.0429569528495815;

            double actual = ExtendedAlgorithm(n, a, b, step);

            double delta = 0.000001;
            Assert::IsTrue(abs(expected - actual) < delta);
        }
    };

}
