#ifndef __VERTEX_ARRAY_H__
#define __VERTEX_ARRAY_H__
#include <vector>

/// @class	Vertex
///
/// @brief	 <设置一个顶点坐标类型的类，用于存放点的坐标，供接口使用>.
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
		/// @brief	  <获取Vertex的内容>.
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @param	other	<获取内容>.

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
		/// @brief	  <将浮点值容器类型设置成Vertex类型>.
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
		/// @brief	Get <获取第一数值>.
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
		/// @brief <获取第二数值>.
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
		/// @brief	  <获取第三数值>.
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
		/// @brief	  <获取Vertex中的内容>.
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
	/// @brief	 <类型转换，将Vertex转化成VertexArray类型>.
	typedef std::vector < Vertex > VertexArray;
}
#endif // __VERTEX_ARRAY_H__
