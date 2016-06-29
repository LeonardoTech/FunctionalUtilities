////////////
//    created by 孙庆号
////////////

#ifndef __PROCESSING_H__
#define __PROCESSING_H__
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <iostream>
#include <string>

namespace import{
template<class T>
class ImportContext;

template<class T>
struct Coord2D
{
	T x, y;
	bool read(std::istream& is)
	{
		is >> x >> y;
		return is;
	}
};
typedef Coord2D<float> Coord2DF;
typedef Coord2D<double> Coord2DD;

template<class T>
struct Interval
{
	T start, end;
	bool read(std::istream& is)
	{
		is >> start >> end;
		return is;
	}
};
typedef Interval<float> IntervalF;
typedef Interval<double> IntervalD;

template<class T>
struct Coord3D : public Coord2D<T>
{
	T z;
	bool read(std::istream& is){
		is >> x >> y >> z;
		return is;
	}
};
typedef Coord3D<float> Coord3DF;
typedef Coord3D<double> Coord3DD;

template<class T>
bool readFrom(std::vector<Coord3D<T> >& seq, std::istream& is)
{
	int count;
	if(!(is >> count) || count <= 0)
		return false;
			
	seq.resize(count);
	T* coords = reinterpret_cast<T*>(&seq[0]);
	count *= 3;
	for(int i = 0;i < count;++ i)
		is >> coords[i];
	return is;
}

template<class T>
bool readFrom(std::vector<T>& seq, std::istream& is)
{
	int count;
	if(!(is >> count) || count <= 0)
		return false;
		
	seq.resize(count);
	for(int i = 0;i < count;++ i)
		is >> seq[i];
	return is;
}

template<class T>
struct UVBOX
{
	Coord2D<T> min;
	Coord2D<T> max;
	bool read(std::istream& is)
	{
		min.read(is);
		max.read(is);
		return is;
	}
};
typedef UVBOX<float> UVBOXF;
typedef UVBOX<double> UVBOXD;

template<class T>
class Object
{
public:
	virtual void getRefObjects(std::set<Object*>& objs)
	{
	}
	virtual ~Object()
	{
	}
};
template<class Seq, class Set>
void getRefObjects(Seq& seq, Set& all)
{
	size_t objCount = seq.size();
	for(size_t i = 0;i < objCount;++ i)
	{
		if(all.find(seq[i]) == all.end())
		{
			all.insert(seq[i]);
			seq[i]->getRefObjects(all);
		}
	}
}
typedef Object<float> ObjectF;
typedef Object<double> ObjectD;

template<class T>
class Geometry : public Object<T>
{
};
typedef Geometry<float> GeometryF;
typedef Geometry<double> GeometryD;

template<class T>
class Element : public Object<T>
{
public:
	static Element* readFrom(std::istream& is, ImportContext<T>* context);
	Element()
	{
		id = -1;
	}
	int getId()
	{
		return id;
	}
	static const char* name()
	{
		return "id";
	}
	std::vector<Object<T>*>& getObjs()
	{
		return objs;
	}
	virtual void getRefObjects(std::set<Object*>& objs)
	{
		import::getRefObjects(this->objs, objs);
	}
private:
	int id;
	std::vector<Object<T>*> objs;
};
typedef Element<float> ElementF;
typedef Element<double> ElementD;

template<class T>
class Surface : public Geometry<T>{
};
typedef Surface<float> SurfaceF;
typedef Surface<double> SurfaceD;

template<class T>
class Curve : public Geometry<T>{
};
typedef Curve<float> CurveF;
typedef Curve<double> CurveD;

template<class T>
class Edge : public Geometry<T>
{
	Curve<T>* curve;
public:
  	//curve
	static Edge* readFrom(std::istream& is, ImportContext<T>* context);
	static const char* name()
	{
		return "edge";
	}
	Curve<T>* getCurve()
	{
		return curve;
	}
	virtual void getRefObjects(std::set<Object*>& objs)
	{
		objs.insert(curve);
	}
};
typedef Edge<float> EdgeF;
typedef Edge<double> EdgeD;

template<class T>
class Mesh : public Surface<T>
{
	std::vector<Coord3D<T> > points;
	std::vector<Coord3D<int> > vertices;
public:
	static Mesh* readFrom(std::istream& is, ImportContext<T>* context);
	//vertexCount 3DPoints triangleCount triangleVertexIndex
	static const char* name()
	{
		return "mesh";
	}
	bool read(std::istream& is)
	{
		import::readFrom(points, is);
		return import::readFrom(vertices, is);
	}
	const std::vector<Coord3D<T> >& getPoints()
	{
		return points;
	}
	const std::vector<Coord3D<int> >& getVertices()
	{
		return vertices;
	}
};
typedef Mesh<float> MeshF;
typedef Mesh<double> MeshD;

template<class T>
class Point : public Geometry<T>
{
	Coord3D<T> coord;
public:  	
	static Point* readFrom(std::istream& is, ImportContext<T>* context);
	//coordinate
	static const char* name()
	{
		return "point";
	}
	bool read(std::istream& is)
	{
		return coord.read(is);
	}
};
typedef Point<float> PointF;
typedef Point<double> PointD;

template<class T>
class PolyLine : public Geometry<T>
{
	std::vector<Coord3D<T> > points;
public:
	static PolyLine* readFrom(std::istream& is, ImportContext<T>* context);
	//pointCount 3DPoints
	static const char* name()
	{
		return "polyLine";
	}
	bool read(std::istream& is)
	{
		return import::readFrom(points, is);
	}
	const std::vector<Coord3D<T> >& getPoints()
	{
		return points;
	}
};
typedef PolyLine<float> PolyLineF;
typedef PolyLine<double> PolyLineD;

template<class T>
class Solid : public Geometry<T>
{
	std::vector<Geometry<T>* > geoms;
public:
	static Solid* readFrom(std::istream& is, ImportContext<T>* context);
	//solidBegin geometries solidEnd
	static const char* name()
	{
		return "solidBegin";
	}
	const std::vector<Geometry<T>* >& getGeometries()
	{
		return geoms;
	}
	virtual void getRefObjects(std::set<Object*>& objs)
	{
		import::getRefObjects(this->geoms, objs);
	}
};
typedef Solid<float> SolidF;
typedef Solid<double> SolidD;

template<class T>
class Material : public Object<T>
{
public:
	static Material* readFrom(std::istream& is, ImportContext<T>* context);
	static const char* name()
	{
		return "material";
	}
	bool read(std::istream& is)
	{
		return is;
	}
};
typedef Material<float> MaterialF;
typedef Material<double> MaterialD;

template<class T>
class Transform : public Geometry<T>
{
	std::vector<Geometry<T>* > geoms;
public:
	T matrix[12];
	static Transform* readFrom(std::istream& is, ImportContext<T>* context);
	//3 X 4 matrix
	//firstColumn secondColumn thirdColumn fourthColumn
	static const char* name()
	{
		return "transform";
	}
	bool read(std::istream& is)
	{
		double scale;
		is >> scale;
		for(int i = 0;i < 12;++ i)
		{
			is >> matrix[i];
			matrix[i] *= scale;
		}
		return is;
	}
	const std::vector<Geometry<T>* >& getGeometries()
	{
		return geoms;
	}
	virtual void getRefObjects(std::set<Object*>& objs)
	{
		import::getRefObjects(this->geoms, objs);
	}
};
typedef Transform<float> TransformF;
typedef Transform<double> TransformD;

template<class T>
class Arc : public Curve<T>
{
	T radius, period;
	Coord3D<T> center, xDirection, yDirection;
public:
  	//radius period center xdirection ydirection
	static Arc* readFrom(std::istream& is, ImportContext<T>* context);
	static const char* name()
	{
		return "arc";
	}
	bool read(std::istream& is)
	{
		is >> radius;
		is >> period;
		center.read(is);
		xDirection.read(is);
		return yDirection.read(is);
	}
	T getRadius()
	{
		return radius;
	}
	T getPeroid()
	{
		return period;
	}
	const Coord3D<T>& getCenter()
	{
		return center;
	}
	const Coord3D<T>& getXDirection()
	{
		return xDirection;
	}
	const Coord3D<T>& getYDirection()
	{
		return yDirection;
	}
};
typedef Arc<float> ArcF;
typedef Arc<double> ArcD;

template<class T>
class CylindricalHelix : public Curve<T>
{
	T radius;
	Interval<T> interval;
	T pitch;
	Coord3D<T> basePoint, xVector, zVector; 
public:
	static CylindricalHelix* readFrom(std::istream& is, ImportContext<T>* context);
	//radius startParam endParam pitch basePoint YVector ZVector
	static const char* name()
	{
		return "cylindricalHelix";
	}
	bool read(std::istream& is)
	{
		is >> radius;
		interval.read(is);
		is >> pitch;
		basePoint.read(is);
		xVector.read(is);
		return zVector.read(is);
	}
};
typedef CylindricalHelix<float> CylindricalHelixF;
typedef CylindricalHelix<double> CylindricalHelixD;

template<class T>
class Ellipse : public Curve<T>
{
	T radiusX, radiusY;
	Interval<T> interval;
	Coord3D<T> center, xDirection, yDirection;
public:	
	static Ellipse* readFrom(std::istream& is, ImportContext<T>* context);
	//radiusX radiusY startParam endParam Center XDirection YDirection
	static const char* name()
	{
		return "ellipse";
	}
	bool read(std::istream& is)
	{
		is >> radiusX >> radiusY;
		interval.read(is);
		center.read(is);
		xDirection.read(is);
		return yDirection.read(is);
	}
};
typedef Ellipse<float> EllipseF;
typedef Ellipse<double> EllipseD;

template<class T>
class HermiteSpline : public Curve<T>
{
	Interval<T> interval;
	std::vector<Coord3D<T> > controlPoints;
	std::vector<Coord3D<T> > tagents;
	std::vector<T> parameters;
public:
	static HermiteSpline* readFrom(std::istream& is, ImportContext<T>* context);
	//startParam endParam controlPointCount controlPoints tagentsCount tangents parameterSize parameters
	static const char* name()
	{
		return "hermiteSpline";
	}
	bool read(std::istream& is)
	{
		interval.read(is);
		import::readFrom(controlPoints, is);
		import::readFrom(tagents, is);
		return import::readFrom(parameters, is);
	}
};
typedef HermiteSpline<float> HermiteSplineF;
typedef HermiteSpline<double> HermiteSplineD;

template<class T>
class Line : public Curve<T>
{
	Interval<T> interval;
	Coord3D<T> origin, direction;
public:
	static Line* readFrom(std::istream& is, ImportContext<T>* context);
	//startParam endParam origin direction
	static const char* name()
	{
		return "line";
	}
	bool read(std::istream& is)
	{
		interval.read(is);
		origin.read(is);
		return direction.read(is);
	}
};
typedef Line<float> LineF;
typedef Line<double> LineD;

template<class T>
class NurbsSpline : public Curve<T>
{
	Interval<T> interval;
	int degree;
	bool isClosed, isRational;
	std::vector<T> knots;
	std::vector<Coord3D<T> > controlPoints;
public:
	static NurbsSpline* readFrom(std::istream& is, ImportContext<T>* context);
	//startParam endParam degree isClosed isRational knotSize knots controlPointCount controlPoints
	static const char* name()
	{
		return "nurbsSpline";
	}
	bool read(std::istream& is)
	{
		interval.read(is);
		is >> degree >> isClosed >> isRational;
		import::readFrom(knots, is);
		return import::readFrom(controlPoints, is);
	}
};
typedef NurbsSpline<float> NurbsSplineF;
typedef NurbsSpline<double> NurbsSplineD;

template<class T>
class ConicalFace : public Surface<T>
{
	T halfAngle;
	Coord3D<T> radiusVector;
	UVBOX<T> uv;
	Coord3D<T> origin;
	Coord3D<T> axis;
public:
	static ConicalFace* readFrom(std::istream& is, ImportContext<T>* context);
	//halfAngle radiusVector UVBox origin axis
	static const char* name()
	{
		return "conicalFace";
	}
	bool read(std::istream& is)
	{
		is >> halfAngle;
		radiusVector.read(is);
		uv.read(is);
		origin.read(is);
		return axis.read(is);
	}
};
typedef ConicalFace<float> ConicalFaceF;
typedef ConicalFace<double> ConicalFaceD;

template<class T>
class CylindricalFace : public Surface<T>
{
	Coord3D<T> radiusVector;
	UVBOX<T> uv;
	Coord3D<T> origin;
	Coord3D<T> axis;
public:
	static CylindricalFace* readFrom(std::istream& is, ImportContext<T>* context);
	//radiusVector UVBOX origin axis 
	static const char* name()
	{
		return "cylindricalFace";
	}
	bool read(std::istream& is)
	{
		radiusVector.read(is);
		uv.read(is);
		origin.read(is);
		return axis.read(is);
	}
	const UVBOX<T>& getUVBOX()
	{
		return uv;
	}
	const Coord3D<T>& getOrigin()
	{
		return origin;
	}
	const Coord3D<T>& getAxis()
	{
		return axis;
	}
	const Coord3D<T>& getRadiusVector()
	{
		return radiusVector;
	}
};
typedef CylindricalFace<float> CylindricalFaceF;
typedef CylindricalFace<double> CylindricalFaceD;

template<class T>
class HermiteFace : public Surface<T>
{
public:
	static HermiteFace* readFrom(std::istream& is, ImportContext<T>* context);
	//
	static const char* name()
	{
		return "hermiteFace";
	}
	bool read(std::istream& is)
	{
		return is;
	}
};
typedef HermiteFace<float> HermiteFaceF;
typedef HermiteFace<double> HermiteFaceD;

template<class T>
class PlanarFace : public Surface<T>
{
	UVBOX<T> uv;
	Coord3D<T> origin;
	Coord3D<T> uDirection, vDirection;
public:
	static PlanarFace* readFrom(std::istream& is, ImportContext<T>* context);
	//UVBOX origin normal
	static const char* name()
	{
		return "planarFace";
	}
	bool read(std::istream& is)
	{
		uv.read(is);
		origin.read(is);
		uDirection.read(is);
		return vDirection.read(is);
	}
	const UVBOX<T>& getUVBOX()
	{
		return uv;
	}
	const Coord3D<T>& getOrigin()
	{
		return origin;
	}
	const Coord3D<T>& getUDirection()
	{
		return uDirection;
	}
	const Coord3D<T>& getVDirection()
	{
		return vDirection;
	}
};
typedef PlanarFace<float> PlanarFaceF;
typedef PlanarFace<double> PlanarFaceD;

template<class T>
class RevolvedFace : public Surface<T>
{
	UVBOX<T> uv;
	Coord3D<T> origin;
	Coord3D<T> axis;
	Curve<T> *curve;
public:
	RevolvedFace()
	{
		curve = NULL;
	}
	static RevolvedFace* readFrom(std::istream& is, ImportContext<T>* context);
	//UVBOX origin axis curve
	static const char* name(){
		return "revolvedFace";
	}
	bool read(std::istream& is){
		uv.read(is);
		origin.read(is);
		return axis.read(is);
	}
	Curve<T>* getCurve(){
		return curve;
	}
	virtual void getRefObjects(std::set<Object*>& objs){
		objs.insert(curve);
	}
};
typedef RevolvedFace<float> RevolvedFaceF;
typedef RevolvedFace<double> RevolvedFaceD;


template<class T>
class RuledFace : public Surface<T>
{
public:
	static RuledFace* readFrom(std::istream& is, ImportContext<T>* context);
	//
	static const char* name(){
		return "ruledFace";
	}
};
typedef RuledFace<float> RuledFaceF;
typedef RuledFace<double> RuledFaceD;

template<class T>
class ImportContext{
public:
	typedef Object<T>* (*ReadFunc)(std::istream& is, ImportContext* context);
	ImportContext(){
		funcMap[Element<T>::name()] = (ReadFunc)Element<T>::readFrom;
		funcMap[Edge<T>::name()] = (ReadFunc)Edge<T>::readFrom;
		funcMap[Mesh<T>::name()] = (ReadFunc)Mesh<T>::readFrom;
		funcMap[Point<T>::name()] = (ReadFunc)Point<T>::readFrom;
		funcMap[PolyLine<T>::name()] = (ReadFunc)PolyLine<T>::readFrom;
		funcMap[Solid<T>::name()] = (ReadFunc)Solid<T>::readFrom;
		funcMap[Material<T>::name()] = (ReadFunc)Material<T>::readFrom;
		funcMap[Transform<T>::name()] = (ReadFunc)Transform<T>::readFrom;
		funcMap[Arc<T>::name()] = (ReadFunc)Arc<T>::readFrom;
		funcMap[CylindricalHelix<T>::name()] = (ReadFunc)CylindricalHelix<T>::readFrom;
		funcMap[Ellipse<T>::name()] = (ReadFunc)Ellipse<T>::readFrom;
		funcMap[HermiteSpline<T>::name()] = (ReadFunc)HermiteSpline<T>::readFrom;
		funcMap[Line<T>::name()] = (ReadFunc)Line<T>::readFrom;
		funcMap[NurbsSpline<T>::name()] = (ReadFunc)NurbsSpline<T>::readFrom;
		funcMap[ConicalFace<T>::name()] = (ReadFunc)ConicalFace<T>::readFrom;
		funcMap[CylindricalFace<T>::name()] = (ReadFunc)CylindricalFace<T>::readFrom;
		funcMap[HermiteFace<T>::name()] = (ReadFunc)HermiteFace<T>::readFrom;
		funcMap[PlanarFace<T>::name()] = (ReadFunc)PlanarFace<T>::readFrom;
		funcMap[RevolvedFace<T>::name()] = (ReadFunc)RevolvedFace<T>::readFrom;
		funcMap[RuledFace<T>::name()] = (ReadFunc)RuledFace<T>::readFrom;
		funcMap["ref"] = ImportContext::readRef;
		funcMap["geoId"] = ImportContext::readGeoObjWithId;
	}
	bool read(std::istream& is)
	{
		int version = -1;
		std::string str;

		if(!(is >> version) || version != 1){
			std::cerr << "version " << version << " not supported" << std::endl;
			return false;
		}
		std::getline(is, str);
		if(!(is >> str) || str != "mapBegin"){
			std::cerr << "invalid file format 'mapBegin' expected" << std::endl;
			return false;
		}
		while((is >> str) && str != "mapEnd"){
			std::map<std::string, ReadFunc>::iterator pos = funcMap.find(str);
			ReadFunc readFunc = NULL;
			if(pos != funcMap.end()){
				readFunc = pos->second;
			}
			if(!(is >> code) && code.size() != 1){
				std::cerr << code << " is too long, we're only expecting one character" << std::endl;
				return false;
			}
			readFuncs[code[0]] = readFunc;
			codeNames[code[0]] = str;
		}

		code.clear();
		if(!is){
			std::cerr << "invalid file format" << std::endl;
		}
		while(is){
			Object<T>* obj = readCurrent(is);
			if(obj == NULL){
				if(!is.eof()){
					std::cerr << "read data failed" << std::endl;
					return false;
				}
				return true;
			}
			objects.push_back(obj);
		}
		return is;
	}
	Object<T>* readCurrent(std::istream& is)
	{
		if(readCode(is))
			return readData(is);
		return NULL;
	}
	Object<T>* readData(std::istream& is)
	{
		if(readFuncs[code[0]] == NULL){
			std::cerr << "no handler is defined for this type " << code << std::endl;
			return NULL;
		}
		return (readFuncs[code[0]])(is, this);
	}
	bool readCode(std::istream& is)
	{
		if(!(is >> code)){
			if(!is.eof())
				std::cerr << "read object type failed" << std::endl;
			return false;
		}
		if(code.size() != 1){
			std::cerr << code << " is too long, we're only expecting one character" << std::endl;
			return false;
		}
		return true;
	}
	const std::string& getCurrentName()
	{
		if(code.size() != 1)
			return codeNames[256];
		return codeNames[code[0]];
	}
	static Object<T>* readRef(std::istream& is, ImportContext* context)
	{
		int id;
		if(!(is >> id)){
			std::cerr << "failed to get id of referenced object" << std::endl;
			return NULL;
		}
		std::map<int, Object<T>* >::iterator pos = context->idToObjMap.find(id);
		if(pos == context->idToObjMap.end()){
			std::cerr << "object with id " << id << " does not exist" << std::endl;
			return NULL;
		}
		return pos->second;
	}
	static Object<T>* readGeoObjWithId(std::istream& is, ImportContext* context)
	{
		int id;
		if(!(is >> id)){
			std::cerr << "failed to get id of geometry object" << std::endl;
			return NULL;
		}
		Object<T>* obj = context->readCurrent(is);
		if(obj == NULL){
			std::cerr << "failed to get object of id " << id << std::endl;
			return NULL;
		}
		if(context->idToObjMap.find(id) != context->idToObjMap.end()){
			std::cerr << "object with this id " << id << " already exist" << std::endl;
			delete obj;
			return NULL;
		}
		context->idToObjMap[id] = obj;
		return obj;
	}
	void addElement(Element<T>* element)
	{
		element->getObjs().swap(objects);
		elements.push_back(element);
		objects.clear();
	}
	const std::vector<Element<T>* >& getElements()
	{
		return elements;
	}
	const std::map<int, Object<T>* >& getSharedObjs()
	{
		return idToObjMap;
	}
	~ImportContext()
	{
		std::set<Object<T>* > all;
		import::getRefObjects(objects, all);
		import::getRefObjects(elements, all);
		std::set<Object<T>* >::iterator begin = all.begin(), end = all.end();
		while(begin != end)
		{
			delete *begin;
			++begin;
		}
	}
private:
	ImportContext& operator=(const ImportContext&);
	ImportContext(const ImportContext&);
	std::string code;
	std::map<std::string, ReadFunc> funcMap;
	std::vector<Object<T>* > objects;
	std::vector<Element<T>* > elements;
	std::map<int, Object<T>* > idToObjMap;
	ReadFunc readFuncs[256];
	std::string codeNames[257];
};
typedef ImportContext<float> ImportContextF;
typedef ImportContext<double> ImportContextD;

template<class T>
Edge<T>* Edge<T>::readFrom(std::istream& is, ImportContext<T>* context)
{
	Object<T>* obj = context->readCurrent(is);
	Curve<T>* curve = dynamic_cast<Curve<T>*>(obj);
	if(curve == NULL)
	{
		std::cerr << "curve expected for edge" << std::endl;
		delete obj;
		return NULL;
	}
	Edge<T>* edge = new Edge<T>();
	edge->curve = curve;
	return edge;
}
#define READ_FROM_FUNCTION(Type, ErrMsg)\
template<class T>\
Type<T>* Type<T>::readFrom(std::istream& is, ImportContext<T>* context){\
	Type<T>* obj = new Type<T>();\
	if(obj->read(is))\
		return obj;\
	std::cerr << ErrMsg << std::endl;\
	delete obj;\
	return NULL;\
}

READ_FROM_FUNCTION(Mesh, "invalid Mesh object")
READ_FROM_FUNCTION(Point, "invalid Point object")
READ_FROM_FUNCTION(PolyLine, "invalid PolyLine object")
READ_FROM_FUNCTION(Arc, "invalid Arc object")
READ_FROM_FUNCTION(CylindricalHelix, "invalid CylindricalHelix object")
READ_FROM_FUNCTION(Ellipse, "invalid Ellipse object")
READ_FROM_FUNCTION(HermiteSpline, "invalid HermiteSpline object")
READ_FROM_FUNCTION(Line, "invalid Line object")
READ_FROM_FUNCTION(NurbsSpline, "invalid NurbsSpline object")
READ_FROM_FUNCTION(ConicalFace, "invalid ConicalFace object")
READ_FROM_FUNCTION(CylindricalFace, "invalid CylindricalFace object")
READ_FROM_FUNCTION(PlanarFace, "invalid PlanarFace object")
READ_FROM_FUNCTION(HermiteFace, "invalid HermiteFace object")
READ_FROM_FUNCTION(Material, "invalid Material object")

template<class T>
Solid<T>* Solid<T>::readFrom(std::istream& is, ImportContext<T>* context)
{
	Solid<T>* solid = new Solid<T>();
	while(true){
		if(!context->readCode(is)){
			delete solid;
			std::cerr << "invalid Solid object" << std::endl;
			return NULL;
		}
		if(context->getCurrentName() == "solidEnd"){
			break;
		}
		Object<T>* obj = context->readData(is);
		Geometry<T>* geo = dynamic_cast<Geometry<T>*>(obj);
		if(geo == NULL){
			std::cerr << "Geometry expected" << std::endl;
			delete obj;
			return NULL;
		}
		solid->geoms.push_back(geo);
	}
	return solid;
}
template<class T>
Transform<T>* Transform<T>::readFrom(std::istream& is, ImportContext<T>* context)
{
	Transform<T>* transform = new Transform<T>();
	if(!transform->read(is)){
		std::cerr << "invalid transform object" << std::endl;
		delete transform;
		return NULL;
	}
	while(true){
		if(!context->readCode(is)){
			delete transform;
			std::cerr << "invalid Solid object" << std::endl;
			return NULL;
		}
		if(context->getCurrentName() == "transformEnd")
		{
			break;
		}
		Object<T>* obj = context->readData(is);
		Geometry<T>* geo = dynamic_cast<Geometry<T>*>(obj);
		if(geo == NULL){
			std::cerr << "Geometry expected" << std::endl;
			delete obj;
			return NULL;
		}
		transform->geoms.push_back(geo);
	}
	return transform;
}
template<class T>
RevolvedFace<T>* RevolvedFace<T>::readFrom(std::istream& is, ImportContext<T>* context)
{
	RevolvedFace<T>* revolvedFace = new RevolvedFace<T>();
	if(!revolvedFace->read(is)){
		std::cerr << "invalid RevolvedFace object" << std::endl;
		return NULL;
	}
	Object<T>* obj = context->readCurrent(is);
	Curve<T>* curve = dynamic_cast<Curve<T>*>(obj);
	if(curve == NULL){
		std::cerr << "Geometry expected" << std::endl;
		delete obj;
		return NULL;
	}
	revolvedFace->curve = curve;
	return revolvedFace;
}

template<class T>
RuledFace<T>* RuledFace<T>::readFrom(std::istream& is, ImportContext<T>* context)
{
	return new RuledFace<T>();
}

template<class T>
Element<T>* Element<T>::readFrom(std::istream& is, ImportContext<T>* context)
{
	int id;
	if(!(is >> id)){
		std::cerr << "failed to get id of element" << std::endl;
		return NULL;
	}

	Element<T>* element = new Element<T>();
	element->id = id;
	context->addElement(element);
	return element;
}
}

#endif // __PROCESSING_H__