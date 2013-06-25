#include<iostream>

#include "util_render.h"
#include "util_pipeline.h"
 

int main(int argc, char* argv[]) 
{
	using namespace std ;
	cout << "�Ұ���v��" << endl ;
	UtilPipeline pp;
	pp.EnableImage(PXCImage::COLOR_FORMAT_RGB32);
	pp.EnableImage(PXCImage::COLOR_FORMAT_DEPTH);
	pp.Init();

	cout << "�]�wGUI" << endl ;
	UtilRender color_render(L"�m��v��");
	UtilRender depth_render(L"�`�׼v��");

	cout << "�}�l�����v��" << endl ;
	for (;;) 
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
	cout << "������v��" << endl ;

	return 0;
}