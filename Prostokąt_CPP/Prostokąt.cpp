#include <iostream>
#include <windows.h>
#include <string>
#include <cstdint>
#include <cstdlib>


class prostokat

{

private:
	int a;
	int b;

public:

	prostokat();

	prostokat(const int a, const int b);

	void Print() const;

	~prostokat();

};

int main(int argc, char* argv[])
{
	prostokat pierwszy;
	pierwszy.Print();

	prostokat drugi(7, 8);
	drugi.Print();

	prostokat trzeci(20, 30);
	trzeci.Print();

	system("pause");
	return EXIT_SUCCESS;

}

prostokat::prostokat() :
	a(5),
	b(10)
{
}

prostokat::prostokat(const int a, const int b) :
	a(a),
	b(b)
{
}

void prostokat::Print() const
{

	using std::cout;
	cout << "Prostokat o bokach: A = " << a << " B = " << b << '\n';

}

prostokat::~prostokat()
{

	this->a = 0;
	this->b = 0;

}