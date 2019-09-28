/* Composite Pattern */
#include <vector>

class Graphic{
	virtual void print() const = 0;
}

class CompositeGraphic : Graphic 
{
private:
	std::vector<Graphic> v_graphic;
public:
	
	void print()
	{
		std::cout << "Composite Graphic" << std::endl;
	}

	void add(Grapic graphic)
	{
		v_graphic.push_back(graphic);
	}

	void remove(Graphic graphic)
	{
		for(i_graphic : v_graphic)
		{
			if (i_graphic == graphic)
			{
				v_graphic.erase(i_graphic);
			}		
		}
		
	}
}

class Elipse : Graphic 
{
	void print()
	{
		std::cout << "Elipse" << std::endl;
	}
}

class Rectangle : Graphic 
{
	void print()
	{
		std::cout << "Rectangle" << std::endl;
	}
}