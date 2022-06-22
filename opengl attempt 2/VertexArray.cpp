
#include "VertexArray.h"
//#include <vector>

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &arrayrenderID);
	

}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &arrayrenderID);
}

void VertexArray::AddBuffer(const VertexBuffer& VB, const VertexBufferLayout& layout)
{
	Bind();
	VB.Bind();
	const auto& elements = layout.GetElements();
	for(unsigned int i = 0; i< elements.size(); i++)
	{ 
		const auto& element = elements[i];
		unsigned int offset = 0;
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride() , (const void*)offset);
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind()
{
	std::cout << "Array Bound" << std::endl;
	glBindVertexArray(arrayrenderID);
}

void VertexArray::Unbind()
{
	std::cout << "Array Unbound" << std::endl;
	glBindVertexArray(0);
}
