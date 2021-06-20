#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
class String;
String operator+(const String& left, const String& right);

class String
{
	unsigned int size; // Size in bytes
	char* str;
public:
	unsigned int get_size() const {
		return size;
	}
	const char* get_str() const {
		return str;
	}
	char* get_str() {
		return str;
	}
	//Constructors
	explicit String(unsigned int size = 80) {
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConst:" << tab << this << endl;
	}
	String(const char str[]) {
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Const:" << tab << this << endl;
	}
	String(const String& other) {
		this->size = other.size;
		//this->str = other.str;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i]; // Побитовое копирование
		cout << "CopyConst: " << this << endl;
	}
	String(const String&& other) {
		this->size = other.size;
		this->str = other.str;
		delete[] other.str;
		cout << "MoveConst: " << this << endl;
	}
	~String() {
		delete[] this->str;
		cout << "Destructor: " << tab << this << endl;
	}
	//Operators
	String& operator+=(const String& other) {
		return *this = *this + other;
	}
	String& operator=(const String& other) {
		if (this == &other) return *this;
		this->size = other.size;
		//this->str = other.str;
		delete[] this->str;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i]; // Побитовое копирование
		cout << "CopyAssign: " << this << endl;
		return *this;
	}
	const char& operator[](unsigned int i) const{
		return str[i];
	}
	char& operator[](unsigned int i) {
		return str[i];
	}
	void print() const {
		cout << "Size: " << size << endl;
		cout << "Str: " << str << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const String& obj) {
	return os << obj.get_str();
}
String operator+(const String& left, const String& right) {
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++) {
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++) {
		cat[i + left.get_size()-1] = right[i];
	}
	return cat;
}
std::istream& operator>>(std::istream& is, String& obj) {
	return is >> obj.get_str();
}
//#define CONSTRUCTORS_CHECK
//#define CIN
void main(){
	setlocale(LC_ALL, "ru");
#ifdef CONSTRUCTORS_CHECK
	String str = "Hello world!";
	cout << str << endl;
	str.print();
	String str2 = str;
	str2.print();
	String str3;
	str3 = str2;
#endif // CONSTRUCTORS_CHECK
#ifdef CIN
	String str;
	cout << "Введите строку: "; cin >> str;

#endif // CIN
#ifdef SUM
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;
	str1 += str2;
	str1.print();
#endif // SUM
}