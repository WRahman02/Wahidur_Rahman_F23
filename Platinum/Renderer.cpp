#include"pch.h"
#include"Renderer.h"
#include"GLFWCode/OpenGLRenderer.h"

pl::Renderer::Renderer()
{
#ifdef PLATINUM_MSCPP
    mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif PLATINUM_APPLE
    mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif PLATINUM_LINUX
    mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
}

void pl::Renderer::Init()
{
    mImplementation->Init();
}

void pl::Renderer::Draw(int x, int y, Picture& pic)
{
    mImplementation->Draw(x, y, pic);
}

void pl::Renderer::Clear()
{
    mImplementation->Clear();
}