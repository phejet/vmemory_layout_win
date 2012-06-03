#include "stdafx.h"
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )
#include <vector>
#include "d3dtester.h"



namespace D3DTester
{
//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
LPDIRECT3D9             gD3D = NULL; // Used to create the D3DDevice
LPDIRECT3DDEVICE9       gd3dDevice = NULL; // Our rendering device


std::vector<LPDIRECT3DVERTEXBUFFER9>	gTempVBs;
std::vector<LPDIRECT3DTEXTURE9>			gTempTextures;

// A structure for our custom vertex type. We added texture coordinates
struct CUSTOMVERTEX
{
    D3DXVECTOR3 position; // The position
    D3DCOLOR color;    // The color
#ifndef SHOW_HOW_TO_USE_TCI
    FLOAT tu, tv;   // The texture coordinates
#endif
};


void initD3D( HWND hWnd )
{
    // Create the D3D object.
    if( NULL == ( gD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
        return;

    // Set up the structure used to create the D3DDevice. Since we are now
    // using more complex geometry, we will create a device with a zbuffer.
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp, sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

    // Create the D3DDevice
    if( FAILED( gD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &gd3dDevice ) ) )
    {
        return;
    }

    // Turn off culling
    gd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );

    // Turn off D3D lighting
    gd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );

    // Turn on the zbuffer
    gd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );

    return;
}

void destroyD3D()
{
    if( gd3dDevice != NULL )
        gd3dDevice->Release();

    if( gD3D != NULL )
        gD3D->Release();

	clearAllTempResources();
}

void createTempD3DTexture()
{
	LPDIRECT3DTEXTURE9     pTexture = NULL;
    // Use D3DX to create a texture from a file based image
    if( FAILED( D3DXCreateTextureFromFile( gd3dDevice, L"banana.bmp", &pTexture ) ) )
    {
        // If texture is not in current folder, try parent folder
        if( FAILED( D3DXCreateTextureFromFile( gd3dDevice, L"..\\banana.bmp", &pTexture ) ) )
        {
            MessageBox( NULL, L"Could not find banana.bmp", L"Textures.exe", MB_OK );
			return;
        }
    }

	gTempTextures.push_back(pTexture);
}

void clearAllTempResources()
{
	// clear VBs
	for (std::vector<LPDIRECT3DVERTEXBUFFER9>::iterator vbItr = gTempVBs.begin();
		vbItr != gTempVBs.end(); ++vbItr)
	{
		 (*vbItr)->Release();
	}
	gTempVBs.clear();
	// clear Textures
	for (std::vector<LPDIRECT3DTEXTURE9>::iterator texItr = gTempTextures.begin();
		texItr != gTempTextures.end(); ++texItr)
	{
		 (*texItr)->Release();
	}
	gTempTextures.clear();
}

}