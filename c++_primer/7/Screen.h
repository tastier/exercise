#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen{
public:
	Screen() = default;
	Screen(unsigned w, unsigned h):
		width(w), height(h), content(w * h, ' ') {}
	Screen(unsigned w, unsigned h, char c):
		width(w), height(h), content(w * h, c) {}
public:
	Screen& move(unsigned wi, unsigned he);
	Screen& set(char c);
	Screen& set(unsigned wi, unsigned he, char c);
	const Screen& display(std::ostream &out) const;
private:
	std::string content;
	unsigned cursor = 0;
	unsigned width = 0;
	unsigned height = 0;
};

inline Screen&
Screen::move(unsigned wi, unsigned he)
{
	cursor = he * width + wi;
	return *this;
}
inline Screen&
Screen::set(char c)
{
	content[cursor] = c;
	return *this;
}
inline Screen&
Screen::set(unsigned wi, unsigned he, char c)
{
	cursor = he * width + wi;
	content[cursor] = c;
	return *this;
}
inline const Screen&
Screen::display(std::ostream &out) const
{
	out << content;
	return *this;
}






#endif
