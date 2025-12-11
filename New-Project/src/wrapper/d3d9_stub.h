/* DirectX 9 Stub for Linux Compatibility */
#ifndef _D3D9_STUB_H_
#define _D3D9_STUB_H_

#ifdef _WIN32
    #include <d3d9.h>
#else
    // Dummy types untuk Linux
    typedef void* LPDIRECT3DDEVICE9;
    typedef void* IDirect3DTexture9;
    typedef void* IDirect3D9;
    #define D3DFMT_A8R8G8B8 0
    #define D3DPOOL_DEFAULT 0
    #define D3DUSAGE_DYNAMIC 0
    #define D3DUSAGE_WRITEONLY 0
#endif

#endif
