#include<iostream>

#include "util_render.h"
#include "util_pipeline.h"
 

int main(int argc, char* argv[]) 
{
	using namespace std ;
	cout << "啟動攝影機" << endl ;
	UtilPipeline pp;
	pp.EnableImage(PXCImage::COLOR_FORMAT_RGB32);
	pp.EnableImage(PXCImage::COLOR_FORMAT_DEPTH);
	pp.Init();

	cout << "設定GUI" << endl ;
	UtilRender color_render(L"彩色影像");
	UtilRender depth_render(L"深度影像");

	cout << "開始接收影像" << endl ;
	while(true)
	{
		if (!pp.AcquireFrame(true)) 
			break;

		PXCImage *color_image=pp.QueryImage(PXCImage::IMAGE_TYPE_COLOR);
		PXCImage *depth_image=pp.QueryImage(PXCImage::IMAGE_TYPE_DEPTH);

		if (!color_render.RenderFrame(color_image)) 
			break;
		if (!depth_render.RenderFrame(depth_image)) 
			break;
		pp.ReleaseFrame();
	}
	pp.Close();
	cout << "關閉攝影機" << endl ;

	return 0;
}

