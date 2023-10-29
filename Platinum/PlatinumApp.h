#pragma once

#include "Utilities.h"
#include "GameWindow.h"

namespace pl
{
	template <typename T>
	class PlatinumApp
	{
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void onUpdate();

		friend typename T;
	private:
		PlatinumApp();
		inline static PlatinumApp* sInstance{ nullptr };
		GameWindow mWindow;
		bool mShouldContinue{ true };
	};
};

#include "PlatinumApp.cpp"