#include "query.h"
#include <algorithm>

using namespace std;

//query的构造函数和友元函数如在本文件中定义为inline，
//则链接时会报错：undefined reference，why？
//而将eval成员函数在本文件中定义成inline则没该错误
//构造函数和友元函数在query.h文件中定义成inline也没该错误


//inline
//query_result query::eval(text_query &tq) const
//{ return q->eval(tq);}

//inline
query::query(const string &str) : q(new word_query(str)) { }

//inline 
query operator~(const query &q)
{
	return query(shared_ptr<query_base>(new not_query(q)));
}

//inline
query operator|(const query &l, const query &r)
{
	return shared_ptr<query_base>(new or_query(l, r));
}

//inline
query operator&(const query &l, const query &r)
{
	return shared_ptr<query_base>(new and_query(l, r));
}

query_result not_query::eval(text_query &t) const
{
//	shared_ptr<set<line_no>> ret_set; 
//	使用上述形式定义指针会产生nullptr，发生严重错误
	auto ret_set = make_shared<set<line_no>>();
	
	query_result qr = qy.eval(t);
	auto beg = qr.begin();
	auto end = qr.end();
	size_t sz = qr.get_file()->size();
	for(size_t n = 0; n != sz; ++n){
		if(beg == end || n != *beg)
			ret_set->insert(n);
		else if(beg != end)
			++beg;
	}
	return query_result(rep(), qr.get_file(), ret_set);
}

query_result and_query::eval(text_query &t) const
{
	auto l_result = lhs.eval(t);
	auto r_result = rhs.eval(t);
	auto ret_set = make_shared<set<line_no>>();
	set_intersection(l_result.begin(), l_result.end(),
					r_result.begin(), r_result.end(),
					inserter(*ret_set,ret_set->begin()));
	return query_result(rep(), l_result.get_file(), ret_set);
}

query_result or_query::eval(text_query &t) const
{
	auto l_result = lhs.eval(t);
	auto r_result = rhs.eval(t);
	auto ret_set = make_shared<set<line_no>>(l_result.begin(), l_result.end());
	ret_set->insert(r_result.begin(), r_result.end());
	return query_result(rep(), l_result.get_file(), ret_set);
}

