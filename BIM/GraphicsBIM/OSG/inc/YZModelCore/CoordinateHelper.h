////////////
//    created by 孙庆号
////////////

#ifndef __COORDINATEHELPLER_H_
#define __COORDINATEHELPLER_H_
#include <osg/Object>
#include <osg/Camera>
namespace util
{
	///-------------------------------------------------------------------------------------------------
	/// <summary>	A coordinate helper. </summary>
	///
	/// <remarks>	Sqh, 2015/5/6. </remarks>
	///-------------------------------------------------------------------------------------------------

	class CoordinateHelper : public osg::Referenced
	{
	public:
		CoordinateHelper(osg::Camera* camera) :
			m_camera(camera)
		{
		}

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Screen to world. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///
		/// <param name="screenPos">	[in,out] The screen position. </param>
		///
		/// <returns>	An osg::Vec3. </returns>
		///-------------------------------------------------------------------------------------------------

		osg::Vec3f ScreenToWorld(osg::Vec3f& screenPos)
		{
			updateMatrix();
			//
			return screenPos * m_inverseMVPW;
		}

		///-------------------------------------------------------------------------------------------------
		/// <summary>	World to screen. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///
		/// <param name="worldPos">	[in,out] The world position. </param>
		///
		/// <returns>	An osg::Vec3. </returns>
		///-------------------------------------------------------------------------------------------------

		osg::Vec3 WorldToScreen(osg::Vec3& worldPos)
		{
			updateMatrix();
			//
			auto result = worldPos * m_MVPW;
			return result;
		}

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets main camera. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///
		/// <returns>	The main camera. </returns>
		///-------------------------------------------------------------------------------------------------

		osg::ref_ptr<osg::Camera> getMainCamera()
		{
			return m_camera;
		}

	protected:
		//osg::ref_ptr<osgViewer::Viewer> m_viewer;
		osg::Matrix m_inverseMVPW;
		osg::Matrix m_MVPW;
		osg::ref_ptr<osg::Camera> m_camera;

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Updates the matrix. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		void updateMatrix()
		{
			auto camera = m_camera;
			m_MVPW = osg::Matrix(camera->getViewMatrix() *
				camera->getProjectionMatrix() *
				camera->getViewport()->computeWindowMatrix());

			m_inverseMVPW = osg::Matrix::inverse(m_MVPW);
		}
	};
}
#endif // __COORDINATEHELPLER_H_