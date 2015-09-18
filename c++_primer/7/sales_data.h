#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class sales_data {
friend std::ostream& operator<<(std::ostream&, const sales_data&);
friend std::istream& operator>>(std::istream&, sales_data&);
private:
	std::string bookNo;
	unsigned units_sold = 0;
//	double sellingprice = 0.0;
	double saleprice = 0.0;
//	double discount =0.0;
public:
	sales_data() = default;
	explicit sales_data(const std::string &s) : bookNo(s) { }
	sales_data(const std::string &s, unsigned n, double sale) :
		bookNo(s), units_sold(n), saleprice(sale) {}
	explicit sales_data(std::istream &is);

public:
	std::string isbn() const { return bookNo;}
	sales_data& combine(const sales_data&);
	int combine (const sales_data&, int);//test
	double avg_price() const { return saleprice / units_sold;}
};

sales_data::sales_data(std::istream &is)
{
	is >> *this;//使用重载后的>>运算符
}

sales_data& sales_data::combine(const sales_data &rhs)
{
	units_sold += rhs.units_sold;//成员函数内部，故rhs也能访问私有数据！
	return *this;
}

std::ostream&
operator<<(std::ostream &out, const sales_data &s)
{
	out << s.isbn() << " " << s.units_sold << " " << s.saleprice;
	return out;
} 

std::istream&
operator>>(std::istream &is, sales_data &sa)
{
	is >> sa.bookNo >> sa.units_sold >> sa.saleprice;
	return is;
}

int sales_data::combine( const sales_data &s, int i)
{
	if(bookNo != s.isbn())
		return -1;
	units_sold += s.units_sold;
		return 0;
}

#endif
