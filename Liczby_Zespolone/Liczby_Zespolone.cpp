#include <iostream>
#include <windows.h>
#include <string>
#include <cstdint>
#include <cstdlib>


class COMPLEX
{
private:
	float im;
	float re;
public:
	COMPLEX();
	COMPLEX(const float im, const float re);
	COMPLEX(const COMPLEX& OBJECT);

	void Print();

	COMPLEX& operator=(const COMPLEX& OBJECT);

	COMPLEX& operator*=(const COMPLEX& OBJECT);
	COMPLEX& operator+=(const COMPLEX& OBJECT);
	COMPLEX& operator-=(const COMPLEX& OBJECT);
	COMPLEX& operator*=(const float value);	
	COMPLEX& operator+=(const float value);	
	COMPLEX& operator-=(const float value);	

	friend std::ostream& operator<<(std::ostream& lhs, const COMPLEX& rhs);
	friend bool operator==(const COMPLEX& lhs, const COMPLEX& rhs);
	friend COMPLEX operator*(const COMPLEX& lhs, const COMPLEX& rhs);
	friend COMPLEX operator-(const COMPLEX& lhs, const COMPLEX& rhs);
	friend COMPLEX operator+(const COMPLEX lhs, const COMPLEX& rhs);
	friend COMPLEX operator*(const COMPLEX& lhs, const float value);
	friend COMPLEX operator-(const COMPLEX& lhs, const float value);
	friend COMPLEX operator+(const COMPLEX& lhs, const float value);
	friend COMPLEX operator*(const float value, const COMPLEX& rhs);
	friend COMPLEX operator-(const float value, const COMPLEX& rhs);
	friend COMPLEX operator+(const float value, const COMPLEX& rhs);


	~COMPLEX();
};


int main(int argc, char* argv[])
{
	COMPLEX A(1.0f, 2.0f);

	COMPLEX B(0.5f, -1.5f);

	std::cout << A;//8
	A.Print();
	B.Print();

	COMPLEX C;
	std::cout << C;//8
	C *= A;//2
	std::cout << C;//8
	C += A;//3
	std::cout << C;//8
	C -= A;//4
	std::cout << C;//8
	C = A * B;//10
	std::cout << C;//8
	C = A - B;//11
	std::cout << C;//8
	C = A + B;//12
	std::cout << C;//8
	C = B;//1
	std::cout << C;//8


	A *= 3.f;//5
	A += 3.f;//6
	A -= 3.f;//7

	C = C * 2.f;//13
	C = C + 2.f;//15
	C = C - 2.f;//14

	B = 1.5f * A;//16
	B = 1.5f + A;//18
	B = 1.5f - A;//17

	if (A == B)//9
	{
		std::cout << "Rowne\n";
	}
	else
	{
		std::cout << "Nierowne\n";
	}



	system("pause");
	return EXIT_SUCCESS;
}

COMPLEX::COMPLEX() :
	im(0.0f),
	re(0.0f)
{
}

COMPLEX::COMPLEX(const float im, const float re) :
	im(im),
	re(re)
{

}

COMPLEX::COMPLEX(const COMPLEX& OBJECT) :
	im(OBJECT.im),
	re(OBJECT.re)
{

}

void COMPLEX::Print()
{
	using std::cout;
	using std::endl;
	cout << "Im: " << im << " Re: " << re << endl;
}

COMPLEX& COMPLEX::operator=(const COMPLEX& OBJECT)
{
	if (this != &OBJECT)
	{
		this->im = OBJECT.im;
		this->re = OBJECT.re;
	}
	return *this;
}

COMPLEX& COMPLEX::operator*=(const COMPLEX& OBJECT)
{
	this->im *= OBJECT.im;
	this->re *= OBJECT.re;
	return *this;
}

COMPLEX& COMPLEX::operator+=(const COMPLEX& OBJECT)
{
	this->im += OBJECT.im;
	this->re += OBJECT.re;
	return *this;
}

COMPLEX& COMPLEX::operator-=(const COMPLEX& Object)
{
	this->im -= Object.im;
	this->re -= Object.re;
	return *this;
}

COMPLEX& COMPLEX::operator*=(const float value)
{
	this->im *= value;
	this->re *= value;
	return *this;
}

COMPLEX& COMPLEX::operator+=(const float value)
{
	this->im += value;
	this->re += value;
	return *this;
}

COMPLEX& COMPLEX::operator-=(const float value)
{
	this->im -= value;
	this->re -= value;
	return *this;
}

COMPLEX::~COMPLEX()
{
	this->im = 0.f;
	this->re = 0.f;
}

std::ostream& operator<<(std::ostream& lhs, const COMPLEX& rhs)
{
	using std::endl;
	lhs << "Im: " << rhs.im << " Re: " << rhs.re << std::endl;
	return lhs;
}

bool operator==(const COMPLEX& lhs, const COMPLEX& rhs)
{
	if (lhs.im == rhs.im && lhs.re == rhs.re)
	{
		return true;
	}
	return false;
}

COMPLEX operator*(const COMPLEX& lhs, const COMPLEX& rhs)
{
	COMPLEX wynik;
	wynik.im = lhs.im * rhs.im;
	wynik.re = lhs.re * rhs.re;
	return wynik;
}

COMPLEX operator-(const COMPLEX& lhs, const COMPLEX& rhs)
{
	COMPLEX wynik;
	wynik.im = lhs.im - rhs.im;
	wynik.re = lhs.re - rhs.re;
	return wynik;
}

COMPLEX operator+(const COMPLEX lhs, const COMPLEX& rhs)
{
	COMPLEX wynik;
	wynik.im = lhs.im + rhs.im;
	wynik.re = lhs.re + rhs.re;
	return wynik;
}

COMPLEX operator*(const COMPLEX& lhs, const float value)
{
	COMPLEX wynik;
	wynik.im = lhs.im * value;
	wynik.re = lhs.re * value;
	return wynik;
}

COMPLEX operator-(const COMPLEX& lhs, const float value)
{
	COMPLEX wynik;
	wynik.im = lhs.im - value;
	wynik.re = lhs.re - value;
	return wynik;
}

COMPLEX operator+(const COMPLEX& lhs, const float value)
{
	COMPLEX wynik;
	wynik.im = lhs.im + value;
	wynik.re = lhs.re + value;
	return wynik;
}

COMPLEX operator*(const float value, const COMPLEX& rhs)
{
	COMPLEX wynik;
	wynik.im = value * rhs.im;
	wynik.re = value * rhs.re;
	return wynik;
}

COMPLEX operator-(const float value, const COMPLEX& rhs)
{
	COMPLEX wynik;
	wynik.im = value - rhs.im;
	wynik.re = value - rhs.re;
	return wynik;
}

COMPLEX operator+(const float value, const COMPLEX& rhs)
{
	COMPLEX wynik;
	wynik.im = value + rhs.im;
	wynik.re = value + rhs.re;
	return wynik;
}