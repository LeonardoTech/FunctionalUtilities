#include "TriangleMesh.h"
using namespace geo;


TriangleMesh::TriangleMesh()
{
 }

void TriangleMesh::drawImplementation(osg::RenderInfo& renderInfo)const
{
	glDrawArray();

}

void geo::TriangleMesh::glDrawArray() const
{
	const int Num = 360;
	int Ra;
	osg::Vec3 Plist[Num];

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, Plist);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, Ra + 1);
	glEnableClientState(GL_VERTEX_ARRAY);
}
