#include "text_query.h"

using namespace std;

text_query::text_query(ifstream &ifs) : file(new vector<string>)
{
	//file不放在初始化列表中，使用reset也可以吧？
	string oneline, word;
	while(getline(ifs, oneline)) {
		file->push_back(oneline);
		line_no num = file->size() -1;
		istringstream record(oneline);
		while(record >> word) {
			word = cleanup_str(word);
			if(!wm[word])
				wm[word].reset(new set<line_no>); //important
			wm[word]->insert(num);
		}
	}
}

query_result text_query::query(const string &word) const
{
	shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(cleanup_str(word));
	if( loc == wm.end())
		return query_result(word, file, nodata); //显式调用构造函数
	else
		return query_result(word, file, loc->second); //wm[word], loc->second 类型相同，为mapped_type		
}

string text_query::cleanup_str(const string &str)
{
	string ret;
	for(auto it = str.begin(); it != str.end(); ++it) {
		if(!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}

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

std::ostream& operator<<(std::ostream &os, const query_result &qr)
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
