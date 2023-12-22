#include "pch.h"
#include "PlatinumApp.h"
#include "Utilities.h"
#include "include/Platinum.h"
#include "Shader.h"
#include "Picture.h"
#include "Renderer.h"
#include "Unit.h"

namespace pl
{
	template<typename T>
	PlatinumApp<T>::PlatinumApp()
	{
		mWindow.Create("Game GS", 1920, 1080);

		mRenderer.Init();

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler();  });
	}

	template<typename T>
	void PlatinumApp<T>::Init()
	{
		if (sInstance == nullptr) {
			sInstance = new T;
		}
	}

	template<typename T>
	void PlatinumApp<T>::RunInterface()
	{
		sInstance->Run();
	}

	template<typename T>
	void PlatinumApp<T>::Run()
	{
		pl::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };

		mNextFrameTime = std::chrono::steady_clock::now();

		while (mShouldContinue)
		{
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());

			onUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void PlatinumApp<T>::onUpdate()
	{
	}

	template<typename T>
	void PlatinumApp<T>::Draw(int x, int y, Picture& pic)
	{
		sInstance->mRenderer.Draw(x, y, pic);
	}

	template<typename T>
	void PlatinumApp<T>::Draw(Unit& item)
	{
		sInstance->mRenderer.Draw(item.mXPosition, item.mYPosition, item.mImage);
	}


	template<typename T>
	void PlatinumApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mWindow.SetKeyPressedCallback(callbackFunc);
	}

	template<typename T>
	void PlatinumApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}

	template<typename T>
	void PlatinumApp<T>::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		mWindow.SetWindowCloseCallback(callbackFunc);
	}

	template<typename T>
	void PlatinumApp<T>::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}

}
