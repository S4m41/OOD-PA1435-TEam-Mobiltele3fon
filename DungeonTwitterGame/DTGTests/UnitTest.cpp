#include "stdafx.h"
#include "Weapon.hpp"
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;


namespace DTGTests
{
	[TestClass]
	public ref class UnitTest
	{
	public:
	
		[TestMethod]
		void TestMethod1()
		{
			char* c = "Axe.png";
			Weapon w = Weapon(c);
			//
			// TODO: Add test logic here
			//
		};
	};
}
