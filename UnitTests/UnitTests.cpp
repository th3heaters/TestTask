#include "pch.h"
#include "CppUnitTest.h"
#include "init_tape.h"
#include "init_tape.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
		TEST_METHOD(testCorrectConfig)
		{
			int read = 10, record = 10, rewind = 100, shift = 5;
			tapes tape("tape_input.txt", "tape_output.txt");
			Assert::IsTrue(read == 10);
		}
		TEST_METHOD(isInitialized)
		{
			tapes tape("tape_input.txt", "tape_output.txt");
			tape.init_tape();
			Assert::IsTrue(!tape.getTape().empty());
		}
		TEST_METHOD(isSorted)
		{
			tapes tape("tape_input.txt", "tape_output.txt");
			tape.init_tape();
			tape.sorts();
			std::list <int> testtape = { 1, 12, 13, 22, 34, 63, 134, 134, 234, 242, 346, 534, 563, 652, 2345, 2366, 4754, 5634, 6074, 6564, 6784, 7643, 9675 };
			Assert::IsTrue(testtape == tape.getTape());
		}
	};
}
