#pragma once

#include "Utilities.h"

namespace pl
{
	template <typename T>
	class PLATINUM_API PlatinumApp
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
		bool mShouldContinue{ true };
	};
};

#include "PlatinumApp.cpp"