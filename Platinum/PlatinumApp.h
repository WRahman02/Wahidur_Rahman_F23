#pragma once

#include "Utilities.h"
#include "GameWindow.h"
#include "Picture.h"
#include "Renderer.h"
#include "Unit.h"

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

		void Draw(int x, int y, Picture& pic);
		void Draw(Unit& thing);

		friend typename T;
	private:
		PlatinumApp();
		inline static PlatinumApp* sInstance{ nullptr };
		GameWindow mWindow;
		Renderer mRenderer;
		bool mShouldContinue{ true };
	};
};

#include "PlatinumApp.cpp"