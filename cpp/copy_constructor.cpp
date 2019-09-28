#include <iostream>

class Line {
public:
	Line();
	Line(const int);
	Line(const Line &);

	~Line();
	const int getLine() const;
	void display();
	Line& operator=(const Line);
private:
	int *ptr;
};


Line::Line()
{
	ptr = new int;
	std::cout << "Default Constructor" <<  *ptr << std::endl;
	*ptr = 0;
}

Line::Line(const int line)
{
	ptr = new int;
	*ptr = line;
	std::cout << "Int Constructor" << *ptr << std::endl;
}

Line::Line (const Line &obj)
{
	ptr = new int;
	*ptr = obj.getLine();
	std::cout << "Copy Constructor" << *ptr << std::endl;
}

const int Line::getLine() const
{
	return *ptr;
}

void Line::display(){
	std::cout << *ptr << std::endl;
}

Line::~Line()
{
	std::cout << "Destructor " << *ptr << std::endl;
	delete ptr;
}

void display(Line &line)
{
	line.display();
}

Line& Line::operator=(const Line line) {
	
	std::cout << "Destructor " << *ptr << std::endl;
	delete ptr;
	*ptr = line.getLine();
	std::cout << "Assign " << *ptr << std::	endl;
	return *this;
}

int main()
{
	Line line(10);
	Line line2(line.getLine()+2);
	line2 = Line(20);
	display(line);
	line2.display();
	return 0;
}