#include "pch.h"
#include "PlatinumApp.h"

namespace pl
{
	template <typename T>
	PlatinumApp<T>::PlatinumApp()
	{
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
		mWindow.Create("Game_WA",1000, 800);
		while (mShouldContinue)
		{
			onUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}
	template <typename T>
	void PlatinumApp<T>::onUpdate()
	{

	}
}