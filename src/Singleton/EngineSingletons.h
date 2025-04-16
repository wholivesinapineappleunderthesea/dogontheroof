#pragma once

#include "Singleton.h"

#include "Graphics/GraphicsSystem.h"

namespace apostate
{
	struct InternalEngineSingletonsOrder
	{
		SingletonInstance<GraphicsSystem> m_graphicsSystem;
	};

	using EngineSingletons = SingletonHolder<InternalEngineSingletonsOrder>;
}; // namespace apostate