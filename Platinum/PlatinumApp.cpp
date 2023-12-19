#include "pch.h"
#include "PlatinumApp.h"
#include "Utilities.h"
//#include "../glad/include/glad/glad.h"
//#include "../glfw/include/GLFW/glfw3.h"
//#include "../stbi/stb_image.h"
#include "include/Platinum.h"
#include "Shader.h"
#include "Picture.h"
#include "Renderer.h"

namespace pl
{
	template <typename T>
	PlatinumApp<T>::PlatinumApp()
	{
		mWindow.Create("Game WA", 1000, 800);
		mRenderer.Init();
	}
	template <typename T>
	void PlatinumApp<T>::Init()
	{
		if (sInstance == nullptr)
			sInstance = new T;
	}
	template <typename T>
	void PlatinumApp<T>::RunInterface()
	{
		sInstance->Run();
	}
	template <typename T>
	void pl::PlatinumApp<T>::Run()
	{
		
		////////////////////// Shader //////////////

		pl::Shader shader( "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" );
		///////////////////// Texture //////////////
		while (mShouldContinue)
		{
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());

			onUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}
	template <typename T>
	void PlatinumApp<T>::onUpdate()
	{

	}

	template <typename T>
	void PlatinumApp<T>::Draw(int x, int y, Picture& pic)
	{
		sInstance->mRenderer.Draw(x, y, pic);
	}
	template<typename T>
	void PlatinumApp<T>::Draw(Unit& thing)
	{
		sInstance->mRenderer.Draw(thing.mXPosition, thing.mYPosition, thing.mImage);
	}
}