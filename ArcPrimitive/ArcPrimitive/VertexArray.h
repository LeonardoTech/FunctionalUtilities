#ifndef __VERTEX_ARRAY_H__
#define __VERTEX_ARRAY_H__
#include <vector>

/// @class	Vertex
///
/// @brief	 <����һ�������������͵��࣬���ڴ�ŵ�����꣬���ӿ�ʹ��>.
///
/// @author	Admin
/// @date	2016/3/23

namespace geo
{
	class Vertex
	{
	public:
		Vertex() :
			_vertices(3)
		{
			_vertices[0] = 0;
			_vertices[1] = 0;
			_vertices[2] = 0;
		}
		Vertex(const double x, const double y, const double z) :
			Vertex::Vertex()
		{
			set(x, y, z);
		}
		/// @fn	Vertex::Vertex(const Vertex& other)
		///
		/// @brief	  <��ȡVertex������>.
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @param	other	<��ȡ����>.

		Vertex(const Vertex& other)
		{
			_vertices = other.getVector();
		}

		void set(const double x, const double y, const double z)
		{
			_vertices[0] = x;
			_vertices[1] = y;
			_vertices[2] = z;
		}

		void setX(double x)
		{
			_vertices[0] = x;
		}
		void setY(double y)
		{
			_vertices[1] = y;
		}
		void setZ(double z)
		{
			_vertices[2] = z;
		}
		/// @fn	void Vertex::setVertices(const std::vector<float>& vertices)
		///
		/// @brief	  <������ֵ�����������ó�Vertex����>.
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @param	vertices	The vertices.
		void setVertices(const std::vector<double>& vertices)
		{
			_vertices = vertices;
		}

		/// @fn	virtual float Vertex::getX() const
		///
		/// @brief	Get <��ȡ��һ��ֵ>.
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @return	The x coordinate.
		virtual double x() const
		{
			return _vertices[0];
		}

		/// @fn	virtual float Vertex::getY() const
		///
		/// @brief <��ȡ�ڶ���ֵ>.
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @return	The y coordinate.
		virtual double y() const
		{
			return _vertices[1];
		}

		/// @fn	virtual float Vertex::getZ() const
		///
		/// @brief	  <��ȡ������ֵ>.
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @return	The z coordinate.
		virtual double z() const
		{
			return _vertices[2];
		}

		/// @fn	std::vector<float> Vertex::getVector() const
		///
		/// @brief	  <��ȡVertex�е�����>.
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @return	The vector.
		std::vector<double> getVector() const
		{
			return _vertices;
		}

	protected:
		std::vector<double> _vertices;
	};

	/// @typedef	std::vector < Vertex > VertexArray
	///
	/// @brief	 <����ת������Vertexת����VertexArray����>.
	typedef std::vector < Vertex > VertexArray;
}
#endif // __VERTEX_ARRAY_H__
