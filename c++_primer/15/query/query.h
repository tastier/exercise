#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include "text_query.h"

//注意各种类出现的顺序，query出现在query_base之后，并且不能在query的内部定义公有的构造函数，因为还没有定义word_query。

//query_base及其派生类只有private和protected成员，
//因为它们有管理类，不需要用户直接访问
class query_base {
friend class query;
protected:
	using line_no = text_query::line_no;
	//基类需要虚析构函数，注意访问级别
	virtual ~query_base() = default; 
private:
	//const text_query
	virtual query_result eval(text_query &) const = 0;
	virtual std::string rep() const = 0;
};


class query {
friend query operator~(const query &);
friend query operator&(const query &, const query &);
friend query operator|(const query &, const query &);

public:
	query(const std::string &);
	query_result eval(text_query &tq) const
					{ return q->eval(tq); }
	std::string	rep() const 
					{ return q->rep(); }

private:
	//此处base指针定义成引用为什么出错？
	query(std::shared_ptr<query_base> base) : q(base) {}
	std::shared_ptr<query_base> q;
};


class word_query : public query_base {
friend class query;
private:
	word_query(const std::string &str) : word(str) {}

	query_result eval(text_query &tq) const
					{ return tq.query(word); } //query是const成员函数，而tq是非const
	std::string rep() const
					{ return word; }
private:
	std::string word;
};

//inline
//query::query(const std::string &str) : q(new word_query(str)) { }


class not_query : public query_base {
friend query operator~(const query &);
private:
	not_query(const query &q) : qy(q) {}
	query_result eval(text_query &) const;
	std::string rep() const 
					{ return "~(" + qy.rep() + ")"; }
private:
	query qy; //const q初始化非const qy？
};

class binary_query : public query_base {
protected:
	binary_query(const query &l, const query &r, 
			const std::string &s) : lhs(l), rhs(r), op(s) {}
	std::string rep() const
	{ return "(" + lhs.rep() + " " + op + " " + rhs.rep() + ")"; }
	
	query lhs, rhs;
	std::string op;
};

class or_query : public binary_query {
friend query operator|(const query &l, const query &r);
private:
	or_query(const query &l, const query &r)
		: binary_query(l, r, "|") {}
	query_result eval(text_query &) const;
};

class and_query : public binary_query {
friend query operator&(const query &,const query &);
private:
	and_query(const query &l, const query &r)
		: binary_query(l, r, "&") {}
	query_result eval(text_query &) const;
};

//友元声明
class query;
query operator~(const query &);
query operator|(const query &, const query &);
query operator&(const query &, const query &);

#endif
