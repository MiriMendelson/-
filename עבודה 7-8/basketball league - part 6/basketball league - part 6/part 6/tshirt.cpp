#pragma warning(disable: 4996)

#include <string>
#include <iostream>
using namespace std;

#include "tshirt.h"

const char* TShirt::sizeStr[3] = { "Large", "XL", "XXL" };

TShirt::TShirt(const char* nickname, eSize size) : size(size)
{
	this->nickname = new char[strlen(nickname)+1];
	strcpy(this->nickname, nickname);
}

TShirt::TShirt(const TShirt& other) : nickname(nullptr)
{
	/*this->nickname = new char[strlen(other.nickname) + 1];
	strcpy(this->nickname, other.nickname);
	this->size = other.size;*/
	*this = other;
}

TShirt::TShirt(TShirt&& other)
{
	this->nickname = other.nickname;
	other.nickname = nullptr;
	this->size = other.size;
}

TShirt::~TShirt()
{
	delete[]nickname;
}

const TShirt& TShirt::operator=(const TShirt& other)
{
	if (this != &other)
	{
		size = other.size;
		//nickname = other.nickname;

		setNickname(other.nickname);
	}

	return *this;
}

void TShirt::setNickname(const char* newNickname)
{
	delete[]nickname;
	this->nickname = new char[strlen(newNickname) + 1];
	strcpy(this->nickname, newNickname);
}

void TShirt::print() const
{
	cout << "TShirt size: " << sizeStr[(int)size] << ", nickname: " << nickname << endl;
}

int TShirt::operator()(const char* s, int x)
{
	setNickname(s);
	return (int)size;
}

ostream& operator<<(ostream& os, const TShirt& tshirt)
{
	os << tshirt.nickname << ", size=" << TShirt::sizeStr[(int)tshirt.getSize()];
	return os;
}

istream& operator>>(istream& is, TShirt& tshirt)
{
	char temp[20];
	is >> temp;
	tshirt.setNickname(temp);

	int size;
	is >> size;

	tshirt.size = (TShirt::eSize)size;

	return is;
}