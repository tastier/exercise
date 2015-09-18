#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include "query_result.h"

//class query_result;

class text_query {
public:
	typedef std::vector<std::string>::size_type line_no;
	text_query(std::ifstream&);
	query_result query(const std::string &) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
	static std::string cleanup_str(const std::string &); //为什么query函数是const，就需要该函数声明为static？
};


#endif
