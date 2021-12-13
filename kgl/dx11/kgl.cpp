#include <map>

#include "kgl/kgl.h"
#include "kgl/dx11/kglrendertarget.h"

static KGLDeviceDesc deviceDesc;
static KGLVideoSettings videoSettings;

static D3D11_QUERY_DATA_TIMESTAMP_DISJOINT DisjointData;
static ID3D11Query* qDisjoint;
static ID3D11InputLayout* currentLayout;
static ID3D11RenderTargetView* activeRenderTargetView;
static ID3D11DepthStencilView* activeDepthStencilView;
static ID3D11RasterizerState* cullStates[6];

static KGLRenderTarget screenDepthTarget;
static KGLRenderTarget screenRenderTarget;
static ID3D11BlendState* blendStates[4];

static ID3D11DeviceContext* immediateContext;
static ID3D11Device* device;
static IDXGISwapChain* swapChain;
static IFW1Factory* pFW1Factory;
static IDWriteFontCollection* acFontCollection;
static IDWriteFontCollectionLoader* pCollectionLoader;
static PPFX::IPfxContext_Dx11* g_pPfxContext;
static HWND DirectInput::hWnd;
static DirectInput* DirectInput::m_singleton;
static HINSTANCE DirectInput::hInstance;
static GLRenderer* ksgui::Graph::localGL;
static GLRenderer* guiGL;
static int geomCollideTestCount;
static int rayCollideTestCount;
static int broadTestCount;
static GLRenderer* susGL;
static GLRenderer* glTyreTester;

static ID3D11DepthStencilState* depthStates[4];

static std::map<int, ID3D11InputLayout*> inputLayouts;


static int kglInitFonts(IDWriteFactory* a);
static HRESULT initBlendStates();
static HRESULT initCullStates();

KGLVideoSettings videoSettings;


int kglInit(const KGLVideoSettings& vs)
{
    IDWriteFactory* v2;

    //*(__m128i*)& videoSettings.aaSamples = _mm_loadu_si128((const __m128i*)vs);
    //*(__m128i*)& videoSettings.vSync = _mm_loadu_si128((const __m128i*) & vs->vSync);
    //*(__m128i*)& videoSettings.hdrPostProcessing = _mm_loadu_si128((const __m128i*) & vs->hdrPostProcessing);

    //*(_QWORD*)&videoSettings.tripleBuffer = *(_QWORD*)&vs->tripleBuffer;

    if (initDX11())
        return -1;
    
    initBlendStates();
    initCullStates();
    kglInitFonts(v2);

    //*(__m128i*)& vs->aaSamples = _mm_loadu_si128((const __m128i*) & videoSettings);
    //*(__m128i*)& vs->vSync = _mm_loadu_si128((const __m128i*) & videoSettings.vSync);
    //*(__m128i*)& vs->hdrPostProcessing = _mm_loadu_si128((const __m128i*) & videoSettings.hdrPostProcessing);
    //*(_QWORD*)&vs->tripleBuffer = *(_QWORD*)&videoSettings.tripleBuffer;

    return 0;
}

int __cdecl initDX11()
{
    KGLRenderTarget* v0; // eax
    ID3D11RenderTargetView* v1; // ecx
    ID3D11Texture2D* pBackBuffer; // [esp+40h] [ebp-7Ch] BYREF
    ID3D11RenderTargetView* rtv; // [esp+44h] [ebp-78h] BYREF
    D3D11_DEPTH_STENCIL_DESC dsd; // [esp+48h] [ebp-74h] BYREF
    DXGI_SWAP_CHAIN_DESC sd; // [esp+7Ch] [ebp-40h] BYREF

    if (createDeviceAndSwapChain())
        return -1;
    createDepthBuffer();
    if (swapChain)
        swapChain->GetBuffer(swapChain, 0, &_GUID_6f15aaf2_d208_4e89_9ab4_489535d34f9c, (void**)&pBackBuffer);
    device->CreateRenderTargetView(device, pBackBuffer, 0, &rtv);
    v0 = (KGLRenderTarget*)operator new(0x20u);
    if (v0)
    {
        v1 = rtv;
        v0->rtTexture = 0;
        v0->shaderResourceView = 0;
        v0->renderTargetViewDepth = 0;
        v0->width = 0;
        v0->height = 0;
        v0->samples = -1;
        v0->renderTargetView = v1;
    }
    else
    {
        v0 = 0;
    }

    screenRenderTarget = v0;
    pBackBuffer->Release(pBackBuffer);
    activeRenderTargetView = screenRenderTarget->renderTargetView;
    activeDepthStencilView = screenDepthTarget->renderTargetViewDepth;
    memset(&dsd, 0, sizeof(dsd));
    dsd.DepthEnable = 1;
    dsd.DepthFunc = D3D11_COMPARISON_LESS;
    dsd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
    device->CreateDepthStencilState(device, &dsd, depthStates);
    memset(&dsd, 0, sizeof(dsd));
    dsd.DepthEnable = 1;
    dsd.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
    dsd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
    device->CreateDepthStencilState(device, &dsd, (ID3D11DepthStencilState**)&unk_18729FC);
    memset(&dsd, 0, sizeof(dsd));
    dsd.DepthEnable = 1;
    dsd.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
    dsd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
    if (device->CreateDepthStencilState(device, &dsd, (ID3D11DepthStencilState**)&unk_18729F4) < 0)
    {
        _printf("ERROR: FAILED TO CREATE depthStencilStateZWriteOFF\n");
        return -1;
    }
    memset(&dsd, 0, sizeof(dsd));
    dsd.DepthEnable = 0;
    dsd.DepthFunc = D3D11_COMPARISON_ALWAYS;
    dsd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
    device->CreateDepthStencilState(device, &dsd, (ID3D11DepthStencilState**)&unk_18729F8);
    if (videoSettings.isFullscreen && swapChain)
    {
        _printf("\n***** GOING FULLSCREEN ***\n");
        if (swapChain)
        {
            swapChain->GetDesc(swapChain, &sd);
            swapChain->ResizeTarget(swapChain, (const DXGI_MODE_DESC*)&sd);
            swapChain->SetFullscreenState(swapChain, 1, 0);
            kglResizeBuffers(sd.BufferDesc.Width, sd.BufferDesc.Height);
        }
    }
    printSwapChainDesc();
    return 0;
}