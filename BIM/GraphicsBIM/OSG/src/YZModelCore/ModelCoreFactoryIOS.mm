#include "ModelCoreFactoryIOS.h"
//#include <osgViewer/GraphicsWindow>
USE_GRAPICSWINDOW_IMPLEMENTATION(IOS)
#include <osgViewer/api/IOS/GraphicsWindowIOS>
#include <osgDB/FileUtils>
#include <osgGA/MultiTouchTrackballManipulator>

  namespace{

#include <osg/Notify>
    struct SetNotifyLevel{
      SetNotifyLevel(){
        //osg::setNotifyLevel(osg::DEBUG_INFO);
      }
    }instance;
    const char *defaultVertexShader =
      "attribute vec4 position;\n\
      attribute vec3 normal;\n\
      attribute vec4 color;\n\
      \n\
      varying lowp vec4 colorVarying;\n\
      \n\
      uniform mat4 osg_modelviewprojectionmatrix;\n\
      uniform mat3 osg_normalmatrix;\n\
      void main()\n\
      {\n\
        \n\
          //don't want specicail lighting calculations,\
          //it also not working under gles2\
          //vec3 eyenormal = normalize(osg_normalmatrix * normal);\n\
          //vec3 lightposition = vec3(1.0, 1.0, 1.0);\n\
          //vec4 diffusecolor = vec4(0.4, 0.4, 1.0, 1.0);\n\
          //\n\
          //float ndotvp = max(0.5, dot(eyenormal, normalize(lightposition)));\n\
          //\n\
          //colorvarying = diffusecolor * ndotvp;\n\
          colorVarying = color;\n\
          gl_Position = osg_ModelViewProjectionMatrix * position;\n\
          \n\
      }\n\
    ";
    const char *defaultFragmentShader =
      "varying lowp vec4 colorVarying;\n\
      \n\
      void main()\n\
      {\n\
        gl_FragColor = colorVarying;\n\
      }";
    class SetupDefaultShader : public osg::NodeVisitor{
      osg::Program *program;
      osg::Program* getProgram(){
        if(program == NULL){
          program = new osg::Program;
          program->addBindAttribLocation("position", 0);
          program->addBindAttribLocation("color", 3);
          program->addBindAttribLocation("normal", 2);
          program->addShader(new osg::Shader(osg::Shader::VERTEX, defaultVertexShader));
          program->addShader(new osg::Shader(osg::Shader::FRAGMENT, defaultFragmentShader));
        }
        return program;
      }
      public:
      SetupDefaultShader()  : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
      program(NULL){
      }
      void setShader(osg::StateSet *stateSet){
        if(stateSet){
          osg::Program *program = getProgram();
          stateSet->setAttribute(program, osg::StateAttribute::ON);
          stateSet->setAttributeAndModes(program, osg::StateAttribute::ON);
        }
      }

      void apply(osg::Node &node){
        setShader(node.getStateSet());
        traverse(node);
      }

      void apply(osg::Geode &geode){
        setShader(geode.getStateSet());
        for(unsigned int i=0; i<geode.getNumDrawables(); ++i){
          osg::Drawable *drawable = geode.getDrawable(i);
          setShader(drawable->getStateSet());
          //drawable->setColor(osg::Vec4(1.0, 0.0, 1.0, 1.0));
        }
      }
    };
    
 //   class ModelViewerImplIOS
	//{
 //     public:
 //     osgGA::CameraManipulator* createCameraManipulator(){
 //       return new bimWorld::BIMCameraManipulator(this, true, 0.02);
 //     }
 //       virtual osg::Node* readNode(const char *file){
 //       try{
 //         const char *ext = std::strrchr(file, '.');
 //         ext = (ext == NULL ? file : ext + 1);
 //         osgDB::ReaderWriter*  reader =
 //           osgDB::Registry::instance()->getReaderWriterForExtension(ext);
 //         if(reader == NULL){
 //           NSLog(@"cannot find reader writer for %s", ext);
 //           NSLog(@"read file %s failed", file);
 //           return NULL;
 //         }
 //         osgDB::ReaderWriter::ReadResult result =
 //           reader->readNode(file);
 //         if(!result.success()){
 //           NSLog(@"read file %s failed", file);
 //           NSLog(@"message %s", result.message().c_str());
 //           return NULL;
 //         }
 //         NSLog(@"read file %s succeed", file);
 //         // Optimize the model
 //         osgUtil::Optimizer optimizer;
 //         optimizer.optimize(result.getNode());
 //         optimizer.reset();
 //         setupShader(result.getNode());
 //         return result.takeNode();
 //       }catch(...){
 //         NSLog(@"exception read file %s", file);
 //         return NULL;
 //       }
 //     }
 //   };
  }
  namespace bimWorld{

	  void bimWorld::ModelCoreFactoryIOS::setupShader(osg::Node *node, std::shared_ptr<YZModelCoreInternal> core)
	  {
		  if (!useGLES2 || node == NULL)
		  {
			  return;
		  }
		  NSLog(@"setting up shaders...");
		  SetupDefaultShader sds;
		  node->setStateSet(core->_Materials()->_MaterialSetting()->getSelectionRenderModel());
		  osg::StateSet* stateset = node->getOrCreateStateSet();
		  //stateset->setColor(osg::Vec4(0.5, 0.5, 0.5,1));
		  sds.apply(*node);
	  }

	  std::shared_ptr<IModelCore> bimWorld::ModelCoreFactoryIOS::getModule(UIView *window,
		  bool useGLES2/* = false*/, bool fixedFrameRate/* = false*/, int ratio/* = 2*/)
	  {
          view = window;
          useGLES2 = useGLES2;
          fixedFrameRate = fixedFrameRate;
		  auto core = std::make_shared<YZModelCoreInternal>();
		  auto m_sceneRoot = core->_ViewerData()->getSceneRoot();
		  if (useGLES2)
			  setupShader(m_sceneRoot, core);

		  core->_ViewerData()->initOSG([this, window, ratio](osg::GraphicsContext::Traits* traits)
		  {
			  // Init the Windata Variable that holds the handle for the Window to display OSG in.
			  osg::ref_ptr<osg::Referenced> windata = new osgViewer::GraphicsWindowIOS::WindowData(view);
			  traits->x = view.bounds.origin.x;
			  traits->y = view.bounds.origin.y;
#if TARGET_IPHONE_SIMULATOR
			  traits->width = view.bounds.size.width;
			  traits->height = view.bounds.size.height;
#else
			  traits->width = view.bounds.size.width * ratio;
			  traits->height = view.bounds.size.height * ratio;
#endif
			  traits->inheritedWindowData = windata;
		  });
		  return core;
	  }
  //bool ModelViewerIOS::readMaterialSettingFromFile(const char *file){
  //  std::string fileName = osgDB::findDataFile(file);
  //  if(fileName.empty()){
  //    NSLog(@"cannot find material file %s", file);
  //    return false;
  //  }
  //    return ModelViewer::readMaterialSettingFromFile(fileName.c_str());
  //}
}