#ifndef __ITHUMBTACK_H__
#define __ITHUMBTACK_H__
#include <string>
#include <functional>
using namespace std;

namespace thumbtack_thumbtack_ithumbtack
{
	enum class Layer
	{
		Level0=1,
		Level1,
		Level2
	};
	class IThumbtack
	{
	public:
		// <在模型控件中显示图钉，支持显示指定的图片，点击出发相应的事件>
		// <在不同的比例尺下会变更显示的图片以及大小，默认提供三级比例尺下的变更>
		virtual void setLevelImage(const std::string& level0, const std::string& level1, const std::string& level2)=0;

		virtual void bindClick(long,std::function<void(IThumbtack*)> click) = 0;

		virtual void setSize(float width, float height) = 0;

		virtual void changImage(const std::string& imhePath, Layer level) = 0;

		virtual void setLevelScale(float level0, float level1, float level2)=0;

		virtual void setLevelWidthAndHeight(float x1, float y1, float x2, float y2, float x3, float y3)=0;
	};
}

#endif