#include "pch.h"
#include "../Uzduotis/functions.hpp"
#include "../Uzduotis/functions.cpp"

TEST(Name_Setter, Check_Setter)
{
	Studentas name;
	name.setVardas("vardenis");
	ASSERT_EQ(name.getVardas(), "vardenis");
}

TEST(Assignment, CheckAssignment)
{
	Studentas name, name2;
	name.setVardas("vardenis");
	name2 = name;
	ASSERT_EQ(name2.getVardas(), "vardenis");
}

TEST(Copy_Surname, CheckCopy)
{
	Studentas surname;
	surname.setPavarde("vardenis");
	Studentas surname2(surname);
	ASSERT_EQ(surname2.getPavarde(), "vardenis");
}