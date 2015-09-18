

class NoDefault{
private:
	int a;
public:
	NoDefault(int i) : a(i) {}
};

class C{
private:
	NoDefault n;
public:
	C(int i = 0) : n(i) {}

};
