#ifndef __VERTEX_ARRAY_H__
#define __VERTEX_ARRAY_H__
#include <vector>


class Vertex
{
public:
	Vertex():
		_vertices(3)
	{
		_vertices[0] = 0;
		_vertices[1] = 0;
		_vertices[2] = 0;
	}

	Vertex(const Vertex& other)
	{
		_vertices = other.getVector();
	}

	void setVertices(const std::vector<float>& vertices)
	{
		_vertices = vertices;
	}

	virtual float getX() const
	{
		return _vertices[0];
	}
	virtual float getY() const
	{
		return _vertices[1];
	}
	virtual float getZ() const
	{
		return _vertices[2];
	}

	std::vector<float> getVector() const
	{
		return _vertices;
	}

protected:
	std::vector<float> _vertices;
};

typedef std::vector < Vertex > VertexArray;

#endif // __VERTEX_ARRAY_H__
