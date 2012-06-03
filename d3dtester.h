// d3d memory testing stuff

#ifndef __INCLUDE_D3DTESTER_
#define __INCLUDE_D3DTESTER_

namespace D3DTester
{
	void	initD3D( HWND hWnd );
	void	destroyD3D();

	void createTempD3DTexture();

	void clearAllTempResources();
}

#endif // __INCLUDE_D3DTESTER_