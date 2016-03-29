#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>	


class ModelController : public osgGA::GUIEventHandler
{
public:
	ModelController(osg::MatrixTransform* node)
		: _model(node)
	{}
	virtual bool handle(const osgGA::GUIEventAdapter& ea,
		osgGA::GUIActionAdapter& aa);

protected:
	osg::ref_ptr<osg::MatrixTransform> _model;
};


