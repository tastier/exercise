#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map> 
#include <set>

class query_result {
friend std::ostream& operator<<(std::ostream &, const query_result &);
friend std::ostream& print(std::ostream &, const query_result &); //为什么需要加const？
public:
	typedef std::vector<std::string>::size_type line_no;
	typedef std::set<line_no>::const_iterator set_iter;
//	query_result() = default;
	query_result(std::string str, 
				 std::shared_ptr<std::vector<std::string>> f,
				 std::shared_ptr<std::set<line_no>> p) :
		sought(str), file(f), lines(p) 
	{ 
		std::cout << "query_result constructor" << std::endl;
	}
	set_iter begin() const { return lines->begin(); }
	set_iter end() const { return lines->end(); }
	std::shared_ptr<std::vector<std::string>> get_file() 
	{ return file; }
private:
	std::string sought;
	std::shared_ptr<std::vector<std::string>> file;
	std::shared_ptr<std::set<line_no>> lines;
};

//定义在这里不可以

/*
std::ostream& print(std::ostream &os, const query_result &qr)
{
	if(!qr.lines->size())
		os << qr.sought << " occurs " << "0 time."<< std::endl;
	else {
		 os << qr.sought << " occurs " << qr.lines->size()
			 << " times " << std::endl;
		 for (auto line = qr.lines->begin();
				 line != qr.lines->end(); ++line ) { 
			 os << "(line: " << *line + 1 << ")"
				 << *(qr.file->begin() + *line) << std::endl;
		 }
	}
	return os;
}
*/

#endif
