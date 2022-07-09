#ifndef __TSHIRT_H
#define __TSHIRT_H

class TShirt
{
public:
	static const char* sizeStr[3];
	enum class eSize {L, XL, XXL};

private:
	char* nickname;
	eSize size;

public:
	TShirt(const char* nickname="player1", eSize size=eSize::XL);
	TShirt(const TShirt& other);
	TShirt(TShirt&& other);
	~TShirt();

	const TShirt& operator=(const TShirt& other);

	void print() const;

	const char* getNickname() const { return nickname; }
	void setNickname(const char* newNickname);
	eSize getSize() const { return size; }
	void setSize(eSize newSize) { size = newSize; }

	operator const char* () const { return nickname; }
	operator TShirt::eSize () const { return size; }

	int operator()(const char* s, int x);

	friend ostream& operator<<(ostream& os, const TShirt& tshirt);
	friend istream& operator>>(istream& is, TShirt& tshirt);
};
#endif // __TSHIRT_H