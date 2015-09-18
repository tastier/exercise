#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class strblob {
public:
	typedef std::vector<std::string>::size_type size_type;
	
	strblob();
	explicit strblob(std::initializer_list<std::string> il); //不使用引用？类似的，vector的引用？

	size_type size() const {return vec_ptr->size(); }
	bool empty() const { return vec_ptr->empty();}

	//添加，删除成员。
	//针对vec_ptr指向的vector进行操作，故成员函数的返回值不需要是strblob&类型
	void push_back(const std::string &s) { vec_ptr->push_back(s); }
	void pop_back() 
	{ 
		check(0, "pop_back");
		vec_ptr->pop_back();
	}

	//访问成员
	std::string &front();
	const std::string &front() const;//不返回const string也能够重载,重载的依据是成员函数是否是const，对应(*this)是否时const

	std::string &back();
	const std::string &back() const;

private:
	std::shared_ptr<std::vector<std::string>> vec_ptr;
	//检查输入合法性
	void check(size_type i, const std::string &msg) const;
};

inline 
strblob::strblob(std::initializer_list<std::string> il) :
	vec_ptr(std::make_shared<std::vector<std::string>>(il)) { }

inline
strblob::strblob() : vec_ptr(std::make_shared<std::vector<std::string>>()) { }
/*inline
strblob::strblob()
{
	vec_ptr = std::make_shared<std::vector<std::string>>();
}*/
std::string &strblob::front()
{
	check(0, "front");
	return vec_ptr->front();
}
const std::string &strblob::front() const
{
	check(0, "front const");
	std::cout << "front const" << std::endl;
	return vec_ptr->front();
}
std::string &strblob::back()
{
	check(0, "back");
	return vec_ptr->back();
}
const std::string &strblob::back() const
{
	check(0, "back const");
	std::cout << "back const" << std::endl;
	return vec_ptr->back();
}

void strblob::check(size_type i, const std::string &msg) const
{
	if(i >= vec_ptr->size())
		throw std::out_of_range(msg);
}

#endif
