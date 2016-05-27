#include "ModelController.h"

//
//osgText::Text* createText(const osg::Vec3& pos, std::string content, float size)
//{
//	osg::ref_ptr<osgText::Text> text = new osgText::Text;
//	text->setFont(g_font.get());
//	text->setCharacterSize(size);
//	text->setAxisAlignment(osgText::TextBase::XY_PLANE);
//	text->setPosition(pos);
//	text->setText(content);
//	return text.release();
//}

float x = 0.0;
float y = 0.0;
float z = 0.0;
std::stringstream ss;
string info;
string a;

bool ModelController::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{

	if (!_model) return false;
	osg::Matrix matrix = _model->getMatrix();
	//char xchar[20];
	//char ychar[20];
	//char zchar[20];
	int n = 4;
	switch (ea.getEventType())
	{
	case osgGA::GUIEventAdapter::KEYDOWN:
		switch (ea.getKey())
		{
		case 'x': case 'X':
			_axis->getAxisDirection(X_Coordinate, x, y, z);
			info.empty();
			info.clear();
			ss.str("");
			ss << "the Axis of  X_Axis is : " << x << "  " << y << "  " << z;
			info = ss.str();
			mutex.lock();
			_text->setText(info);
			_text->setPosition(osg::Vec3(250.0f, 500.0f, 0.0f));
			mutex.unlock();
			break;
		case 'y': case 'Y':
			_axis->getAxisDirection(Y_Coordinate, x, y, z);
			info.empty();
			info.clear();
			ss.str("");
			ss << "the Axis of  Y_Axis is : " << x << "  " << y << "  " << z;
			info = ss.str();
			mutex.lock();
			_text->setText(info);
			_text->setPosition(osg::Vec3(250.0f, 500.0f, 0.0f));
			mutex.unlock();
			break;
		case 'z': case 'Z':
			_axis->getAxisDirection(Z_Coordinate, x, y, z);
			info.clear();
			info.empty();
			ss.str("");
			ss << "the Axis of  Z_Axis is :  " << x << "  " << y << "  " << z;
			info = ss.str();
			mutex.lock();
			_text->setText(info);
			_text->setPosition(osg::Vec3(250.0f, 500.0f, 0.0f));
			mutex.unlock();
			break;
		default:
			break;
		}
		_model->setMatrix(matrix);
		break;
	default:
		break;
	}
	return false;
}


osg::Camera* createHUDCamera(double left, double right, double bottom, double top)
{
	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	camera->setClearMask(GL_DEPTH_BUFFER_BIT);
	camera->setRenderOrder(osg::Camera::POST_RENDER);
	camera->setAllowEventFocus(true);
	camera->setProjectionMatrix(
		osg::Matrix::ortho2D(left, right, bottom, top));
	return camera.release();
}