#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
#include <vector>

class quote {
public:
	quote() = default;
	quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) 
	{ 
//		std::cout << "quote constructor running" << std::endl;
	}

	std::string isbn() const { return bookNo;}
	
	virtual ~quote() = default;

	virtual double net_price(std::size_t n) const { return n * price;}
	
	virtual void debug(std::ostream &os) const 
	{ 
		os << "bookNo: " << bookNo << std::endl
			<< "price: " << price << std::endl;
	}

	virtual quote* clone() const 
	{ 
		std::cout << "copy quote object" << std::endl;
		return new quote(*this); 
	}
private:
	std::string bookNo;
protected:
	double price;
};

class disc_quote : public quote {
public:
	disc_quote() : quantity(0), discount(0.0) {}
	disc_quote(const std::string &book, double sales_price,
			std::size_t qu, double dis)
			: quote(book, sales_price), quantity(qu), discount(dis) {}
	virtual double net_price(std::size_t n) const = 0;
protected:
	std::size_t quantity;
	double discount;
};

class bulk_quote : public disc_quote {
public:
	bulk_quote() = default;
	bulk_quote(const std::string &book, double sales_price,
			std::size_t qu, double dis)
		: disc_quote(book, sales_price, qu, dis) 
	{
//		std::cout << "bulk_quote constructor running" << std::endl;
	}
	
	double net_price(std::size_t n) const override;

	bulk_quote* clone() const 
	{ 
		std::cout << "copy bulk_quote obj" << std::endl;
		return new bulk_quote(*this); 
	}
};

class lim_quote : public disc_quote {
public:
	lim_quote() = default;
	lim_quote(const std::string &book, double sales_price, 
			std::size_t mq, double dis) 
		: disc_quote(book, sales_price, mq, dis) {}
	double net_price(std::size_t n) const override;
};

double print_total(std::ostream &os, const quote &q, std::size_t n);

#endif

