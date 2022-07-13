#include "Fixed.hpp"

void basic_unary_op_test(void)
{
	float bNum = 17.55f;
	float cNum = 3.5f;
	Fixed a;

	cout << "==== BASIC ARITHMETIC TESTS ===" << endl;
	a = Fixed(bNum) + Fixed(cNum);
	cout << ">> Testing +" << endl
		 << (bNum) << " + " << cNum << " =" << endl
		 << "Fixed : " << a << endl
		 << "Float : " << (bNum + cNum) << endl
		 << endl;

	a = Fixed(bNum) - Fixed(cNum);
	cout << ">> Testing -" << endl
		 << (bNum) << " - " << cNum << " =" << endl
		 << "Fixed : " << a << endl
		 << "Float : " << (bNum - cNum) << endl
		 << endl;

	a = Fixed(bNum) * Fixed(cNum);
	cout << ">> Testing *" << endl
		 << (bNum) << " * " << cNum << " =" << endl
		 << "Fixed : " << a << endl
		 << "Float : " << (bNum * cNum) << endl
		 << endl;

	a = Fixed(bNum) / Fixed(cNum);
	cout << ">> Testing /" << endl
		 << (bNum) << " / " << cNum << " =" << endl
		 << "Fixed : " << a << endl
		 << "Float : " << (bNum / cNum) << endl
		 << endl;
}

void basic_pfixes_op_test(void)
{
	float aNum = 5.5f;
	float bNum = 2.5f;

	Fixed a(aNum);
	Fixed b(bNum);
}

int main(void)
{
	// basic_relational_op_test_p1();
	// basic_relational_op_test_p2();
	// basic_relational_op_test_p3();
	basic_unary_op_test();
	// basic_pfixes_op_test();

	return (0);
}