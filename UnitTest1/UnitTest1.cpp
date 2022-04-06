#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.1.2/Lab_9.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* stud = new Student[5];
			stud[0].specialst = computer_science;
			stud[0].physics_grade = 5;
			stud[0].math_grade = 5;
			stud[0].programing_grade = 5;

			stud[1].specialst = informatics;
			stud[1].physics_grade = 4;
			stud[1].math_grade = 5;
			stud[1].chisel_metod_grade = 2;

			stud[2].specialst = math_a_economics;
			stud[2].physics_grade = 2;
			stud[2].math_grade = 5;
			stud[2].pedagogic_grade = 5;

			stud[3].specialst = computer_science;
			stud[3].physics_grade = 5;
			stud[3].math_grade = 2;
			stud[3].programing_grade = 5;

			stud[4].specialst = labor_education;
			stud[4].physics_grade = 3;
			stud[4].math_grade = 5;
			stud[4].pedagogic_grade = 5;
			
			Assert::AreEqual(PrizvPrint(stud,0), true);
			Assert::AreEqual(PrizvPrint(stud,1), false);
			Assert::AreEqual(PrizvPrint(stud,2), false);
			Assert::AreEqual(PrizvPrint(stud,3), true);
			Assert::AreEqual(PrizvPrint(stud,4), false);
		}
	};
}
